#include <iostream>
#include <vector>
using namespace std;

// 给定一个整数数组和一个非负整数k，k表示最多可以移除的元素的个数。
// 如果子数组中的元素都是一样的，那么就说这个子数组是一个等值子数组，空数组也是等值子数组。
// 返回最长的等值子数组的个数。

class Solution {
public:
    // 没做出来，看的代码随想录的思路
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> vec(n + 1);  //vec[i]表示所有值为i的元素的下标的集合
        for (int i = 0; i < n; i++)
            vec[nums[i]].push_back(i);

        int maxlen = 0;
        for (auto& v : vec) {
            // 对于一个vec[k]，其中的vec[k][i]和vec[k][j]表示子数组的左右端点，共有vec[k][j]-vec[k][i]+1个元素
            // i和j表示子数组中等值元素的左右端点，所以子数组中共有j-i+1个等值元素
            // 如果vec[k][j]-vec[k][i] - (j-i) > k的话就说明当前子数组窗口中有多余k个元素需要删除，所以此时要缩小窗口
            for (int i = 0, j = 0; j < v.size(); j++) {
                while (v[j] - v[i] - (j - i) > k) {
                    i++;
                }
                maxlen = max(maxlen, j - i + 1);
            }
        }
        return maxlen;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 1,3,2,3,1,3 };
    int k = 3;
    cout << st.longestEqualSubarray(nums, k) << endl;
    return 0;
}