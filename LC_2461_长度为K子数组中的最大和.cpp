#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        long long sum = 0, res = 0;
        for (int i = 0; i < k; i++) {
            ++umap[nums[i]];
            sum += nums[i];
        }
        if (umap.size() == k)
            res = max(res, sum);

        for (int i = k; i < nums.size(); i++) {
            sum += nums[i];
            sum -= nums[i - k];
            ++umap[nums[i]];
            if (--umap[nums[i - k]] == 0)
                umap.erase(nums[i - k]);
            if (umap.size() == k)
                res = max(res, sum);
        }
        return res;
    }

    long long maximumSubarraySum1(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        long long sum = 0, res = 0;
        for (int i = 0; i < k - 1; i++) {
            ++umap[nums[i]];
            sum += nums[i];
        }

        for (int i = k - 1; i < nums.size(); i++) {
            sum += nums[i];
            ++umap[nums[i]];

            if (i >= k) {
                sum -= nums[i - k];
                if (--umap[nums[i - k]] == 0)
                    umap.erase(nums[i - k]);
            }
            if (umap.size() == k)
                res = max(res, sum);
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 1,5,4,2,9,9,9 };
    int k = 3;
    cout << st.maximumSubarraySum(nums, k) << endl;
    cout << st.maximumSubarraySum1(nums, k) << endl;
    return 0;
}