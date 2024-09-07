#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// 给定一个字符串，如果一个子串满足子串中不同字母的数目小于等于maxLetters，子串长度位于[minSize, maxSize]之间，就称这是一个好串。
// 返回字符串中满足这种条件的且出现次数最大的子串的出现次数。

// 定长滑动窗口
// 这个问题的关键是，如果结果子串的长度大于minSize，那么这个子串切割成长度为minSize的子串后肯定也是满足“好串”的要求的，并且最后长度为minSize的子串的数目还可能大于长度为maxSize的子串的数目
// 所以只需要考虑长度为minSize的子串是否满足子串中不同字母的数目是否小于等于maxLetters即可。


class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int> s_umap;
        unordered_map<char, int> c_umap;
        int n = s.size();
        string str;
        int res = 0;
        for (int i = 0; i < minSize; i++) {
            ++c_umap[s[i]];
            str += s[i];
        }
        if (c_umap.size() <= maxLetters) {
            ++s_umap[str];
            res = 1;
        }
        for (int i = minSize; i < n; i++) {
            str += s[i];
            str.erase(0, 1);
            ++c_umap[s[i]];
            if (--c_umap[s[i - minSize]] == 0)
                c_umap.erase(s[i - minSize]);
            if (c_umap.size() <= maxLetters) {
                res = max(res, ++s_umap[str]);
            }
        }
        return res;
    }
};

int main() {
    Solution st;
    string s("aababcaab");
    int maxLetters = 2, minSize = 3, maxSize = 4;
    cout << st.maxFreq(s, maxLetters, minSize, maxSize) << endl;
    return 0;
}