#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        int maxlen = 0;
        for (int i = 0, j = 0; j < nums.size(); j++) {
            umap[nums[j]]++;
            while (umap[nums[j]] > k) {
                umap[nums[i++]]--;
            }
            maxlen = max(maxlen, j - i + 1);
        }
        return maxlen;
    }
};
int main() {
    Solution st;
    vector<int> nums{ 1,2,1,2,1,2,1,2 };
    int k = 1;
    cout << st.maxSubarrayLength(nums, k) << endl;
    return 0;
}