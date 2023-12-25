#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] < target)
				left = mid + 1;
			else if (nums[mid] > target)
				right = mid - 1;
			else
				return searchHelper(nums, target, mid);
		}
		return vector<int>{-1, -1};
	}
private:
	vector<int> searchHelper(vector<int>& nums, int target, int i) {
		int left = i, right = i;
		for (; left >= 0 && nums[left] == target; left--);  //�ʼ��ʱ���������forѭ���������д���ˣ�д��nums[left] == target && left >= 0�ˣ�
		//���������ж��ǲ��ǵ���target�����leftС��0������ͻᱨ�����������ж��ǲ���>=�����ˣ����<0�Ͳ�������������� 
		for (; right <= nums.size() - 1 && nums[right] == target; right++);
		return vector<int>{++left, --right};
	}
};
int main() {
	Solution st;
	vector<int> nums = { 1 };
	int target = 1;
	vector<int> res = st.searchRange(nums, target);

	for (size_t i = 0; i < res.size(); i++)
		cout << res[i] << "  ";
	cout << endl;
	return 0;
}