#include <iostream>
#include <vector>
using namespace std;

//这个题我想到把gas和cost数组的对应位置相减，获得每个加油站油量的净收益。如果所有的净收益加一起小于0，说明不可能开一圈，
//但是从哪个位置开始，我还是只能想到用暴力的解法，从各个位置循环一遍，然后加上每个位置的净油量，如果能到达起始位置的前一个说明可以开一圈，否则不能。
//但是看了一下代码随想录的pdf上说了一个时间复杂度O(n)的方法，想了一阵子想不出。
//然后看了视频才知道，他的意思也是算每个位置的净油量，如果从0到某个点时，净油量和为负数，说明这个区间选择任何一个位置作为起点都会断油，
//然后就从当前节点的下一个位置重新开始计算。
//这里的局部最优是当某点处的净油量小于0时，起始位置至少是i+1，因为i之前开始的都不行。
//全局最优就是找到一个可以跑一圈的位置。
//但是这个题让我自己想，我肯定还是想不出，我想可能需要一些数学证明

class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int cursum = 0, totalsum = 0, start = 0;
		for (int i = 0; i < gas.size(); i++) {
			cursum += gas[i] - cost[i];
			totalsum += gas[i] - cost[i];
			if (cursum < 0) {
				start = i + 1;   //为什么这里不写成start=i，然后最后返回start+1。因为有可能0就是最后的起始位置，整个过程都不会涉及修改起点的事。
				cursum = 0;
			}
		}
		if (totalsum < 0) return -1;
		return start;
	}

	//第二次做，还是没有做出来，但是我已经有些理解这个思路了
	//就是说如果一个区间内的rest[i]的和是小于0的话，这个区间内的所有点都是不能作为起点的，因为任何一个点作为起点走到区间末端的时候，油量都会小于0，
	//所以起点只能在下一个区间内
	int canCompleteCircuit1(vector<int>& gas, vector<int>& cost) {
		int curSum = 0;
		int totalSum = 0;  //用于最后计算整个路程的净油量是否大于0
		int start = 0;
		for (int i = 0; i < gas.size(); i++) {
			curSum += gas[i] - cost[i];
			totalSum += gas[i] - cost[i];
			if (curSum < 0) {
				start = i + 1;
				curSum = 0;
			}
		}
		if (totalSum < 0) return -1;
		return start;
	}
};

int main() {
	Solution st;
	vector<int> gas{ 3,1,1 }, cost{ 1,2,2 };
	cout << st.canCompleteCircuit(gas, cost) << endl;
	return 0;
}