//
// Created by ������ on 25-2-22.
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
    // �������Լ���д����ʱ�临�Ӷ���O(n2)�����ұ���������
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

    // �����õĸ�leetcode 1512 �����Ե���Ŀ һ���ķ����������������ַ�����1512�п�����������ʾ��������������ô��ʾ�أ�
    // ��32Ϊint�еĵ�26Ϊ��ʾÿ����ĸ�Ƿ���ֹ���Ȼ���ø�int��Ӧ��������ʾ����ַ���������
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
