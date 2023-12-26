/*
* 209 长度最小的子数组
* 给定一个含有n个正整数的数组和正整数target，在数组中找出连续的子数组满足这几个数的和大于等于target，返回子数组长度的最小值
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int minSubArrayLen(int target, vector<int>& nums) {
		int i = 0, sum = 0, count = 0, result = INT_MAX;  //i作为滑动窗口的开始位置，sum是窗口的总和，count是当前窗口内满足条件的数组的长度，result是最后的结果
		for (int j = 0; j < nums.size(); j++) {   //j是滑动窗口的结束位置
			sum += nums[j];
			while (sum >= target) {
				count = j - i + 1;
				result = result < count ? result : count;
				sum -= nums[i++];
			}
		}
		return result == INT_MAX ? 0 : result;
	}
};

//这个题是滑动窗口的题，因为好长时间没接触滑动窗口了，看到题之后隐约感觉应该用两个指针选出一个范围，但是接下来就没头绪了
//然后直接看了答案，才知道咋做

int main() {
	Solution st;
	vector<int> nums{ 2,3,1,2,4,3 };
	int res = st.minSubArrayLen(7, nums);
	cout << res << endl;
	return 0;
}