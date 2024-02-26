#include <iostream>
#include <vector>
using namespace std;

//多重背包就是每件物品有Mi个，每个消耗空间是Ci，价值是Wi。其实只要把多重背包内的物品展开就行，就和01背包一样了

class Solution {
public:
	void test_multi_pack() {
		vector<int> weight = { 1, 3, 4 };
		vector<int> value = { 15, 20, 30 };
		vector<int> nums = { 2, 3, 2 };

		int bagWeight = 10;
		for (int i = 0; i < nums.size(); i++) {
			while (nums[i] > 1) {      // nums[i]保留到1，把其他物品都展开
				weight.push_back(weight[i]);
				value.push_back(value[i]);
				nums[i]--;
			}
		}
		vector<int> dp(bagWeight + 1, 0);
		for (int i = 0; i < weight.size(); i++) {   // 遍历物品
			for (int j = bagWeight; j >= weight[i]; j--) {   // 遍历背包
				dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
			}
			for (int j = 0; j <= bagWeight; j++) {
				cout << dp[j] << " ";
			}
			cout << endl;
		}
		cout << dp[bagWeight] << endl;
	}
	/*
	0 15 15 15 15 15 15 15 15 15 15
	0 15 15 20 35 35 35 35 35 35 35
	0 15 15 20 35 45 45 50 65 65 65
	0 15 30 30 35 50 60 60 65 80 80
	0 15 30 30 35 50 60 60 70 80 80
	0 15 30 30 35 50 60 60 70 80 80
	0 15 30 30 35 50 60 60 70 80 90
	*/

	//我懂下边这种了，还是按01的先物品后背包，倒序的遍历方式，对于每个背包都遍历每个物品是数量，尽可能的多装当前物品
	void test_multi_pack1() {
		vector<int> weight = { 1, 3, 4 };
		vector<int> value = { 15, 20, 30 };
		vector<int> nums = { 2, 3, 2 };
		int bagWeight = 10;
		vector<int> dp(bagWeight + 1, 0);
		for (int i = 0; i < weight.size(); i++) {   // 遍历物品
			for (int j = bagWeight; j >= weight[i]; j--) {   // 遍历背包
				// 以上为01背包，然后加⼀个遍历个数

				for (int k = 1; k <= nums[i] && j >= k * weight[i]; k++) { // 遍历个数
					dp[j] = max(dp[j], dp[j - k * weight[i]] + k * value[i]);
				}
			}
			// 打印⼀下dp数组
			for (int j = 0; j <= bagWeight; j++) {
				cout << dp[j] << " ";
			}
			cout << endl;
		}
		cout << dp[bagWeight] << endl;
	}
	/*
	0 15 30 30 30 30 30 30 30 30 30
	0 15 30 30 35 50 50 55 70 70 75
	0 15 30 30 35 50 60 60 70 80 90
	*/
};

int main() {
	Solution st;
	st.test_multi_pack();
	st.test_multi_pack1();
	return 0;
}