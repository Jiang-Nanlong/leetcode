#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//还是求下一个更大的元素，但是这里的nums是一个循环数组，这样的话只需要遍历两遍数组就能给求出所有的下一个更大元素了。

class Solution {
public:
	vector<int> nextGreaterElements(vector<int>& nums) {
		int n = nums.size();
		vector<int> res(n, -1);
		stack<int> stk;
		for (int i = 0; i < 2 * n; i++) {
			while (!stk.empty() && nums[i % n] > nums[stk.top() % n]) {
				res[stk.top() % n] = nums[i % n];
				stk.pop();
			}
			stk.push(i % n);
		}
		return res;
	}
};

int main() {
	Solution st;
	vector<int> nums{ 1,2,1 };
	vector<int> res = st.nextGreaterElements(nums);
	for (int i : res)
		cout << i << "  ";
	return 0;
}
