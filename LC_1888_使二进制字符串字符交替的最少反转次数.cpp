#include <iostream>
#include <string>
using namespace std;

// 给定一个二进制字符串，可以执行以下两种操作：
// 1.删除字符串的第一个字符并把它添加到字符串末尾；
// 2.选择字符串中的任意一个字符将其反转，0->1 或者 1->0
// 返回使得字符串变成一个交替字符串的最少 操作2 的次数

// 这是一个滑动窗口题，其实一种暴力解法的优化版本。
// 操作1其实是说明这个字符串是一个循环字符串，所以我们只需要计算以字符串中的每一个字符为开头的字符串的最少操作2的次数，选出最小的那个就行。
// 但如果直接这么做的话，时间复杂度是O(n^2)，所以使用滑动窗口优化，这里的窗口长度其实就是字符串的长度，来实现时间复杂度为O(n)。


class Solution {
public:
    int minFlips(string s) {
        string str("01");
        int res = 0, cnt = 0, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] != str[i & 1])
                ++cnt;
        }
        res = min(cnt, n - cnt);  // 至此，先统计第一个字符串的最少操作2的次数

        // 然后开始滑动窗口，每次都相当于以s[i+1]为字符串的第一个元素
        for (int i = 0; i < n; ++i) {
            if (s[i] != str[i & 1])  // 移除s[i]
                --cnt;
            if (s[i] != str[(i + n) & 1])  // 加入s[i+n]，新加入的字符串是窗口最后一个，因为这是一个循环字符串，所以新加入的字符和刚移除的一样
                ++cnt;
            res = min({ res, cnt, n - cnt });
        }
        return res;
        // 注意，整个匹配的过程中，cnt对应的都是0101类型字符串的修改次数！！！
    }
};

int main() {
    Solution st;
    string s("111000");
    cout << st.minFlips(s) << endl;
    return 0;
}