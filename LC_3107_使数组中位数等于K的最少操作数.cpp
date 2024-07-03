#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ����һ����������nums��һ���Ǹ�����k��һ�β���ֻ��+1��-1�����ذ��������λ�����k����Ҫ�����ٲ�������
// ������鳤��Ϊż������ѡ���м��������нϴ�ֵ��Ϊ��λ��
// ��Ϊ��ż�����������м��������нϴ������Ϊ��λ�����ڵ��������У���ô���ǾͿ���ֱ�Ӱ��ұ��Ǹ�����Ϊ��λ���������������Ⱥ�ż�����ȼ�����λ����λ�þ�ͳһ������,����n/2,
// Ȼ���n/2��λ������λ��k����ôֻ��Ҫ�������С�ڵ���k���ұߵ������ڵ���k���ɡ�
// Ϊ�˴ﵽ���ٲ���������ߴ���k���������k���ұ�С��k����Ҳ�����k�����ˡ�

class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int mid = n / 2;
        long long count = (long long)abs(k - nums[mid]);

        for (int i = 0; i < mid; i++) {  // ��ߴ���k���������k
            if (nums[i] > k)
                count += (long long)nums[i] - k;
        }
        for (int i = mid + 1; i < n; i++) {  // �ұ�С��k���������k
            if (nums[i] < k)
                count += (long long)k - nums[i];
        }
        return count;
    }
};

int main() {
    Solution st;
    vector<int>nums{ 2,5,6,8,5 };
    int k = 7;
    cout << st.minOperationsToMakeMedianK(nums, k) << endl;
    return 0;
}