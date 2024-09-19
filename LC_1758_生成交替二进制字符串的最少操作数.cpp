#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int count1 = 0, count2 = 0;
        for (int i = 0; i < s.size(); i++) {
            if ((s[i] - '0') % 2 != i % 2)
                count1++;
            else
                count2++;
        }
        return min(count1, count2);
    }

    // 下边这种写法更简洁
    int minOperations1(string s) {
        string str = "01";
        int cnt = 0, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] != str[i & 1])
                ++cnt;
        }
        return min(cnt, n - cnt);
    }
};

int main() {
    Solution st;
    string s("1111");
    cout << st.minOperations(s) << endl;
    cout << st.minOperations1(s) << endl;
    return 0; 
}