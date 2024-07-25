#include <iostream>
#include <string>
using namespace std;

// 给定一个字符串，表示一个数字，删除字符串中的几个字符，剩下的字符组成的字符串可以被25整除。返回最小的删除次数。
// 字符串不包含前导0
// 能被25整除的数字都是以00,25,50,75结尾。所以倒序遍历字符串，如果找到了0，再找5或0.如果找到了5，就再找2或7

class Solution {
public:
    int minimumOperations(string num) {
        int n = num.size();
        bool find_0 = false, find_5 = false;
        for (int i = n - 1; i >= 0; i--) {
            char c = num[i];
            if (c == '0') {
                if (find_0)
                    return n - i - 2;
                else
                    find_0 = true;
            }
            if (c == '2' || c == '7')
                if (find_5)
                    return n - i - 2;

            if (c == '5') {
                if (find_0)
                    return n - i - 2;
                find_5 = true;
            }
        }
        return n - find_0;
    }
};

int main() {
    Solution st;
    string num("2245047");
    cout << st.minimumOperations(num) << endl;
    return 0;
}