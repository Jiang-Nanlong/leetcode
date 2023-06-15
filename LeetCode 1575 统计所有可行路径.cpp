/*
给定一个互不相同的整数数组，数组中的第i位表示第i个城市的位置，同时给定start，finish和fuel最初的燃油，每一次经过城市都会消耗燃油，
两城市之间的燃油量就是数组中两个元素之间的差的绝对值，同一个城市可以经过多次，返回路径条数，但是路径数可能很大，最后结果对10^9+7取余
*/
#include <iostream>
#include <vector>
using namespace std;

//最开始我想的是声明一个dp数组，数组中的每一位代表着start到这一点消耗的燃油，如果还有燃油且不是终点，然后再从这一点出发继续上个过程，
//直到燃油为0或者到达终点，不过后来又感觉太复杂实现不了 嚓  这不就是dfs吗 嚓

//dfs的数据范围一般是30以内，超过了30以后就要搭配“记忆化搜索”来实现

class Solution {
public:
	int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
		int n = locations.size();
		vector<vector<int>> dp(n, vector<int>(fuel + 1, -1));  // *** dp[i][fuel]表示从i点开始，当前油量为fuel的情况下到达终点的路径数
		return dfs(locations, dp, start, finish, fuel);
	}

	int dfs(vector<int>& locations, vector<vector<int>>& dp, int start, int end, int fuel) {
		if (dp[start][fuel] != -1) {
			return dp[start][fuel];
		}
		
		//第一种情况，还没到达目的地，但是没油了
		if (start != end && fuel == 0) {
			dp[start][fuel] = 0;
			return 0;
		}

		//第二种情况，还没到达目的地，但是所剩余的油已经不够到达其他地点了
		int n = locations.size();
		bool canArrive = false;
		for (int i = 0; i < n; i++) {
			if (i != start) {
				if (fuel >= abs(locations[i] - locations[start])) {
					canArrive = true;
					break;
				}
			}
		}
		if (fuel != 0 && canArrive == false) {
			dp[start][fuel] = start == end ? 1 : 0;
			return dp[start][fuel];
		}

		//最后计算总的路径
		int sum = start == end ? 1 : 0;   //因为题目例子中存在一种情况，油量足够时，到达终点后还可以到其他点在从其他点再到终点也算一条路径
		for (int i = 0; i < n; i++) {
			if (i != start) {
				if (fuel >= abs(locations[i] - locations[start])) {
					sum += dfs(locations, dp, i, end, fuel - abs(locations[i] - locations[start]));
					sum %= 1000000007;   //这一句写在这里是因为有一种情况结果特别多，没法用int表示
				}
			}
		}
		dp[start][fuel] = sum;
		return sum;
	}
};

//这个题是dfs和记忆化搜索相结合的一个题，开始的时候我只想到了dfs，但是写不出代码，后来看了宫水三叶的代码才知道怎么写，但是还是不熟练
int main() {
	vector<int> location1 = { 2,3,6,8,4 };
	int start1 = 1, finish1 = 3, fuel1 = 5;
	vector<int> location2 = { 4,3,1 };
	int start2 = 1, finish2 = 0, fuel2 = 6;
	Solution s;
	cout << s.countRoutes(location1, start1, finish1, fuel1) << endl;
	cout << s.countRoutes(location2, start2, finish2, fuel2) << endl;
	return 0;
}
