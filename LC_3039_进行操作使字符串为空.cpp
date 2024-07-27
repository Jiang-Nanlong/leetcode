#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string lastNonEmptyString(string s) {
        int n = s.size();
        int num[26];
        memset(num, 0, sizeof(num));  // 记录每个字母出现的次数
        int last[26];
        memset(last, -1, sizeof(last));  // 记录每个字母最后的出现位置
        int moreappare = 0;  // 记录最大的出现次数

        for (int i = 0; i < n; i++) {
            num[s[i] - 'a']++;
            last[s[i] - 'a'] = i;
            moreappare = max(moreappare, num[s[i] - 'a']);
        }

        vector<pair<int, char>> vec;
        for (int i = 0; i < 26; i++) {
            if (num[i] == moreappare) {
                vec.emplace_back(last[i], 'a' + i);
            }
        }
        sort(vec.begin(), vec.end());
        string res;
        for (auto it = vec.begin(); it != vec.end(); it++)
            res += it->second;

        return res;
    }
};

int main() {
    Solution st;
    string s("aabcbbca");
    cout << st.lastNonEmptyString(s) << endl;
    return 0;
}