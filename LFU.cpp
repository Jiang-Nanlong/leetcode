//
// Created by cml on 25-4-11.
//
#include <iostream>
#include <unordered_map>
#include <map>
#include <list>
using namespace std;

class LFU {
public:
    LFU(int n): capacity_(n) {
    }

    int get(const int &key) {
        if (lfu_.find(key) == lfu_.end()) {
            return -1;
        }
        updateFrequency(key);
        return lfu_[key].first;
    }

    void put(const int &key, const int &value) {
        if (lfu_.find(key) != lfu_.end()) {
            lfu_[key].first = value;
            updateFrequency(key);
            return;
        } else {
            if (lfu_.size() >= capacity_) {
                auto it = freq_map_.begin();
                int key = it->second.front();
                lfu_.erase(key);
                if (it->second.empty()) {
                    freq_map_.erase(it);
                }
                it->second.pop_front();

                key_iterator_map_.erase(key);
            }
            lfu_[key] = make_pair(value, 1);
            freq_map_[1].push_back(key);
            key_iterator_map_[key] = --freq_map_[1].end();
        }
    }

    void remove(const int &key) {
        if (lfu_.find(key) == lfu_.end()) {
            return;
        }
        int freq = lfu_[key].second;
        auto it = key_iterator_map_[key];
        freq_map_[freq].erase(it);
        if (freq_map_[freq].empty()) {
            freq_map_.erase(freq);
        }
        lfu_.erase(key);
        key_iterator_map_.erase(key);
    }

private:
    int capacity_;
    unordered_map<int, pair<int, int> > lfu_;
    map<int, list<int> > freq_map_;
    unordered_map<int, list<int>::iterator> key_iterator_map_;

    void updateFrequency(const int &key) {
        int freq = lfu_[key].second;
        lfu_[key].second++;
        freq_map_[freq].erase(key_iterator_map_[key]);
        if (freq_map_[freq].empty()) {
            freq_map_.erase(freq);
        }
        freq_map_[freq + 1].push_back(key);
        key_iterator_map_[key] = --freq_map_[freq].end();
    }
};

int main() {
    return 0;
}
