#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int res = 0;
        for (int num : nums) {
            res += getMaxRes(num);
        }
        return res;
    }

    int getMaxRes(int num) {
        int MaxNum = 0;
        int count = 0;
        while (num) {
            MaxNum = max(MaxNum, num % 10);
            num /= 10;
            count++;
        }

        int res = MaxNum;
        while (--count) {
            res = res * 10 + MaxNum;
        }

        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 10,21,31 };
    cout << st.sumOfEncryptedInt(nums) << endl;
    return 0;
}