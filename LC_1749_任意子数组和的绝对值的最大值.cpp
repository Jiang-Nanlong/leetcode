//
// Created by ������ on 25-1-6.
//

#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

// ������������nums��������ĺ͵ľ���ֵ�����ֵ

// һ��ʼ��ֻ����һ��vector���������Ƿ�����[-7,-1,0,-2,1,3,8,-2,-6,-1,-10,-6,-6,8,-4,-9,-4,1,4,-9]ʱ������᲻�ԣ�����������һ�·��֣�
// ������͵ľ���ֵ���ʱ���������������������С��ʱ�򣬲��ܰ��������������һ����

class Solution {
public:
    int maxAbsoluteSum(vector<int> &nums) {
        int n = nums.size();
        vector<int> dp_max(n, 0);
        vector<int> dp_min(n, 0);
        dp_max[0] = nums[0];
        dp_min[0] = nums[0];

        int res = abs(nums[0]);
        for (int i = 1; i < n; i++) {
            dp_max[i] = max(dp_max[i - 1], 0) + nums[i];
            dp_min[i] = min(dp_min[i - 1], 0) + nums[i];

            res = max(res, max(abs(dp_max[i]), abs(dp_min[i])));
        }
        return res;
    }

    // ���LC_53_�����������е�maxSubArray7��д����ʡ��dp�����д��
    int maxAbsoluteSum1(vector<int> &nums) {
        int res = 0;
        int f_max = 0, f_min = 0;

        for (int i: nums) {
            f_max = max(f_max, 0) + i;
            f_min = min(f_min, 0) + i;

            res = max(res, max(abs(f_max), abs(f_min)));
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{-7, -1, 0, -2, 1, 3, 8, -2, -6, -1, -10, -6, -6, 8, -4, -9, -4, 1, 4, -9};
    cout << st.maxAbsoluteSum(nums) << endl;
    cout << st.maxAbsoluteSum1(nums) << endl;

    return 0;
}
