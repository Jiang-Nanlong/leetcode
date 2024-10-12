#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// ������������г���k����ͬ�����ԣ���ô��˵����һ���������飬���غ����������Ŀ

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        long long res = 0;
        int cnt = 0, n = nums.size();  // cnt����ͳ�����Եĸ���
        for (int i = 0, j = 0; j < n; j++) {
            ++umap[nums[j]];
            // ��Ϊǰ��nums[j]����������1����ônums[j]�����Ծ�Ҫ����umap[nums[j]] - 1������Ϊ�����ӵ�nums[j]��֮ǰ�Ĵ����ڵ�nums[j]�������
            cnt += umap[nums[j]] - 1;
            while (cnt >= k) {
                --umap[nums[i]];
                cnt -= umap[nums[i++]];  // ͬʱ��ȥ��Ӧ������
            }
            res += i;
        }
        return res;
    }

    // ���ϱ�һ���������ϱ�ͳ�Ƶ������ÿ���Ҷ˵㣬�±�ͳ�Ƶ������ÿ����˵�
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