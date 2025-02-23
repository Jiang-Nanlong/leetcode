//
// Created by cml on 25-2-23.
//
// 这个跳表和之前的不太一样，这次允许插入相同的值，插入函数不用改，都是把新元素插入到第一个该插入的位置。
// 主要是删除的地方，因为是从上层逐步遍历到下层，而且可能有多个相同的值，所以这里删除层数最高的那个结点，
// 并记录结点地址，根据这个地址找到每一层它前一个节点的地址，最后一次修改前一个节点在该层的next指针

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_LEVEL 10

struct Node {
private:
    int data;

public:
    Node **next;

    Node(int d, int level): data(d), next(nullptr) {
        next = new Node *[level + 1];
        memset(next, 0, sizeof(Node *) * (level + 1));
    }

    ~Node() {
        delete[] next;
    }

    void setData(int d) {
        data = d;
    }

    int getData() const {
        return data;
    }
};

class Skiplist {
private:
    Node *head;
    int skiplist_level;

    int getRandomlevel() {
        int level = 0;
        while ((rand() % 100) < 50 && level < MAX_LEVEL) {
            level++;
        }
        return level;
    }

public:
    Skiplist() {
        skiplist_level = 0;
        head = new Node(0, MAX_LEVEL + 1);
    }

    bool search(int target) {
        Node *cur = head;
        for (int i = skiplist_level; i >= 0; i--) {
            while (cur->next[i] && cur->next[i]->getData() < target) {
                cur = cur->next[i];
            }

            if (cur->next[i] && cur->next[i]->getData() == target) {
                return true;
            }
        }
        return false;
    }

    void add(int num) {
        Node **prev = new Node *[MAX_LEVEL + 1];
        memset(prev, 0, sizeof(Node *) * (MAX_LEVEL + 1));

        Node *cur = head;
        for (int i = skiplist_level; i >= 0; i--) {
            while (cur->next[i] && cur->next[i]->getData() < num) {
                cur = cur->next[i];
            }
            prev[i] = cur;
        }


        int level = getRandomlevel();
        if (level > skiplist_level) {
            int i = skiplist_level + 1;
            while (i <= level)
                prev[i++] = head;

            skiplist_level = level;
        }

        Node *newNode = new Node(num, level);
        for (int i = 0; i <= level; i++) {
            newNode->next[i] = prev[i]->next[i];
            prev[i]->next[i] = newNode;
        }
    }

    bool erase(int num) {
        if (!search(num))
            return false;

        Node **prev = new Node *[MAX_LEVEL + 1];
        memset(prev, 0, sizeof(Node *) * (MAX_LEVEL + 1));

        Node *cur = head;
        Node *need_to_delete = nullptr;
        for (int i = skiplist_level; i >= 0; i--) {
            while (cur->next[i] && (cur->next[i]->getData() < num || (
                                        cur->next[i]->getData() == num && need_to_delete && cur->next[i] !=
                                        need_to_delete))) {
                cur = cur->next[i];
            }
            prev[i] = cur;
            if (need_to_delete == nullptr && cur->next[i] && cur->next[i]->getData() == num) {
                need_to_delete = cur->next[i];
            }
        }

        cur = cur->next[0];
        for (int i = 0; i <= skiplist_level; i++) {
            if (prev[i]->next[i] && prev[i]->next[i]->getData() == num) {
                if (prev[i] == head && cur->next[i] == nullptr) {
                    head->next[i] = nullptr;
                    --skiplist_level;
                } else {
                    prev[i]->next[i] = cur->next[i];
                }
            } else
                break;
        }

        delete cur;
        return true;
    }

    void print() {
        for (int i = skiplist_level; i >= 0; i--) {
            Node *cur = head->next[i];
            while (cur) {
                cout << cur->getData() << " ";
                cur = cur->next[i];
            }
            cout << endl;
        }
    }
};


/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */

int main() {
    Skiplist s;
    s.add(8);
    s.add(8);
    s.add(8);
    s.print();
    cout << boolalpha << s.search(0) << endl;
    s.add(4);
    s.print();

    cout << s.erase(8) << endl;
    s.print();

    cout << "----" << endl;
    cout << s.erase(8) << endl;
    s.print();

    cout << s.search(1) << noboolalpha << endl;
    s.print();

    return 0;
}
