#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;

//统计数组中每个数出现的次数，返回次数最高的前k个数

class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> mp;

		for (auto& i : nums)
			mp[i]++;

		vector<pair<int, int>> vec;
		for (auto& p : mp)
			vec.push_back(p);

		sort(vec.begin(), vec.end(), compare);
		vector<int> res;
		for (int i = 0; i < k; i++) {
			res.push_back(vec[i].first);
		}
		return res;
	}

	static bool compare(const pair<int, int>& a, const pair<int, int>& b) {
		return a.second > b.second;
	}

	//第二次做
	static bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
		return a.second > b.second;
	}
	vector<int> topKFrequent1(vector<int>& nums, int k) {
		unordered_map<int, int> umap;
		for (int& i : nums)
			umap[i]++;

		vector<pair<int, int>> vec(umap.begin(), umap.end());
		sort(vec.begin(), vec.end(), cmp);
		vector<int> res;
		for (int i = 0; i < k; i++) {
			res.push_back(vec[i].first);
		}
		return res;
	}

	//后来跟着答案写的小顶堆的写法。
	//这里用小顶堆的话只需要维护k个元素就行，如果用大顶堆的话就得维护所有元素。注意，而且小顶堆的cmp函数的写法跟之前的都不一样。
	class cmp1 {
	public:
		bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
			return a.second > b.second;
		}
	};

	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> umap;
		for (int& i : nums)
			umap[i]++;

		priority_queue<pair<int, int>, vector<pair<int, int>>, cmp1> priority_que;
		for (auto& p : umap) {
			priority_que.push(p);
			if (priority_que.size() > k)
				priority_que.pop();
		}
		vector<int> res(k);
		for (int i = k - 1; i >= 0; i--) {
			res[i] = priority_que.top().first;
			priority_que.pop();
		}
		return res;
	}
};

int main() {
	Solution st;
	vector<int> nums{ -5,-9,67,-10,4,-57,47,13,-67,-26,-57,63,38,-68,62,-45,-37,95,
		49,-91,-53,-42,-33,80,78,-30,-36,22,9,-86,79,-1,44,-92,30,-68,-94,58,-51,-26,
		-38,5,-74,25,71,-93,52,-12,-86,7,-86,53,78,-31,-5,-87,88,-98,-39,9,99,23,96,
		-90,51,-64,35,-73,9,60,-78,70,99,14,70,71,-78,50,7,46,-89,57,-1,87,-87,-95,
		48,49,79,-54,31,28,-27,75,31,-76,-12,35,40,-90,-60,-60,-7,67,73,-34,-42,-35
		,61,51,18,95,16,78,-81,-91,-30,92,57,-79,5,41,29,72,-62,-47,80,29,1,-21,-36
		,5,82,4,-12,-52,-56,-47,-68,95,85,-87,-7,-12,98,75,-64,-93,11,73,-81,-9,-12,
		-9,51,17,-94,33,-9,57,-35,10,-17,87,-18,-55,-52,30,-62,73,35,-74,-47,-63,77,
		-72,-55,5,73,21,14,7,-65,-51,-55,-49,98,-20,-22,-68,34,-20,92,55,47,-20,6,-54,
		-12,3,75,69,60,15,88,64,2,-27,-50,55,73,46,-15,-64,93,-47,-75,-55,-75,21,-57,
		91,-12,-99,-68,-56,-14,-4,-77,-94,55,93,-31,68,-12,-23,59,-56,-86,43,83,-93,
		-78,-11,-7,96,-3,-87,-37,19,-78,67,-29,77,-28,91,-73,-68,-22,18,-7,3,15,77,99,
		31,-48,-86,-45,-82,52,-39,8,-88,-83,-58,-77,5,87,-61,50,32,-66,-36,60,-53,52,
		70,-36,-1,83,-56,33,98,-80,28,1,-21,-50,-60,44,99,18,83,-29,83,-36,-55,-6,96,
		-60,61,75,6,-57,2,82,62,-27,36,60,72,92,61,-65,79,-57,-34,-23,-28,-55,53,36,
		-80,5,-76,64,-81,-32,-43,-1,50,-16,-72,-74,22,88,28,-79,-99,85,-13,-34,-76,85,
		6,21,-99,10,-46,79,11,-70,17,47,-22,-62,0,6,75,-19,57,-25,-52,-83,90,21,95,52,
		68,47,-12,76,-9,-65,86,90,16,74,64,26,84,64,-42,97,-72,53,-76,11,89,-62,67,100,
		15,53,68,-16,24,11,-77,20,59,-95,-50,-20,27,45,94,13,-93,86,49,12,19,17,-33,-52,
		-28,71,79,-19,-73,40,-99,83,77,19,-20,98,86,-5,-5,73,18,100,73,-45,33,3,89,32,
		-53,73,16,-3,-26,-80,49,-78,67,31,1,-85,-44,-91,-68,75,-74,95,23,89,99,-84,54,
		-93,68,0,-41,66,-15,-27,-23,-9,-68,37,45,-69,57,80,10,-64,35,26,55,-67,31,-76,
		36,-99,21 };

	int k = 7;
	vector<int> res = st.topKFrequent(nums, k);
	for (auto i : res)
		cout << i << " ";
	return 0;

}
