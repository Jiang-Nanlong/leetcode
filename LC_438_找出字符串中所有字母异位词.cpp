#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

// 找出字符串s中所有字符串p的异位词的子串，并记录这些异位词子串的起始位置

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (p.size() > s.size())
            return {};

        int count[26] = { 0 };
        vector<int> res;
        for (char c : p)
            ++count[c - 'a'];

        for (int i = 0; i < p.size() - 1; ++i)
            --count[s[i] - 'a'];

        for (int i = p.size() - 1; i < s.size(); ++i) {
            --count[s[i] - 'a'];
            if (isMatch(count))
                res.push_back(i - p.size() + 1);
            ++count[s[i - p.size() + 1] - 'a'];
        }
        return res;
    }
    // 感觉上边这种定长滑动窗口的时间复杂度更高，对于每个s中的元素都要判断一遍计数数组是不是一致。
  // 还是用不定长滑动窗口更好
    vector<int> findAnagrams1(string s, string p) {
        int count[26];
        memset(count, 0, sizeof(count));
        for (char c : p)
            ++count[c - 'a'];

        vector<int> res;
        int n = s.size();
        for (int i = 0, j = 0; j < n; j++) {
            char c = s[j];
            --count[c - 'a'];
            while (count[c - 'a'] < 0) {
                ++count[s[i++] - 'a'];
            }

            // 这个地方，为什么j-i+1==p.size()的时候就说明是找到了异位词了呢？注意缩小窗口的条件，只有当窗口中某个词的出现次数大于p中的出现次数就缩小窗口，
            // 那么窗口中的每个词的出现次数都小于等于p中出现的次数，而所有的字母个数又都相同，那么只能是异位词了。
            if (j - i + 1 == p.size())
                res.push_back(i);
        }
        return res;
    }

private:
    bool isMatch(int* p) {
        for (int i = 0; i < 26; i++)
            if (p[i] != 0)
                return false;

        return true;
    }
};

int main() {
    Solution st;
    string s("cbaebabacd"), p("abc");
    vector<int> res = st.findAnagrams(s, p);
    for (int i : res)
        cout << i << " ";
    cout << endl;
    return 0;
}