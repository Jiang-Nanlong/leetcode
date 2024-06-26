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
//	return slow;*/      //一开始想到的就是这个，只想到了用双指针，但是还是弄不清具体该怎么写
//
//	/*
//	if(nums.size()==0) return 0;        //接下来的这两个方法都行，感觉最下边这个更好，不需要一遍遍的读vector
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
//以上是第一次做的时候写的


//第二次做
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
