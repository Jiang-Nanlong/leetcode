#include <iostream>
using namespace std;

// 26个字母组成环，'z'后边是'a'。
// 给定一个字符串s，可以把字符串中的字符修改成任意字符，最后得到一个字典序列最小的字符串，且修改后的字符串与原字符串对应字符之间的距离之和为k
// 这是一个贪心算法的题，要想修改后的字典序列最小，那么字符串左边的字符要尽可能修改成'a'，所以先计算原字符与'a'之间的距离，如果距离小于等于k，那么就可以把这个字符修改成a，同时修改k
// 如果原字符与'a'之间的距离大于k了，那么说明在k个距离内，我们不能把原字符修改成'a'，只能把原字符缩小k个，因为要字典序尽可能小
// 距离小于k的时候，可以把a想象成26个字母的中间，往左看是z,y,x...，往右看是b,c,d...。不管是在哪一边缩小k个字符都不可能越过a到达z,y,x这一边

class Solution {
public:
    int distance(const char& a, const char& b) {  // 计算两个字符之间的距离
        return min(abs(a - b), 26 - abs(a - b));
    }

    string getSmallestString(string s, int k) {
        for (int i = 0; i < s.size() && k > 0; i++) {
            int diff = distance(s[i], 'a');
            if (diff <= k) {
                s[i] = 'a';
                k -= diff;
            }
            else {
                s[i] -= k;
                k = 0;
            }
        }
        return s;
    }
};

int main() {
    Solution st;
    string s("zbbz");
    int k = 3;
    cout << st.getSmallestString(s, k) << endl;
    return 0;
}