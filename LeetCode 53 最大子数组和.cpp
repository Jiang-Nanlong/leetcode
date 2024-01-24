#include <iostream>
#include <vector>
using namespace std;

//给定一个数组，找出数组中具有最大和的连续子数组
//局部最优：当连续和为负数时，就从下一个数重新开始，因为负数只会拖累连续和
//局部最优退出全局最优，所以可以使用贪心
//还是不熟练，找不到问题的关键，一下子没想出来，还是看了题解才想出来。

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int result = INT_MIN;
		int count = 0;
		for (int i = 0; i < nums.size(); i++) {
			count += nums[i];
			if (count > result)  //这个地方应该先保存结果，然后再判断count是不是<=0，因为nums数组中可能全是负数，
				//如果这两个判断写反了，就会先置为0，然后再保存结果，然后就出错了
				result = count;

			if (count <= 0) {
				count = 0;
			}

		}
		return result;
	}
};

void main() {
	Solution st;
	vector<int> nums{ -2,1,-3,4,-1,2,1,-5,4 };
	cout << st.maxSubArray(nums) << endl;
}