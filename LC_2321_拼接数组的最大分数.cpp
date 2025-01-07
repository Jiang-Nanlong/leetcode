//
// Created by ������ on 25-1-7.
//
#include <iostream>
#include <vector>
using namespace std;

// ����������nums1��nums2��������ͬ�����Խ���һ�λ�������������е�ĳ�������飬�����Ƕ�λ�����飬Ȼ�󷵻�sum(nums1)��sum(nums2)�е����ֵ
// ����nums2�е�ĳ���������滻��nums1�еĶ�λ������Ϊ������ôsum(nums1) = sum(ԭʼnums1) - (nums1[l]+...+nums1[r]) + nums2[l]+...+nums2[r]
// �������к�Ϊsum(nums1) = sum(ԭʼnums1) + (nums2[l]-nums1[l])+...+(nums2[r]-nums1[r])
// Ҫ��sum(nums1)�����ô�ͱ�����(nums2[l]-nums1[l])+...+(nums2[r]-nums1[r])��󣬾�ת��Ϊ������������������͵�����

class Solution {
public:
    int maximumsSplicedArray(vector<int> &nums1, vector<int> &nums2) {
        int sum_nums1 = 0;
        int sum_nums2 = 0;

        int val = 0;
        int max_val1 = 0, max_val2 = 0;
        int n = nums1.size();

        for (int i = 0; i < n; i++) {
            sum_nums1 += nums1[i];
            sum_nums2 += nums2[i];

            val = max(val, 0) + nums2[i] - nums1[i];
            max_val1 = max(max_val1, val);
        }

        val = 0;
        for (int i = 0; i < n; i++) {
            val = max(val, 0) + nums1[i] - nums2[i];
            max_val2 = max(max_val2, val);
        }

        return max(sum_nums1, max(sum_nums2, max(sum_nums1 + max_val1,
                                                 sum_nums2 + max_val2)));
    }
};

int main() {
    Solution st;
    vector<int> nums1{10, 20, 50, 15, 30, 10}, nums2{40, 20, 10, 100, 10, 10};
    cout << st.maximumsSplicedArray(nums1, nums2) << endl;

    return 0;
}
