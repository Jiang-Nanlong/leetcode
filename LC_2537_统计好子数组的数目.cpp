#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 如果子数组中有超过k对相同的数对，那么就说这是一个好子数组，返回好子数组的数目

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        long long res = 0;
        int cnt = 0, n = nums.size();  // cnt用来统计数对的个数
        for (int i = 0, j = 0; j < n; j++) {
            ++umap[nums[j]];
            // 因为前边nums[j]的数量增加1，那么nums[j]的数对就要增加umap[nums[j]] - 1个，因为刚增加的nums[j]和之前的窗口内的nums[j]组成数对
            cnt += umap[nums[j]] - 1;
            while (cnt >= k) {
                --umap[nums[i]];
                cnt -= umap[nums[i++]];  // 同时减去相应的数对
            }
            res += i;
        }
        return res;
    }

    // 和上边一样，不过上边统计的是针对每个右端点，下边统计的是针对每个左端点
    long long countGood1(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        long long res = 0;
        int cnt = 0, n = nums.size();
        for (int i = 0, j = 0; j < n; j++) {
            ++umap[nums[j]];
            cnt += umap[nums[j]] - 1;
            while (cnt >= k) {
                res += (n - j);
                --umap[nums[i]];
                cnt -= umap[nums[i++]];
            }
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 3,1,4,3,2,2,4 };
    int k = 2;
    cout << st.countGood(nums, k) << endl;
    cout << st.countGood1(nums, k) << endl;
    return 0;
}