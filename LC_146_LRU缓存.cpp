//
// Created by ������ on 25-3-12.
//
#include <iostream>
#include <list>
#include <unordered_map>
#include <shared_mutex>
#include <mutex>

using namespace std;

class LRUCache {
    mutable shared_mutex mtx;
    list<pair<int, int> > cache_;
    unordered_map<int, list<pair<int, int> >::iterator> cacheMap;
    int capacity;

    void moveToFront(list<pair<int, int> >::iterator it) {
        cache_.splice(cache_.begin(), cache_, it);
    }

public:
    LRUCache(int cap) : capacity(cap) {
    }

    int get(int key) {
        shared_lock<shared_mutex> lock(mtx);
        auto it = cacheMap.find(key);
        if (it == cacheMap.end())
            return -1;
        moveToFront(it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        unique_lock<shared_mutex> lock(mtx);
        auto it = cacheMap.find(key);
        if (it != cacheMap.end()) {
            it->second->second = value;
            moveToFront(it->second);
            return;
        }

        if (cache_.size() == capacity) {
            auto itt = cache_.back();
            cacheMap.erase(itt.first);
            cache_.pop_back();
        }
        cache_.emplace_front(make_pair(key, value));
        cacheMap[key] = cache_.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    LRUCache lRUCache(2);
    lRUCache.put(1, 1); // ������ {1=1}
    lRUCache.put(2, 2); // ������ {1=1, 2=2}
    cout << lRUCache.get(1) << endl; // ���� 1
    lRUCache.put(3, 3); // �ò�����ʹ�ùؼ��� 2 ���ϣ������� {1=1, 3=3}
    cout << lRUCache.get(2) << endl; // ���� -1 (δ�ҵ�)
    lRUCache.put(4, 4); // �ò�����ʹ�ùؼ��� 1 ���ϣ������� {4=4, 3=3}
    cout << lRUCache.get(1) << endl; // ���� -1 (δ�ҵ�)
    cout << lRUCache.get(3) << endl; // ���� 3
    cout << lRUCache.get(4) << endl; // ���� 4

    return 0;
}
