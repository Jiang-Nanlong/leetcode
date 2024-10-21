#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int threeSumMulti(vector<int>& arr, int target) {
		sort(arr.begin(), arr.end());
		int res = 0;
		int MOD = 1e9 + 7;
		int n = arr.size();
		for (int i = 0; i < n - 2; i++) {
			if (arr[i] + arr[i + 1] + arr[i + 2] > target)
				return res;
			if (arr[i] + arr[n - 2] + arr[n - 1] < target)
				continue;
			int j = i + 1, k = n - 1;
			while (j < k) {
				int sum = arr[i] + arr[j] + arr[k];
				if (sum == target) {
					if (arr[j] == arr[k]) {
						long long temp = ((k - j + 1) % MOD * (k - j) % MOD) % MOD / 2;
						res = (res + temp) % MOD;
						break;
					}
					else {
						int count1 = 1, count2 = 1;
						while (arr[j] == arr[j + count1])
							count1++;
						while (arr[k] == arr[k - count2])
							count2++;
						res = (res + count1 * count2) % MOD;
						j += count1;
						k -= count2;
					}
				}
				else if (sum < target)
					j++;
				else
					k--;
			}
		}
		return res;
	}
};
int main() {
	Solution st;
	vector<int> nums{ 1,1,2,2,3,3,4,4,5,5 };
	int target = 8;
	cout << st.threeSumMulti(nums, target) << endl;
	return 0;
}