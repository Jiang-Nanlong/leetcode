#include <iostream>
#include <vector>
using namespace std;

//class Solution {
//public:
//	/*vector<int> sortedSquares(vector<int>& nums) {
//		for (size_t i = 0; i < nums.size(); i++)
//			nums[i] *= nums[i];
//		sort(nums.begin(), nums.end());
//		return nums;
//	}*/   //�ʼ�뵽�ľ�������㷨��ֱ����ƽ����Ȼ���������򣬵������Ч����̫��
//	vector<int> sortedSquares(vector<int>& nums) {   //Ȼ��������֪�����������������ǳ�����˫ָ��һ�ڣ��������벻����ô��˫ָ�룬��������Ժ�Ż�Ȼ���򣬵������ַ�����Ҫһ������Ŀռ�
//		int k = nums.size() - 1;
//		int i = 0, j = k;
//		vector<int> res(nums.size(), 0);
//		while (i <= j) {
//			if (nums[i] * nums[i] > nums[j] * nums[j]) {
//				res[k--] = nums[i] * nums[i];
//				i++;
//			}
//			else {
//				res[k--] = nums[j] * nums[j];
//				j--;
//			}
//		}
//		return res;
//	}
//};
//�����ǵ�һ������ʱ��д�Ĵ���

class Solution {
public:
	vector<int> sortedSquares(vector<int>& nums) {
		vector<int> res(nums.size());
		int index = nums.size() - 1;
		int i = 0, j = nums.size() - 1;
		while (i <= j) {
			if (abs(nums[i]) >= abs(nums[j])) {
				res[index--] = nums[i] * nums[i];
				i++;
			}
			else {
				res[index--] = nums[j] * nums[j];
				j--;
			}
		}
		return res;
	}

	vector<int> sortedSquares1(vector<int>& nums) {
		int n = nums.size();
		int i = 0, j = n - 1, k = n - 1;
		vector<int> res(n);
		while (i <= j) {
			if (abs(nums[i]) > abs(nums[j])) {
				res[k--] = nums[i] * nums[i];
				i++;
			}
			else {
				res[k--] = nums[j] * nums[j];
				j--;
			}
		}
		return res;
	}
};

int main() {
	Solution st;
	vector<int> nums{ -4,-1,0,3,10 };
	vector<int> res = st.sortedSquares(nums);
	for (int i : res)
		cout << i << "  ";
	cout << endl;

	vector<int> res1 = st.sortedSquares1(nums);
	for (int i : res1)
		cout << i << "  ";
	cout << endl;
	return 0;
}