#include <iostream>
#include <string>
using namespace std;

// 给定一个字符串，仅包含a,b,c三种字符，返回a,b,c都至少出现一次的子字符串的数目，相同字符串算多次。

class Solution {
public:
    int numberOfSubstrings(string s) {
        int count[3];
        memset(count, 0, sizeof(count));
        int res = 0;
        for (int i = 0, j = 0; j < s.size(); j++) {
            // 相当于固定窗口右端点，移动左端点，直到条件不满足时，那么从左端点往左的所有字符加入到窗口中后
            // 都是满足条件的子字符串。
            count[s[j] - 'a']++;
            while (count[0] > 0 && count[1] > 0 && count[2] > 0)
                count[s[i++] - 'a']--;
            res += i;
        }
        return res;
    }
};

int main() {
    Solution st;
    string s("aaacb");
    cout << st.numberOfSubstrings(s) << endl;
    return 0;
}