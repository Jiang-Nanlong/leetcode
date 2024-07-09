#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

// 开始想用大根堆实现来着，但是后来发现不行。比如插入顺序元素3，频率3；插入元素2频率2；插入元素1，频率1.最后得到的数组应该是{3,3,3},但使用大根堆则是{3,3,2}

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