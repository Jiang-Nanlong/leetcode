#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 给定一个整数数组和一个整数k，一次操作中可以把任意一个元素加1，最多执行k次操作，返回数组中最高频元素的最大频数。
// 其实就是个阶梯型，把阶梯调整成同一水平面需要的花费和k之间比较，进而滑动窗口

class Solution {
public:
    //开始的时候一直用这个思路，但是最后一个测试用例老是报错，后来才想到会不会是整数越界，后来一看还真是。
    /*int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int maxlen = 1;
        for (int i = 0, j = 1; j < nums.size(); j++) {
            k -= 1LL * (nums[j] - nums[j - 1]) * (j - i);  // k是int型的，力扣最后的测试用例超过了整数的范围
            while (k < 0) {
                k += nums[j] - nums[i++];
            }
            maxlen = max(maxlen, j - i + 1);
        }
        return maxlen;
    }*/
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int maxlen = 1;
        long long k1 = (long long)k;  // 换成long long就行了
        for (int i = 0, j = 1; j < nums.size(); j++) {
            k1 -= 1LL * (nums[j] - nums[j - 1]) * (j - i);
            while (k1 < 0) {
                k1 += nums[j] - nums[i++];
            }

            maxlen = max(maxlen, j - i + 1);
        }
        return maxlen;
    }


    int maxFrequency1(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int maxlen = 1;
        long long cost = 0;
        for (int i = 0, j = 1; j < nums.size(); j++) {
            cost += 1LL * (nums[j] - nums[j - 1]) * (j - i);  // 或者计算把前边数字变为一样的花费，也是要用longlong
            while (k < cost) {
                cost -= nums[j] - nums[i++];
            }

            maxlen = max(maxlen, j - i + 1);
        }
        return maxlen;
    }
};
int main() {
    Solution st;
    vector<int> nums{ 1,4,8,13 };
    int k = 5;
    cout << st.maxFrequency(nums, k) << endl;
    cout << st.maxFrequency1(nums, k) << endl;
    return 0;
}