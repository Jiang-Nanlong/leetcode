#include<iostream>
#include <vector>
#include <numeric>
using namespace std;

// ����һ����������arr������������k��threshold�����������г���Ϊk����ƽ��ֵ���ڵ���threshold�����������Ŀ

// ԭ����ж�����������

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