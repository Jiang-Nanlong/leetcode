#include <iostream>
#include<string>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        long result = 0;
        int flag = 0;
        int temp = 0;
        for (char i : s)
        {
            if (flag == 0 && i == ' ')continue;
            else if (flag == 0 && i == '+')flag = 1;
            else if (flag == 0 && i == '-')flag = -1;
            else if (i >= '0' && i <= '9')
            {
                if (flag == 0)flag = 1;
                temp = i - '0';
                result = result * 10 + temp;
                if (result > INT_MAX)break;
            }
            else break;
        }
        if (flag == 1 && result > INT_MAX)result = INT_MAX;
        else if (flag == -1)
        {
            result = -result;
            if (result < INT_MIN)result = INT_MIN;
        }
        return result;
    }
    string s = "+-12";
};
int main() {
    Solution* a = new Solution();
    cout << a->myAtoi(a->s) << endl;
    return 0;
}
