#include <iostream>
#include <string>
using namespace std;

// 给定两个01字符串a和b，以二进制的形式返回a和b的和

class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        string res;
        int indexa = a.size() - 1, indexb = b.size() - 1;
        while (indexa >= 0 || indexb >= 0) {
            int left = 0, right = 0;
            if (indexa >= 0) {
                left = a[indexa] - '0';
                indexa--;
            }
            if (indexb >= 0) {
                right = b[indexb] - '0';
                indexb--;
            }

            int sum = left + right + carry;
            res += sum % 2 + '0';
            carry = sum >> 1;
        }
        if (carry != 0) {
            res += carry %2 + '0';
            carry >>= 1;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution st;
    string a("11"), b("1");
    string res = st.addBinary(a, b);
    cout << res << endl;
    return 0;
}