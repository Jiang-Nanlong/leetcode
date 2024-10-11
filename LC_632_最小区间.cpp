#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

// ����k���ǵݼ����е��������飬�ҳ�һ����С���䣬ʹ��ÿ�������ж�������һ�����������С�
// ��С���еĶ����ǣ���� b-a < d-c ������ b-a == d-c ʱ a < c�������� [a,b] �� [c,d] С

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int, int>> vec; // ÿ��������ÿ��������(���кţ�ֵ)����ʽ���뵽vector�У�Ȼ������
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                vec.push_back(make_pair(i, nums[i][j]));
            }
        }
        sort(vec.begin(), vec.end(), [&](pair<int, int>& a, pair<int, int>& b) {
            return a.second < b.second;
            });

        int left = 0, right = vec.back().second;  // ��ʼ�����󣬰�������nums�����е�ֵ
        unordered_map<int, int> umap;
        for (int i = 0, j = 0; j < vec.size(); j++) {
            umap[vec[j].first]++;  // ͳ�Ƶ�ǰ�����е�ÿ�����е�ֵ�ĳ��ִ���
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