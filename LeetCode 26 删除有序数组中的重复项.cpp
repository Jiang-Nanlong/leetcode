#include <iostream>
#include <vector>
using namespace std;

//int removeDuplicates(vector<int>& nums) {
//	/*int slow = 0, fast = 0;
//	for (; fast < nums.size(); fast++) {
//		if (nums[slow] != nums[fast]) {
//			nums[slow] = nums[fast];
//			slow++;
//		}
//	}
//	return slow;*/      //һ��ʼ�뵽�ľ��������ֻ�뵽����˫ָ�룬���ǻ���Ū����������ôд
//
//	/*
//	if(nums.size()==0) return 0;        //���������������������У��о����±�������ã�����Ҫһ���Ķ�vector
//	if(nums.size()==1) return 1;
//
//	int slow = 1,fast = 1;
//	for(;fast<nums.size();fast ++){
//		if(nums[fast]==nums[fast-1])
//			continue;
//		else{
//			nums[slow++] = nums[fast];
//		}
//	}
//	return slow;
//	*/
//	if (nums.size() == 0) return 0;
//	if (nums.size() == 1) return 1;
//
//	int last = nums[0], count = 1;
//	for (int fast = 1; fast < nums.size(); fast++) {
//		if (last != nums[fast]) {
//			last = nums[fast];
//			nums[count++] = nums[fast];
//		}
//	}
//	return count;
//}
//�����ǵ�һ������ʱ��д��


//�ڶ�����
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int i = 1, j = 1;
		for (; i < nums.size(); i++) {
			if (nums[i] != nums[i - 1]) {
				nums[j] = nums[i];
				j++;
			}
		}
		return j;
	}
};

int main() {
	Solution st;
	vector<int> nums{ 0,0,1,1,1,2,2,3,3,4 };
	cout << st.removeDuplicates(nums) << endl;
	return 0;
}