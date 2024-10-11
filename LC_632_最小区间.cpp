#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

// 给定k个非递减排列的整数数组，找出一个最小区间，使得每个数列中都至少有一个数包含其中。
// 最小序列的定义是：如果 b-a < d-c 或者在 b-a == d-c 时 a < c，则区间 [a,b] 比 [c,d] 小

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int, int>> vec; // 每个数列中每个数都按(序列号，值)的形式加入到vector中，然后排序
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                vec.push_back(make_pair(i, nums[i][j]));
            }
        }
        sort(vec.begin(), vec.end(), [&](pair<int, int>& a, pair<int, int>& b) {
            return a.second < b.second;
            });

        int left = 0, right = vec.back().second;  // 开始结果最大，包含整个nums中所有的值
        unordered_map<int, int> umap;
        for (int i = 0, j = 0; j < vec.size(); j++) {
            umap[vec[j].first]++;  // 统计当前窗口中的每个序列的值的出现次数
            while (umap.size() == nums.size()) {
                int x = right - left - (vec[j].second - vec[i].second);

                if (x > 0 || (x == 0 && vec[i].second < left)) {
                    left = vec[i].second;
                    right = vec[j].second;
                }
                if (--umap[vec[i].first] == 0)
                    umap.erase(vec[i].first);
                i++;
            }
        }
        return vector<int>{left, right};
    }
};

int main() {
	Solution st;
	vector<vector<int>> nums{
		{47,67,82,97},
		{-2,34,42,49,50,50,51},
		{-61,-45,-3,-1,2,10},
		{25,57,76,77,78},
		{-11,10,29,55,55,55,57,59,60,60,62,63} 
	};

	vector<int> res = st.smallestRange(nums);
	cout << res[0]<<","<<res[1] << endl;
	return 0;
}