//
// Created by ������ on 25-1-8.
//

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//  ����һ���������飬���س˻������������ֵ

// �˻���������ͼӷ�������������������ǳ˻�����ݵ�ǰֵ���������ֲ�һ���Ľ�������Բ���Ҫά����ǰһ���ַ�Ϊ��β������������˻���ҲҪά����ǰһ���ַ�Ϊ��β�����������С�˻�
// ��ǰֵ��ǰ��������ĳ˻������ֵ���ܳ���������������£���һ�־��ǵ�ǰ�ַ�����������ֵ

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        int n = nums.size();
        vector<int> dp_max(n), dp_min(n);
        dp_max[0] = nums[0];
        dp_min[0] = nums[0];
        int res = nums[0];
        for (int i = 1; i < n; i++) {
            int temp = dp_max[i - 1];
            dp_max[i] = max(
                {dp_max[i - 1] * nums[i], dp_min[i - 1] * nums[i], nums[i]});
            dp_min[i] = min({temp * nums[i], dp_min[i - 1] * nums[i], nums[i]});
            res = max(res, dp_max[i]);
        }

        return res;
    }

    int maxProduct1(vector<int> &nums) {
        int res = INT_MIN;
        int max_val = 1;
        int min_val = 1;

        for (int i: nums) {
            int temp = max_val;
            max_val = max({max_val * i, min_val * i, i});
            min_val = min({min_val * i, temp * i, i});

            res = max(res, max_val);
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{2, 3, -2, 4};
    cout << st.maxProduct(nums) << endl;
    cout << st.maxProduct1(nums) << endl;

    return 0;
}
