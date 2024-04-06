#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int length = nums.size();
		int count = 0;

		for (int i = 0; i < length; i++) {
			if (nums[i] != val) {
				nums[count] = nums[i];
				count++;
			}
		}
		return count;
	}

	//ÏÂ±ßµÚ¶þ´Î×ö
	int removeElement1(vector<int>& nums, int val) {
		int i = 0, j = 0;
		for (; j < nums.size(); j++) {
			if (nums[j] != val) {
				nums[i] = nums[j];
				i++;
			}
		}
		return i;
	}
};

void main() {
	Solution st;
	vector<int> nums{ 3,2,2,3 };
	int val = 3;
	int count = st.removeElement(nums, val);
	cout << count << endl;
	vector<int> nums1{ 3,2,2,3 };
	cout << st.removeElement1(nums1, 3) << endl;
}
