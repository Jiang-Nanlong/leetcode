#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// 给定一个只含有Q,W,E,R四种字符的字符串，可以选择一个子串把其中的内容修改，使得最后字符串的修改结果为每种字符的数量相同，
// 也就是每种字符的个数都占整个字符串的1/4。返回实现这种字符串要替换的最短子串的长度。

// 还是滑动窗口题，不过感觉这个题的缩小窗口的条件比较难想
// 如果其实不用考虑子串内的内容应该怎么变，因为只要窗口外每种字符的数量不超过总数的1/4就行。
// 可以反着想，如果子串外的某种字符数量大于总数的1/4那么不管子串内怎么改变都不会变成一个我们要求的字符串。
// 所以只要子串之外的每种字符的数量都少于1/4，我们就可以尝试着缩短子串。

class Solution {
public:
    int balancedString(string s) {
        int n = s.size() / 4;
        unordered_map<char, int> uamp;
        for (char c : s)
            uamp[c]++;
        if (uamp['Q'] == n && uamp['W'] == n && uamp['E'] == n &&
            uamp['R'] == n)
            return 0;

        int minlen = INT_MAX;
        for (int i = 0, j = 0; j < s.size(); j++) {
            uamp[s[j]]--;
            while (uamp['Q'] <= n && uamp['W'] <= n && uamp['E'] <= n &&
                uamp['R'] <= n) {
                minlen = min(minlen, j - i + 1);
                uamp[s[i++]]++;
            }
        }
        return minlen;
    }
};

int main() {
    Solution st;
    string s("WWEQERQWQWWRWWERQWEQ");
    cout << st.balancedString(s) << endl;
    return 0;
}