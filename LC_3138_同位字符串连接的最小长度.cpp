#include <iostream>
#include <array>
using namespace std;

// 给定一个字符串，判断是不是由一系列的同位字符串组成，同位字符串就是字符个数相同，但排列不一定相同的字符串
// 返回同位字符串的最小长度。
// 如果一个字符串是由多个同位字符串组成，那么同位字符串的长度一定是整个字符串长度的因子，而字符串最长是100000，100000以内因子个数最多的数为83160，共128个因子，
// 所以可以直接枚举所有可能的同位字符串的长度，然后判断整个字符串是不是可以分割成多个同位字符串

class Solution {
public:
    int minAnagramLength(string s) {
        int n = s.size();
        auto check = [&](int len) {
            array<int, 26> num{};
            for (int j = 0; j < len; j++)
                num[s[j] - 'a']++;

            for (int j = len; j < n; j += len) {
                array<int, 26> num1{};
                for (int k = j; k < j + len; k++) {
                    num1[s[k] - 'a']++;
                }
                if (num1 != num)
                    return false;
            }
            return true;
            };
        for (int len = 1; len <= n / 2; len++) {
            if (n % len == 0 && check(len))
                return len;
        }
        return n;
    }
};


int main() {
    Solution st;
    string s("jjj");
    cout << st.minAnagramLength(s) << endl;
    return 0;
}