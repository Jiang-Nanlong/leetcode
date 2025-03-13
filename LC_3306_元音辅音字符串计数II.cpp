#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
using namespace std;

class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        unordered_map<char, int> umap1, umap2;
        long long res = 0;
        for (int i1 = 0, i2 = 0, j = 0; j < word.size(); j++) {
            char c = word[j];
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                umap1[c]++;
                umap2[c]++;
            }
            while (umap1.size() == 5 && (j - i1 + 1 - getCount(umap1) > k)) {
                c = word[i1];
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                    if (--umap1[c] == 0)
                        umap1.erase(c);
                }
                i1++;
            }

            while (umap2.size() == 5 && (j - i2 + 1 - getCount(umap2) >= k)) {
                c = word[i2];
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                    if (--umap2[c] == 0)
                        umap2.erase(c);
                }
                i2++;
            }
            res += i2 - i1;
        }
        return res;
    }

    // 三指针滑动窗口
    long long countOfSubstrings1(string word, int k) {
        unordered_set<char> uset{'a', 'e', 'i', 'o', 'u'};
        int array1[26], array2[26];
        memset(array1, 0, sizeof(array1));
        memset(array2, 0, sizeof(array2));
        int cnt_vowel1 = 0, cnt_vowel2 = 0;
        int cnt_consonant1 = 0, cnt_consonant2 = 0;
        int left1 = 0, left2 = 0;
        long long res = 0;
        for (char c : word) {
            if (uset.find(c) != uset.end()) {
                if (++array1[c - 'a'] == 1)
                    ++cnt_vowel1;
                if (++array2[c - 'a'] == 1)
                    ++cnt_vowel2;
            } else {
                ++cnt_consonant1;
                ++cnt_consonant2;
            }

            while (cnt_vowel1 == 5 && cnt_consonant1 >= k) {
                char cc = word[left1];
                if (uset.find(cc) != uset.end()) {
                    if (--array1[cc - 'a'] == 0)
                        --cnt_vowel1;
                } else
                    --cnt_consonant1;

                ++left1;
            }
            while (cnt_vowel2 == 5 && cnt_consonant2 > k) {
                char cc = word[left2];
                if (uset.find(cc) != uset.end()) {
                    if (--array2[cc - 'a'] == 0)
                        --cnt_vowel2;
                } else
                    --cnt_consonant2;

                ++left2;
            }
            res += left1 - left2;
        }
        return res;
    }

private:
    int getCount(const unordered_map<char, int>& umap) {
        int sum = 0;
        for (auto it = umap.begin(); it != umap.end(); it++)
            sum += it->second;
        return sum;
    }
};

int main() {
    Solution st;
    string word("ieaouqqieaouqq");
    int k = 1;
    cout << st.countOfSubstrings(word, k) << endl;
    return 0;
}