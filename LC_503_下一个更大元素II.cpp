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

	//第二次做，不过后来突然发现temp数组也只用了前n位，因为整个for循环中一直用%n
	vector<int> nextGreaterElements1(vector<int>& nums) {
		stack<int> stk;
		int n = nums.size();
		vector<int> temp(n * 2, -1);
		for (int i = 0; i < n * 2; i++) {
			while (!stk.empty() && nums[i % n] > nums[stk.top()]) {
				temp[stk.top()] = nums[i % n];
				stk.pop();
			}
			stk.push(i % n);
		}
		vector<int> res(nums.size(), -1);
		for (int i = 0; i < nums.size(); i++) {
			if (temp[i] != -1) {
				res[i] = temp[i];
			}
			else {
				res[i] = temp[i + nums.size()];
			}
		}
		return res;
	}

	//改进后
	vector<int> nextGreaterElements2(vector<int>& nums) {
		stack<int> stk;
		int n = nums.size();
		vector<int> temp(n, -1);
		for (int i = 0; i < n * 2; i++) {
			while (!stk.empty() && nums[i % n] > nums[stk.top()]) {
				temp[stk.top()] = nums[i % n];
				stk.pop();
			}
			stk.push(i % n);
		}
		return temp;
	}
};

int main() {
	Solution st;
	vector<int> nums{ 1,2,1 };
	vector<int> res = st.nextGreaterElements(nums);
	for (int i : res)
		cout << i << "  ";
	cout << endl;
	vector<int> res1 = st.nextGreaterElements1(nums);
	for (int i : res1)
		cout << i << "  ";
	cout << endl;
	vector<int> res2 = st.nextGreaterElements2(nums);
	for (int i : res2)
		cout << i << "  ";
	cout << endl;
	return 0;
}