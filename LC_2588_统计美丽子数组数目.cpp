//
// Created by ≤‹√œ¡˙ on 25-3-6.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long beautifulSubarrays(vector<int> &nums) {
        long long res = 0;
        int prexor = 0;
        unordered_map<int, int> umap;
        umap[0] = 1;
        for (const int &i: nums) {
            prexor ^= i;
            res += umap[prexor];
            ++umap[prexor];
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{4, 3, 1, 2, 4};
    cout << st.beautifulSubarrays(nums) << endl;
    return 0;
}
