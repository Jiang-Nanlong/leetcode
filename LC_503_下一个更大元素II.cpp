#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//��������һ�������Ԫ�أ����������nums��һ��ѭ�����飬�����Ļ�ֻ��Ҫ��������������ܸ�������е���һ������Ԫ���ˡ�

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

	//�ڶ���������������ͻȻ����temp����Ҳֻ����ǰnλ����Ϊ����forѭ����һֱ��%n
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

	//�Ľ���
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