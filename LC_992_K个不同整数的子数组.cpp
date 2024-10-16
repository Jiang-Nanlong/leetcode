#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        unordered_map<int, int> umap1, umap2;
        int res = 0;
        for (int i1 = 0, i2 = 0, j = 0; j < nums.size(); j++) {
            umap1[nums[j]]++;
            umap2[nums[j]]++;
            while (umap1.size() > k) {
                if (--umap1[nums[i1]] == 0)
                    umap1.erase(nums[i1]);
                i1++;
            }

            while (umap2.size() >= k) {
                if (--umap2[nums[i2]] == 0)
                    umap2.erase(nums[i2]);
                i2++;
            }
            res += i2 - i1;
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 1,2,1,2,3 };
    int k = 2;
    cout << st.subarraysWithKDistinct(nums, k) << endl;
    return 0;
}