//
// Created by 曹孟龙 on 25-1-12.
//
#include <vector>
#include <bitset>
#include <iostream>
using namespace std;

// 给定一个数组，返回按位与结果大于0的最长组合的长度

// 按位与结果大于0，其实就是要求按位与以后的结果中有1。那么问题就转换为了按位与以后某个位置为1，那么只需要统计有多少个数字在该位置二进制位为1即可

class Solution {
public:
    int largestCombination(vector<int> &candidates) {
        int max_val = 0;
        for (int i: candidates)
            max_val = max(max_val, i);

        int n = bitset<32>(max_val).size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int num: candidates)
                count += num >> i & 1;
            res = max(res, count);
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> candidates{16, 17, 71, 62, 12, 24, 14};
    cout << st.largestCombination(candidates) << endl;
    return 0;
}
