#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> uset;
        for (int i : nums)
            if (uset.find(i) == uset.end())
                uset.insert(i);

        int count = uset.size(), n = nums.size();
        unordered_map<int, int> umap;
        int res = 0;
        for (int i = 0, j = 0; j < nums.size(); j++) {
            ++umap[nums[j]];
            while (umap.size() == count) {
                res += (n - j);
                if (--umap[nums[i]] == 0)
                    umap.erase(nums[i]);
                i++;
            }
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 1,3,1,2,2 };
    cout << st.countCompleteSubarrays(nums) << endl;
    return 0;
}