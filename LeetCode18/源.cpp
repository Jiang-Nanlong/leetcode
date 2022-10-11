#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        /*vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>  res;
        long sum = 0;
        int length = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < length - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < length - 2; j++) {
                if (j > i+1 && nums[j] == nums[j - 1]) continue;
                int k = j + 1, l = length - 1;
                while (k < l) {
                    sum = (long)nums[k] + nums[i] + nums[j] + nums[l];
                    if (sum == target) {
                        res.push_back({ nums[i],nums[j] ,nums[k],nums[l] });
                        while (k < l && nums[k] == nums[++k]);
                        while (k < l && nums[l] == nums[--l]);
                    }
                    else if (sum > target) {
                        while (k < l && nums[l] == nums[--l]);
                    }
                    else if (sum < target) {
                        while (k < l && nums[k] == nums[++k]);
                    }
                }
            }
        }
        return res;
    }*/
        vector<vector<int>>  res;
        int length = nums.size();
        if (length < 4) return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < length - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            if ((long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
            if ((long)nums[i] + nums[length - 3] + nums[length - 2] + nums[length - 1] < target) continue;
            for (int j = i + 1; j < length - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                if ((long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
                if ((long)nums[i] + nums[j] + nums[length - 2] + nums[length - 1] < target) continue;
                int k = j + 1, l = length - 1;
                while (k < l) {
                    long sum = (long)nums[k] + nums[i] + nums[j] + nums[l];
                    if (sum == target) {
                        res.push_back({ nums[i],nums[j] ,nums[k],nums[l] });
                        while (k < l && nums[k] == nums[++k]);
                        while (k < l && nums[l] == nums[--l]);
                    }
                    else if (sum > target) {
                        while (k < l && nums[l] == nums[--l]);
                    }
                    else if (sum < target) {
                        while (k < l && nums[k] == nums[++k]);
                    }
                }
            }
        }
        return res;
    }
};