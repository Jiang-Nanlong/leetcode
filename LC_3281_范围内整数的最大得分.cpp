#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 给定一个长度为n整数数组start，和一个整数d，这代表了n个区间[start[i], start[i]+d]
// 得分的定义为所选整数两两之间的最小绝对差，需要在n个区间中选择n个整数，每个区间一个。
// 返回所选整数得分的最大值。

// 又是二分

// 得分是所选整数两两之间的最小绝对差，那么为了让这个绝对差尽可能的大，要让这n个整数之间分布尽可能的均匀。
// 所以这里枚举n个整数之间的最小绝对差。
// 怎么判断一个绝对差是否合适呢？ 题目要求是要在n个区间中，每个区间选一个数，如果第一个区间选了一个数x，而x在最小绝对差len上基础上下一个应该选的数应该是x+len，
// 如果x+len大于了第二个区间的最大值，那么就没法在第二个区间取第二个数了，那么这个最小绝对差len就是不合适的。

class Solution {
public:
	int maxPossibleScore(vector<int>& start, int d) {
		sort(start.begin(), start.end());

		auto check = [&](long long len) {
			long long x = start[0];
			for (int i = 1; i < start.size(); i++) {
				x = max(x + len, 1LL * start[i]);  // 因为len代表的是n个整数两两之间的最小绝对差，也就意味着在一组数中存在一组或几组整数，他们的绝对差大于len
				// 所以，如果第1个区间选择了x，在最小绝对差len的基础上，第二个区间应该选择x+len，但是x+len小于第二个区间的最小值，那么此时我们在第二个区间要取值的话
				// 只能选择第二个区间的左端点了。
				if (x > start[i] + d)
					return false;
			}
			return true;
		};

		long long left = 0, right = (start.back() + d - start[0]) / (start.size() - 1) + 1;
		while (left < right) {  // 不过这里的二分终止条件还是写不好，总是会陷入死循环
			long long mid = ((right + left + 1) >> 1);
			if (check(mid))
				left = mid;
			else
				right = mid - 1;
		}
		return left;
	}
};

int main() {
	Solution st;
	vector<int> start{ 6,0,3 };
	int d = 2;
	cout << st.maxPossibleScore(start, d) << endl;
	return 0;
}