#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // 这是一开始的做法，先计算出每个被除数的所有因数，然后再在numberOfPairs函数内查找。时间复杂度是On3
    vector<int> getFactors(int num) {
        std::vector<int> factors;
        for (int i = 1; i <= std::sqrt(num); ++i) {
            if (num % i == 0) {
                factors.push_back(i);
                if (i != num / i) { // 避免重复添加平方根的因数
                    factors.push_back(num / i);
                }
            }
        }
        return factors;
    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        std::unordered_map<int, int> nums2Map;
        for (int num : nums2) {
            nums2Map[num * k]++;
        }

        long long count = 0;

        // 对于nums1中的每个元素，计算其所有因数并检查这些因数在nums2Map中的频率
        for (int num1 : nums1) {
            std::vector<int> factors = getFactors(num1);
            for (int factor : factors) {
                if (nums2Map.find(factor) != nums2Map.end()) {
                    count += nums2Map[factor];
                }
            }
        }
        return count;
    }


    // 这个时间复杂度只有On2，其实思路都是一样的
    long long numberOfPairs1(vector<int>& nums1, vector<int>& nums2, int k) {
        static int pp[1000005];
        memset(pp, 0, sizeof(pp));
        for (int& num : nums2) {
            num *= k;
            if (num <= 1e6)  // 这里如果nums2乘以k以后的结果超过1e6就不统计了，因为nums1中的数都是小于等于1e6的，超过这个数肯定就不可能是nums1的因数了
                pp[num]++;
        }
        long long res = 0;
        for (int num : nums1) {
            for (int i = 1; i <= sqrt(num); i++) {
                if (num % i == 0) {
                    res += pp[i];
                    if (i != num / i)
                        res += pp[num / i];
                }
            }
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums1 = { 1, 2, 4, 12 }, nums2 = { 2, 4 };
    int k = 3;
    cout << st.numberOfPairs1(nums1, nums2, k) << endl;
    return 0;
}