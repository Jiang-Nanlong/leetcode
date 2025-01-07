//
// Created by ������ on 25-1-7.
//
#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
using namespace std;

// ����һ����������nums������nums�ķǿ������������

// �������ѵ���Ҫ�����͵ķǿ���������ܻ��Խ�߽硣�����Խ�߽�Ļ�ֱ�������Ͳ�̫���󣬵���������ܺ�һ����������͵��������Խ�߽磬��ô�м�������һ�ο϶�����Сֵ��
// ��ô�����ֵ������ͱ�������м����������Сֵ��������֤������һ�����߽磬����Ҳ��һ��ԭʼ����������ֵ��
// ��һ���������������м���Сֵ�����������������nums��������Ŀ��Ҫ��nums�ķǿ�����������ͣ���ô�ͷ���ԭʼ����������ֵ������


class Solution {
public:
    int maxSubarraySumCircular(vector<int> &nums) {
        int val = 0;
        int maxval = INT_MIN;
        for (int i: nums) {
            val = max(val, 0) + i;
            maxval = max(val, maxval);
        }

        val = 0;
        int minval = INT_MAX;
        for (const int &i: nums) {
            val = min(val, 0) + i;
            minval = min(val, minval);
        }

        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum == minval)
            return maxval;

        return max(maxval, sum - minval);
    }

    // ���ϴ�������Ż�һ�£�����һ��ѭ������
    int maxSubarraySumCircular1(vector<int> &nums) {
        int max_val = 0;
        int min_val = 0;
        int max_sum = INT_MIN;
        int min_sum = INT_MAX;
        int sum = 0;

        for (const int &i: nums) {
            sum += i;
            max_val = max(max_val, 0) + i;
            max_sum = max(max_val, max_sum);

            min_val = min(min_val, 0) + i;
            min_sum = min(min_sum, min_val);
        }
        return sum == min_sum ? max_sum : max(max_sum, sum - min_sum);
    }
};

int main() {
    Solution st;
    vector<int> nums{5, -3, 5};
    cout << st.maxSubarraySumCircular(nums) << endl;

    return 0;
}
