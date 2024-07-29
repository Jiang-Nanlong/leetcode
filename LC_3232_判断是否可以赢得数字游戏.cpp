#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
	bool canAliceWin(vector<int>& nums) {
		auto check = [&](int k) {
			int sum = 0;
			for (int i : nums) {
				if (getnum(i) == k)
					sum += i;
			}
			return sum;
			};
		int totalsum = accumulate(nums.begin(), nums.end(), 0);
		int sum1 = check(1);
		int sum2 = check(2);
		return sum1 > (totalsum - sum1) || sum2 > (totalsum - sum2);
	}

	bool canAliceWin1(vector<int>& nums) {
		auto check = [&](int k) {
			int sum = 0;
			for (int i : nums) {
				if (k == 1) {  // 统计1位数的和
					if (i < 10)
						sum += i;
				}
				else if (i > 9)  // 统计两位数的和
					sum += i;
			}
			return sum;
			};
		int totalsum = accumulate(nums.begin(), nums.end(), 0);
		int sum1 = check(1);
		int sum2 = check(2);
		return sum1 > (totalsum - sum1) || sum2 > (totalsum - sum2);
	}


private:
	int getnum(int i) {
		int res = 0;
		while (i) {
			res++;
			i /= 10;
		}
		return res;
	}
};

int main() {
	Solution st;
	vector<int> nums{ 1,2,3,4,5,14 };
	cout << boolalpha << st.canAliceWin(nums) << noboolalpha << endl;
	return 0;
}