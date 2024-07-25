#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 给定两个数组nums和changeIndices，长度分别为n和m，一开始nums中的下标都是未标记的，从第1秒到第m秒，每一秒都可以执行以下几种操作：
// 1. 选择nums中的一个下标，将nums[i]减1
// 2. 如果nums[changeIncies[i]]==0，就标记nums数组中的下标changeIncies[i]
// 3. 什么也不做

// 其实可以把nums[i]想象成某一门考试的复习天数，changeIncies[i]表示这一天可以考哪一门。考试的那天必须复习够这门课需要的复习天数。

// 不过这个题我是没想出用二分法来做

class Solution {
public:
	int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
		int n = nums.size(), m = changeIndices.size();
		if (n > m)
			return -1;

		vector<int> last(n);  // 用来统计每门课程最后的考试时间
		auto check = [&](int time) {   // check函数用来统计在给定的时间段内，能否完成所有的考试
			fill(last.begin(), last.end(), -1);  //开始把所有的考试时间都设为-1
			for (int i = 0; i < time; i++)
				last[changeIndices[i] - 1] = i;    // 统计区间内的每门课的最后考试时间

			if (find(last.begin(), last.end(), -1) != last.end())   // 如果遍历完整个区间，至少有一门课没有最后的考试时间，则在这段时间内不能完成所有的考试
				return false;

			int count = 0;
			for (int i = 0; i < time; i++) {    // 还是从头遍历这个区间
				int index = changeIndices[i] - 1;  
				if (i == last[index]) {  // 如果这一天是某一课的最后考试时间，则考试。并从之前的天数内减去这门课需要的复习时间。
					if (count < nums[index])
						return false;
					count -= nums[index];
				}
				else  // 如果今天不是任何一门课的最后考试时间，就把复习天数加一
					count++;
			}
			return true;
			};

		int left = n, right = m + 1;
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (check(mid))
				right = mid;
			else
				left = mid+1;
		}
		return right > m ? -1 : right;
	}
};

int main() {
	Solution st;
	vector<int> nums{ 2,2,0 }, changeIndices{ 2,2,2,2,3,2,2,1 };
	cout << st.earliestSecondToMarkIndices(nums, changeIndices) << endl;
	return 0;
}