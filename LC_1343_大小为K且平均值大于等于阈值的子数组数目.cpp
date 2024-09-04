#include<iostream>
#include <vector>
#include <numeric>
using namespace std;

// 给定一个整数数组arr，和两个整数k和threshold，返回数组中长度为k，且平均值大于等于threshold的子数组的数目

// 原来这叫定长滑动窗口

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = accumulate(arr.begin(), arr.begin() + k, 0);
        int key = k * threshold, res = sum >= key ? 1 : 0;

        int i = 0, j = k;
        while (j < arr.size()) {
            sum += arr[j++];
            sum -= arr[i++];
            if (sum >= key)
                res++;
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> arr{ 2,2,2,2,5,5,5,8 };
    int k = 3, threshold = 4;
    cout << st.numOfSubarrays(arr, k, threshold) << endl;
    return 0;
}