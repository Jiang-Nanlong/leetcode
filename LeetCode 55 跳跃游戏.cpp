#include <iostream>
#include <vector>
using namespace std;

//数组中的每个元素表示当前位置能跳出的最大距离。
//我记得上次做这个题就没想出来时咋用贪心的，这次还是没想出来，看的代码随想录的视频才知道。
//感觉贪心的题好难想
//这个题不关心每一个节点怎么跳，只关心当前能跳到的最大范围，只要在最大范围内，就能找到路径跳过去。
//下一步跳也只是在当前的最大范围内跳跃，如果最大范围能覆盖终点，就说明可以跳到末尾

class Solution {
public:
	bool canJump(vector<int>& nums) {
		if (nums.size() == 1) return true;
		int cover = 0;
		for (int i = 0; i <= cover; i++) {
			cover = max(cover, i + nums[i]);
			if (cover >= nums.size() - 1) return true;
		}
		return false;
	}

	//第二次做，记得覆盖范围这个点，这个题还是挺好做的
	bool canJump1(vector<int>& nums) {
		if (nums.size() == 1) return true;
		int length = nums[0];
		for (int i = 1; i < nums.size() && i <= length; i++) {
			if (length >= nums.size() - 1) return true;
			length = max(length, i + nums[i]);
		}
		return false;
	}

};

void main() {
	Solution st;
	vector<int> nums{ 2,3,1,1,4 };
	cout << boolalpha << st.canJump(nums) << noboolalpha << endl;
}