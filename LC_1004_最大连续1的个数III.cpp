#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int longestOnes(vector<int>& nums, int k) {
		int count_0 = 0;
		int res = 0;
		for (int i = 0, j = 0; j < nums.size(); j++) {
			if (nums[j] == 0)
				count_0++;
			while (count_0 > k) {
				if (nums[i++] == 0)
					count_0--;
			}
			res = max(res, j - i + 1);
		}
		return res;
	}
};

int main() {
	Solution st;
	vector<int> nums{ 1,1,1,0,0,0,1,1,1,1,0 };
	int k = 2;
	cout << st.longestOnes(nums, k) << endl;
	return 0;
}