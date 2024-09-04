#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
	double findMaxAverage(vector<int>& nums, int k) {
		int sum = accumulate(nums.begin(), nums.begin() + k, 0);
		int res = sum;
		for (int i = 0, j = k; j < nums.size(); j++, i++) {
			sum += nums[j];
			sum -= nums[i];

			res = max(res, sum);
		}
		return 1.0 * res / k;
	}

};

int main() {
	Solution st;
	vector<int> nums{ 1,12,-5,-6,50,3 };
	int k = 4;
	cout << st.findMaxAverage(nums, k) << endl;

	return 0;
}