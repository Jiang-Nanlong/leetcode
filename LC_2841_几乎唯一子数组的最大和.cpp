#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// ����һ�������������������m��k��һ������Ϊk����������������m��������ͬ��Ԫ�أ���������������������͡���������������������飬�ͷ���0

// ������������
class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        unordered_map<int, int> umap;
        long long sum = 0, res = 0;

        for (int i = 0; i < k; i++) {
            sum += nums[i];
            ++umap[nums[i]];
        }
        if (umap.size() >= m)
            res = max(res, sum);

        for (int i = k; i < nums.size(); i++) {
            sum += nums[i];
            ++umap[nums[i]];
            sum -= nums[i - k];

            if (--umap[nums[i - k]] == 0)
                umap.erase(nums[i - k]);

            if (umap.size() >= m)
                res = max(res, sum);
        }
        return res;
    }

    long long maxSum1(vector<int>& nums, int m, int k) {
        unordered_map<int, int> umap;
        long long sum = 0, res = 0;

        for (int i = 0; i < k - 1; i++) {
            sum += nums[i];
            ++umap[nums[i]];
        }

        for (int i = k - 1; i < nums.size(); i++) {
            sum += nums[i];
            ++umap[nums[i]];

            if (i >= k) {
                sum -= nums[i - k];
                if (--umap[nums[i - k]] == 0)
                    umap.erase(nums[i - k]);
            }

            if (umap.size() >= m)
                res = max(res, sum);
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 2,6,7,3,1,7 };
    int m = 3, k = 4;
    cout << st.maxSum(nums, m, k) << endl;
    cout << st.maxSum1(nums, m, k) << endl;
    return 0;
}