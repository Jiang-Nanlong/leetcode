//
// Created by ������ on 25-1-6.
//

#include <vector>
#include <iostream>
#include <numeric>
using namespace std;

// ����һ����������arr����һ������k����˼����������arr���Դ���k�Σ����ش���k��֮����������ֵ�������1e9+7ȡ��

// �ȶ�ԭʼarr��������ܺ�sum������sum��k��Ϊ���������
// ���sum<=0��k==1ʱ��ֻ��arr��һ��dp���ɣ�
// ���sum>0,k==1ʱ��Ҳֻ��һ��dp���ɣ����Կ��Ժ��ϱߺ����� k==1��
// ���sum<=0,k>=2ʱ����ôֻ��Ҫ������arrƴ����һ����һ��dp���ɣ�
// ���sum>0,k==2ʱ����ôҲֻ��Ҫ������arrƴ����һ����һ��dp���ɣ����ֿ��Ժ��ϱߵĺ�Ϊһ�������
// ���sum>0,k>2ʱ����ô��Ҫ�Ȱ�����arrƴ����һ����һ��dp��Ȼ������м�k-2��sum�ĺͼ��ɡ�

// �����ܹ���Ϊ���������
// k==1��
// (sum<=0 && k>=2) || (sum>0 && k==2)
// sum>0 && k>2
// �ڶ������ֶ���Ҫ��ԭʼ������arrƴ����һ����һ��dp

class Solution {
    const int MOD = 1e9 + 7;
    using ll = long long;

    ll compute(vector<int> &arr) {
        int val = 0;
        int res = 0;
        for (int i: arr) {
            val = max(val, 0) + i;
            res = max(res, val);
        }
        return res;
    }

public:
    int kConcatenationMaxSum(vector<int> &arr, int k) {
        if (k == 1) {
            return compute(arr) % MOD;
        } else {
            ll sum = accumulate(arr.begin(), arr.end(), 0);
            arr.insert(arr.end(), arr.begin(), arr.end());
            int ans = compute(arr);
            if (sum <= 0) {
                return ans;
            } else {
                return (1LL * ans + (k - 2) * sum) % MOD;
            }
        }
    }
};

int main() {
    Solution st;
    vector<int> arr{-5, -2, 0, 0, 3, 9, -2, -5, 4};
    int k = 5;
    cout << st.kConcatenationMaxSum(arr, k) << endl;
    return 0;
}
