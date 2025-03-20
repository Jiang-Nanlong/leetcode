//
// Created by ²ÜÃÏÁú on 25-3-20.
//
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        int n = nums.size();
        vector<int> s(n + 1);
        for (int i = 0; i < n; i++)
            s[i + 1] = s[i] + nums[i];

        int res = 0;
        unordered_map<int, int> cnt;
        for (int i: s) {
            auto it = cnt.find(i - k);
            res += it != cnt.end() ? cnt[i - k] : 0;
            cnt[i]++;
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{1, 2, 3};
    int k = 3;
    cout << st.subarraySum(nums, k) << endl;
    return 0;
}
