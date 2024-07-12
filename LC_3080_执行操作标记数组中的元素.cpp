#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
using namespace std;

// 这个题做了两天才做出来，太麻烦了
// 给定一个nums数组，和一个queriies数组，queriies数组中的每一个元素是vector<int> 类型，vector[0]表示标记第几个元素，vector[0]是标记几个当前数组中还没标记的最小的元素。
// 返回每一次标记完，剩下的没有标记的元素的和。
// 开始两次做都把整个数组给排序了，然后要标记的元素的下标就混乱了，后来发现直接排序，要把元素和坐标组成的pair进行排序，这样既可以选出最小元素，又可以知道它的下标。

class Solution {
public:

	/*vector<long long> unmarkedSumArray(vector<int>& nums,
		vector<vector<int>>& queries) {
		vector<int> temp;
		for (int i = 0, j = 0; i < nums.size(); i++) {
			if (j < queries.size() && i == queries[j][0]) {
				j++;
			}
			else {
				temp.push_back(nums[i]);
			}
		}
		sort(temp.begin(), temp.end());
		long long sum = accumulate(nums.begin(), nums.end(), 0);
		vector<long long> res;
		for (int i = 0, j = 0; i < queries.size(); i++) {
			vector<int> query = queries[i];
			int index = query[0];
			int len = query[1];

			sum -= nums[index];
			while (len-- && j<temp.size()) {
				sum -= temp[j];
				j++;
			}
			res.push_back(sum);
		}
		return res;
	}*/


	/*vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
		vector<int> temp(nums.begin(), nums.end());
		sort(temp.begin(), temp.end());
		int n = nums.size();
		unordered_map<int, int> umap;
		for (int i = 0; i < n; i++) {
			if (umap.find(temp[i]) == umap.end())
				umap[temp[i]] = i;
		}
		vector<int> visited(n, false);
		vector<long long> res;
		int i = 0;
		long long sum = accumulate(temp.begin(), temp.end(), 0);

		for (vector<int>& query : queries) {
			int num = nums[query[0]];
			int count = query[1];

			int index = umap[num];
			while (temp[index] == num && visited[index]) {
				index++;
			}
			if (temp[index] == num) {
				visited[index] = true;
				sum -= num;
			}

			while (i < n && count) {
				if (visited[i] == false) {
					visited[i] = true;
					count--;
					sum -= temp[i];
				}
				i++;
			}
			res.push_back(sum);
		}
		return res;
	}*/


	vector<long long> unmarkedSumArray(vector<int>& nums,
		vector<vector<int>>& queries) {
		vector<pair<int, int>> temp;
		int n = nums.size();

		for (int i = 0; i < n; i++) {
			temp.push_back({ nums[i], i });
		}
		sort(temp.begin(), temp.end());

		vector<int> visited(n, false);
		vector<long long> res;
		int i = 0;  // 对应temp数组的引用，指向最小的还没标记的元素
		long long sum = accumulate(nums.begin(), nums.end(), 0LL);

		for (vector<int>& query : queries) {
			int index = query[0];
			int count = query[1];

			if (!visited[index]) {
				visited[index] = true;
				sum -= nums[index];
			}

			while (i < n && count) {
				pair<int, int> cur = temp[i];
				if (!visited[cur.second]) {
					visited[cur.second] = true;
					sum -= cur.first;
					count--;
				}
				i++;
			}

			res.push_back(sum);
		}
		return res;
	}

};

int main() {
	Solution st;
	vector<int> nums{ 1,2,2,1,2,3,1 };
	vector<vector<int>> queries{ {1,2},{3,3},{4,2} };
	vector<long long> res = st.unmarkedSumArray(nums, queries);
	for (int i : res)
		cout << i << "  ";
	cout << endl;
	return 0;
}