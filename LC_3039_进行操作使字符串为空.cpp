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
        memset(num, 0, sizeof(num));  // ��¼ÿ����ĸ���ֵĴ���
        int last[26];
        memset(last, -1, sizeof(last));  // ��¼ÿ����ĸ���ĳ���λ��
        int moreappare = 0;  // ��¼���ĳ��ִ���

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