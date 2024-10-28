#include <iostream>
#include <vector>
using namespace std;

// ����һ���������飬��һ������k��һ��������ķ�������Ϊ��������Ԫ�ص���Сֵ������������Ԫ�صĸ���
// һ��������������±�Ҫ����i<=k<=j�������������������

// ���԰�Ԫ�ص�ֵ���Ϊ�߶ȣ�������ķ����������

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int res = nums[k], min_h = nums[k];
        int n = nums.size();
        int i = k, j = k;
        for (int t = 0; t < n - 1; t++) {
            if (j == n - 1 && i > 0)
                min_h = min(min_h, nums[--i]);
            else if (i == 0 && j < n - 1)
                min_h = min(min_h, nums[++j]);
            else if (nums[i - 1] > nums[j + 1])  // ˭������ĸ������ƶ�����Ϊ���͵ķ����ƶ�������ĸ����ø���
                min_h = min(min_h, nums[--i]);
            else
                min_h = min(min_h, nums[++j]);
            res = max(res, min_h * (j - i + 1));
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 1,4,3,7,4,5 };
    int k = 3;
    cout << st.maximumScore(nums, k) << endl;
    return 0;
}