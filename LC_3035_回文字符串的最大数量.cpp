#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 给定一个字符串数组words，words[i]是一个字符串，交换字符串s1和s2之间的任意字符任意次（s1和s2可以是同一字符串），问最后words中最多有多少个回文串

// 其实这个题就相当于用words给定的所有字符来构造长度为words中每个字符串长度的回文串，问最后最多构造多少个回文串。
// 肯定是先构造长度最小的，因为消耗的字符数最少。
// 构造奇数长度的字符串，中间字符可以使用个数为奇数的字符，也可以使用个数为偶数的字符，但是使用个数为偶数的字符时，会使另一种字符个数变成奇数个。
// 构造偶数长度的字符串时，只能使用个数为偶数个的字符。

class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        int num[26];
        memset(num, 0, sizeof(num));
        int n = words.size();
        vector<int> wordLen(n);

        for (int i = 0; i < n; ++i) {  // 统计所有字符出现的次数，已经要构造的每个字符串的长度
            string word = words[i];
            wordLen[i] = word.size();
            for (char c : word)
                num[c - 'a']++;
        }

        int odd = 0, even = 0;  // 统计所有出现奇数次和偶数次字符出现的次数
        for (int i = 0; i < 26; ++i) {
            if (num[i] % 2 == 1) {  // 如果当前字符出现奇数次，那么它可以分为(num[i]-1)/2个成对出现的偶数和1个奇数
                even += num[i] - 1;
                odd += 1;
            }
            else if (num[i] > 0 && num[i] % 2 == 0) {  // 如果当前出现次数是偶数次，那么就可以分成num[i]/2个成对出现的偶数
                even += num[i];
            }
        }

        int res = 0;
        sort(wordLen.begin(), wordLen.end());  // 把要构造的字符串从小到大排序，先构造长度小的字符串

        for (int len : wordLen) {
            if (len % 2 == 1) {  // 如果当前要构造的字符串长度为奇数
                if (odd > 0 && even >= len - 1) {
                    odd -= 1;
                    even -= len - 1;
                    res++;
                }
                else if (odd == 0 && even >= len) {
                    even -= len + 1;
                    odd += 1;
                    res++;
                }
            }
            else {  // 如果当前要构造的字符串长度为偶数
                if (even >= len) {
                    even -= len;
                    res++;
                }
            }
        }

        return res;
    }
};

int main() {
    Solution st;
    vector<string> words{ "abbb","ba","aa" };
    cout << st.maxPalindromesAfterOperations(words) << endl;
    return 0;
}