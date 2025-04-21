//
// Created by cml on 25-4-19.
//
#include <atomic>
#include <thread>
#include <iostream>
#include <vector>
#include <optional>


template <typename T>
class LockFreeQueue {
private:
    struct Node {
        T data;                     // 存储的数据
        std::atomic<Node*> next;    // 指向下一个节点的原子指针

        Node(T val) : data(std::move(val)), next(nullptr) {}
        Node() : next(nullptr) {}
    };

    std::atomic<Node*> head;
    std::atomic<Node*> tail;

public:
    // 构造函数
    LockFreeQueue() {
        // 创建一个哨兵（dummy）节点作为初始状态
        Node* sentinel = new Node();
        // 初始化时，头指针和尾指针都指向哨兵节点
        head.store(sentinel, std::memory_order_relaxed); // 初始存储，宽松即可
        tail.store(sentinel, std::memory_order_relaxed);
    }

    // 析构函数
    ~LockFreeQueue() {
        // 警告：这个析构函数不是线程安全的！
        // 如果其他线程仍在访问队列，调用它是不安全的。
        // 它也没有正确处理并发操作中可能仍然被引用的节点。
        // 这只是一个单线程环境下、所有操作结束后进行的基本清理。
        // 正确的无锁内存管理非常复杂。
        std::cout << "队列析构：开始清理剩余节点..." << std::endl;
        Node* current = head.load(std::memory_order_relaxed); // 读取头指针
        while (current != nullptr) {
            Node* nextNode = current->next.load(std::memory_order_relaxed); // 读取下一个节点指针
            std::cout << "删除节点地址: " << current << std::endl;
            delete current; // 删除当前节点
            current = nextNode; // 移动到下一个节点
        }
         std::cout << "队列析构：清理完成。" << std::endl;
    }

    // 禁用拷贝构造和赋值操作
    LockFreeQueue(const LockFreeQueue&) = delete;
    LockFreeQueue& operator=(const LockFreeQueue&) = delete;

    // 入队操作
    void enqueue(T value) {
        // 1. 创建一个包含新数据的新节点
        Node* newNode = new Node(std::move(value));
        Node* currentTail = nullptr;

        // 2. 无限循环，直到成功将新节点加入队列尾部
        for (;;) {
            // a. 读取当前的尾指针 (tail)
            currentTail = tail.load(std::memory_order_acquire);
            // b. 读取尾节点指向的下一个节点 (tail->next)
            Node* next = currentTail->next.load(std::memory_order_acquire);

            // c. 优化：再次检查尾指针是否未变。如果变了，说明其他线程修改了 tail，重试。
            if (currentTail != tail.load(std::memory_order_acquire)) {
                continue;
            }

            // d. 检查尾指针是否是真正的尾部
            if (next == nullptr) {
                // d.1. 尾指针似乎指向最后一个节点。尝试将新节点链接到其后。
                // 使用 compare_exchange_weak，因为它在循环中，允许伪失败（spurious failure），
                // 伪失败时我们也会重试循环，性能可能更好。
                if (currentTail->next.compare_exchange_weak(next, newNode, // 期望 next 是 nullptr，尝试更新为 newNode
                                                            std::memory_order_release, // 成功时：release 语义
                                                            std::memory_order_relaxed)) // 失败时：relaxed 即可
                {
                    // d.1.i. 成功链接了 newNode！现在尝试移动 tail 指针指向 newNode。
                    // 这是“帮助”性质的操作，即使失败，入队在逻辑上也已完成。
                    // 这里可以用 strong 或 weak，strong 避免伪失败可能简单些。
                    tail.compare_exchange_strong(currentTail, newNode,
                                                 std::memory_order_release,
                                                 std::memory_order_relaxed);
                    return; // 入队成功，退出函数
                }
            } else {
                // d.2. 尾指针落后了 (tail->next 不是 nullptr)。
                // 说明有其他线程已经添加了节点但还没来得及更新 tail。
                // 尝试“帮助”将 tail 指针向前移动到 next 指向的节点。
                 tail.compare_exchange_strong(currentTail, next,
                                              std::memory_order_release,
                                              std::memory_order_relaxed);
                // 无论帮助是否成功，都需要回到循环开始处重试整个入队逻辑。
            }
        }
    }

