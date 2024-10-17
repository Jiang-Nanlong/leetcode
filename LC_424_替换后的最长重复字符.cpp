#include <iostream>
#include <vector>
using namespace std;

// 给定一个字符串s和一个非负整数k，可以把字符串中的任意字符做任意修改，最多修改k次，返回包含同种字符的最长子串的长度

// 还是滑动窗口题，
// 统计窗口中相同字符的最多出现次数，如果整个子串的长度减去这个最多出现次数的结果大于k，说明此时要缩小窗口


class Solution {
public:
    int characterReplacement(string s, int k) {
        int count[26];
        memset(count, 0, sizeof(count));

        int res = 0;
        int mx = 0;
        for (int i = 0, j = 0; j < s.size(); j++) {
            mx = max(mx, ++count[s[j] - 'A']);
            while (j - i + 1 - mx > k) {
                mx = max(mx, --count[s[i++] - 'A']);
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};

int main() {
    Solution st;
    string s("KRSCDCSONAJNHLBMDQGIFCPEKPOHQIHLTDIQGEKLRLCQNBOHNDQGHJPNDQPERNFSSSRDEQLFPCCCARFMDLHADJADAGNNSBNCJQOF");
    int k = 4;
    cout << st.characterReplacement(s, k) << endl;
    return 0;
}