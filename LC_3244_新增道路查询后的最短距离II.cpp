#include <iostream>
#include <vector>
#include <set>
using namespace std;

// 给定n个节点，最初有从i到i+1的路径。该题中每条路径长度都为1。然后给定一个queries数组，数组中的每一个元素代表新添加的一条路径，
// 返回一个数组，数组中的每一位代表添加了一条新路径后，第0个节点到第n-1个节点的路径长度。
// 这个题中有一个重要的信息就是i!=j时，不存在queries[i][0] < queries[j][0] < queries[i][1] < queries[j][1]，
// 也就是说任意两条新添加的路径之间都是包含和被包含，或者是相邻的关系，不存在交叉关系。

// 原来这个题这么简单，周赛的时候光想着要用dijkstra算法了

class Solution {
public:
	vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
		set<pair<int, int>> st;
		for (int i = 0; i < n - 1; i++)   // 加入最初的路径
			st.insert({ i, i + 1 });

		vector<int> res;
		for (auto& v : queries) {
			int l = v[0], r = v[1];

			// 这么写有的测试用例会超时，用lower_bound就不会
			/*auto it = st.begin();
			while (it!=st.end() && *it < pair<int, int>(l, -1))
				it++;*/
			
			// 找出第一个起点大于等于新添加路径的路径，然后再判断这条新找到的路径是不是被新添加的路径给包含
			auto it = st.lower_bound(pair<int, int>(l, -1));
			if (it != st.end() && it->first >= l && it->second <= r) {  // 如果找出来的路径确实是被新路径包含了，就删除原来的路径，用新路径代替
				while (it != st.end() && it->first >= l && it->second <= r) {
					it = st.erase(it);
				}
				st.insert({ l, r });
			}
			res.push_back(st.size());
		}
		return res;
	}
};

int main() {
	Solution st;
	int n = 6;
	vector<vector<int>> queries{ {1,5},{3,5} };
	vector<int> res = st.shortestDistanceAfterQueries(n, queries);
	for (int i : res)
		cout << i << " ";
	cout << endl;
	return 0;
}