    // 出队操作
    // 返回 std::optional<T>，如果队列为空则返回 std::nullopt
    // 或者，可以像之前的例子一样返回 bool 并通过引用参数传值
    std::optional<T> dequeue() {
        Node* currentHead = nullptr;
        Node* currentTail = nullptr;
        Node* next = nullptr;

        // 1. 无限循环，直到成功出队或确认队列为空
        for (;;) {
            // a. 读取当前的头指针 (head)、尾指针 (tail) 和头节点的下一个节点 (head->next)
            currentHead = head.load(std::memory_order_acquire);
            currentTail = tail.load(std::memory_order_acquire);
            next = currentHead->next.load(std::memory_order_acquire);

            // b. 优化：再次检查头指针是否未变。如果变了，重试。
            if (currentHead != head.load(std::memory_order_acquire)) {
                continue;
            }

            // c. 检查队列状态
            if (currentHead == currentTail) {
                // c.1. 头尾指针相等，可能是空队列，或者尾指针落后
                if (next == nullptr) {
                    // c.1.i. head->next 为空，队列确实是空的
                    return std::nullopt; // 返回空 optional 表示队列为空
                }
                // c.1.ii. head->next 不为空，说明尾指针落后了。尝试帮助移动 tail。
                tail.compare_exchange_strong(currentTail, next,
                                             std::memory_order_release,
                                             std::memory_order_relaxed);
                // 帮助后，重试整个出队逻辑
            } else {
                // c.2. 队列非空 (head != tail)。尝试将 head 指向 next。
                // 在尝试 CAS 更新 head 之前，先读取数据。
                // 必须确保在 CAS 成功释放 currentHead 节点 *之前* 读取数据。
                // 由于哨兵节点的存在，如果 head != tail，那么 next 应该指向第一个有效数据节点。
                if (next == nullptr) {
                     // 理论上在有哨兵且 head != tail 时不应发生，除非有极端竞争或内存问题。
                     // 作为健壮性检查，如果发生则重试。
                     continue;
                }
                // 先读取数据 (注意：这里假设 T 的拷贝/移动构造是安全的)
                T value = next->data; // C++17: 可以用 std::move(next->data) 如果 T 支持移动

                // 尝试原子地将 head 从 currentHead 更新为 next
                if (head.compare_exchange_weak(currentHead, next,
                                                std::memory_order_release,
                                                std::memory_order_relaxed))
                {
                    // c.2.i. CAS 成功！头指针已移动，currentHead 指向的节点（旧的哨兵或上一个数据节点）逻辑上已出队。
                    // --- 危险区域 ---
                    // delete currentHead; // <<-- 在并发环境中，这是极其错误的！
                    // --- 危险区域 ---
                    // 旧的 `currentHead` 节点不能在这里安全地删除，因为其他线程可能还在访问它。
                    // 需要使用险象指针、基于纪元的回收等机制。
                    // 在这个简单示例中，我们只能“泄漏”这个节点。
                    // std::cout << "泄漏节点: " << currentHead << std::endl; // 用于演示

                    return value; // 返回包含出队值的 optional
                }
                // c.2.ii. CAS 失败，说明 head 被其他线程修改了（例如，另一个线程成功出队）。重试循环。
            }
        }
    }
};

// --- 示例用法 ---

LockFreeQueue<int> q; // 创建无锁队列实例
const int num_items_per_producer = 2500; // 每个生产者生产的物品数量
const int num_producers = 4; // 生产者线程数量
const int num_consumers = 4; // 消费者线程数量
const int total_items = num_items_per_producer * num_producers; // 总物品数量

std::atomic<int> produced_count(0); // 原子计数器，统计生产总数
std::atomic<int> consumed_count(0); // 原子计数器，统计消费总数
std::atomic<bool> producers_finished(false); // 原子标志，标记所有生产者是否完成

// 生产者任务
void producer_task(int id) {
    for (int i = 0; i < num_items_per_producer; ++i) {
        int value = id * num_items_per_producer + i; // 生成一个唯一值
        // std::cout << "生产者 " << id << " 正在入队 " << value << std::endl;
        q.enqueue(value); // 入队
        produced_count++; // 原子递增
    }
    // std::cout << "生产者 " << id << " 完成。" << std::endl;
}

// 消费者任务
void consumer_task(int id) {
    int count = 0; // 本线程消费计数
    // 持续消费，直到生产者完成且队列为空
    while (!producers_finished.load(std::memory_order_acquire)) { // 检查生产者是否完成
         std::optional<int> value_opt = q.dequeue(); // 尝试出队
         if (value_opt) { // 如果成功出队
            // std::cout << "消费者 " << id << " 出队 " << *value_opt << std::endl;
            consumed_count++; // 原子递增总消费计数
            count++;
         } else {
             // 出队失败，可能队列暂时为空，让出 CPU 时间片
             std::this_thread::yield();
             // 或者稍微等待一下，避免忙等消耗过多 CPU
             // std::this_thread::sleep_for(std::chrono::microseconds(10));
         }
    }

    // 生产者已经全部完成，最后再尝试清空队列剩余内容
    while (true) {
        std::optional<int> value_opt = q.dequeue();
        if (value_opt) {
            // std::cout << "消费者 " << id << " (最后阶段) 出队 " << *value_opt << std::endl;
            consumed_count++;
            count++;
        } else {
            // 队列确定为空了
            break;
        }
    }
    std::cout << "消费者 " << id << " 完成, 共消费 " << count << " 个物品。" << std::endl;
}


int main() {
    std::vector<std::thread> producers;
    std::vector<std::thread> consumers;

    std::cout << "开始测试: " << num_producers << " 个生产者, "
              << num_consumers << " 个消费者, 总共 " << total_items << " 个物品。" << std::endl;

    // 启动生产者线程
    for (int i = 0; i < num_producers; ++i) {
        producers.emplace_back(producer_task, i);
    }

    // 启动消费者线程
    for (int i = 0; i < num_consumers; ++i) {
        consumers.emplace_back(consumer_task, i);
    }

    // 等待所有生产者线程完成
    for (auto& t : producers) {
        t.join();
    }
    std::cout << "所有生产者已完成。" << std::endl;
    producers_finished.store(true, std::memory_order_release); // 设置标志，通知消费者

    // 等待所有消费者线程完成
    for (auto& t : consumers) {
        t.join();
    }
    std::cout << "所有消费者已完成。" << std::endl;


    std::cout << "测试结束。" << std::endl;
    std::cout << "总共生产物品数量: " << produced_count.load() << std::endl;
    std::cout << "总共消费物品数量: " << consumed_count.load() << std::endl;

    // 检查队列是否真的空了 (理论上应该为空)
    int remaining_count = 0;
    while(q.dequeue()) {
        remaining_count++;
    }
    if (remaining_count > 0) {
         std::cerr << "警告：测试结束后队列中仍有 " << remaining_count << " 个物品！" << std::endl;
    } else {
         std::cout << "测试结束后队列已空。" << std::endl;
    }

    // LockFreeQueue 'q' 在这里超出作用域，将调用其析构函数进行（不安全的）清理。

    return 0;
}