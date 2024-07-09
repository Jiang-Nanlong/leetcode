#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

// ��ʼ���ô����ʵ�����ţ����Ǻ������ֲ��С��������˳��Ԫ��3��Ƶ��3������Ԫ��2Ƶ��2������Ԫ��1��Ƶ��1.���õ�������Ӧ����{3,3,3},��ʹ�ô��������{3,3,2}

class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        unordered_map<int, long long> umap;
        multiset<long long> mset;
        vector<long long> res;

        for (int i = 0; i < nums.size(); i++) {
            auto it = mset.find(umap[nums[i]]);
            if (it != mset.end())
                mset.erase(it);
            umap[nums[i]] += freq[i];
            mset.insert(umap[nums[i]]);
            if (mset.empty())
                res.push_back(0);
            else
                res.push_back(*mset.rbegin());
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 2,3,2,1 }, freq{ 3,2,-3,1 };
    vector<long long> res = st.mostFrequentIDs(nums, freq);
    for (auto i : res)
        cout << i << " ";
    cout << endl;
    return 0;
}