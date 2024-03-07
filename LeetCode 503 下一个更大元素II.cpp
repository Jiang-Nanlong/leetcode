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
};

int main() {
	Solution st;
	vector<int> nums{ 1,2,1 };
	vector<int> res = st.nextGreaterElements(nums);
	for (int i : res)
		cout << i << "  ";
	return 0;
}