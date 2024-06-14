#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 给定一个正整数数组，数组中的所有数的位数相同，现在要统计两两之间相同数位上不同数字的数目和。
// 这个题的思路是每个数位分开统计。
// 假设当前所有的数字都是一位数，那么遍历到第i个元素时，第i个元素与之前的所有数字不相同的个数就等于i减去之前与第i个数相同的元素数，剩下的就是都不相同的数字了，
// 每一个与第i个数的组合都是不相同的。放到多位数中，也是一样的。

class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        long long res = 0;
        int n = to_string(nums[0]).size();  // 先就算有几位数
        vector<vector<int>> vec(n, vector<int>(10, 0));  // 为每一个数位都创建一个vector，统计每种数字出现的次数
        for (int i = 0; i < nums.size(); i++) {  // 第i个数字
            int num = nums[i];
            for (int j = 0; num; num /= 10, j++) {  // 第j个数位
                int x = num % 10;
                res += i - vec[j][x];   // i减去同一个数位中之前与第i位相同的数字的个数，就是不同数对的个数
                vec[j][x]++;
            }
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 13,23,12 };
    cout << st.sumDigitDifferences(nums) << endl;
    return 0;
}