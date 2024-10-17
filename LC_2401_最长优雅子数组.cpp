#include <iostream>
#include <vector>
using namespace std;

// 给定一个由正整数组成的数组，如果子数组中不同位置的每对元素按位与的结果为0，则称该数组为优雅子数组
// 返回最长优雅子数组的长度。

// 这个问题的难点在于如何快速的计算出当前元素是不是与子数组中之前的元素按位与结果等于0，
// 其实可以设置一个变量_or，用来表示子数组内所有元素的在二进制的每一位是否为1，即把_or|=当前元素，就可以把当前元素的每一位加入到这个集合中
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int res = 0;
        for (int i = 0, j = 0, _or = 0; j < nums.size(); j++) {
            while (_or & nums[j])
                _or ^= nums[i++];
            _or |= nums[j];
            res = max(res, j - i + 1);
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 1,3,8,48,10 };
    cout << st.longestNiceSubarray(nums) << endl;
    return 0;
}