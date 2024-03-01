#include <iostream>
#include <vector>
using namespace std;

//������LeetCode 300 ����������в�һ����������Ҫ��ĵ����������������ģ������ͺ����ˣ�ֻ��Ҫ��nums[i]��nums[i-1]���бȽϾ�����
//�پ��Ǻ�LeetCode 300һ�������Ľ����һ��������dp[nums.size()-1]�����ܳ�����dp������κεط�

class Solution {
public:
	int findLengthOfLCIS(vector<int>& nums) {
		vector<int> dp(nums.size(), 1);
		int res = 1;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] > nums[i - 1]) {
				dp[i] = dp[i - 1] + 1;
			}
			res = max(res, dp[i]);
		}
		return res;
	}

	//����⻹������̰������
	int findLengthOfLCTIS1(vector<int>& nums) {
		int res = 1, count = 1;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] > nums[i - 1])
				count++;
			else
				count = 1;
			if (count > res) res = count;
		}
		return res;
	}
};

int main() {
	Solution st;
	vector<int> nums{ 1,3,5,4,7 };
	cout << st.findLengthOfLCIS(nums) << endl;
	cout << st.findLengthOfLCTIS1(nums) << endl;
	return 0;
}