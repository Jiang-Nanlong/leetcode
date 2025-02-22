//
// Created by 曹孟龙 on 25-2-22.
//
#include <cstdint>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // 这是我自己的写法，时间复杂度是O(n2)，而且遍历了两次
    int similarPairs(vector<string> &words) {
        int n = words.size();
        vector<unordered_set<char> > vec(n);
        for (int i = 0; i < n; i++) {
            for (char c: words[i]) {
                vec[i].insert(c);
            }
        }

        int res = 0;

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (vec[i] == vec[j]) {
                    ++res;
                }
            }
        }
        return res;
    }

    // 这里用的跟leetcode 1512 好数对的数目 一样的方法，但是这里是字符串，1512中可以用整数表示该整数，这里怎么表示呢？
    // 用32为int中的低26为表示每个字母是否出现过，然后用该int对应的数来表示这个字符串就行了
    int similarPairs1(vector<string> &words) {
        unordered_map<int, int> umap;

        int res = 0;
        for (const string &word: words) {
            uint32_t byte = 0;
            for (const char c: word) {
                byte |= 1 << (c - 'a');
            }
            res += umap[byte]++;
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<string> words{"aba", "aabb", "abcd", "bac", "aabc"};
    cout << st.similarPairs(words) << endl;
    cout << st.similarPairs1(words) << endl;
    return 0;
}
