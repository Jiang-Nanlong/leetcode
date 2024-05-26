#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 有两个整数数组nums1和nums2，和一个正整数k，返回nums1[i]可以被nums[j] * k整除的组合个数

class Solution {
public:
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
};

int main() {
    Solution st;
    vector<int> nums1 = { 1, 2, 4, 12 }, nums2 = { 2, 4 };
    int k = 3;
    cout << st.numberOfPairs(nums1, nums2, k) << endl;
    return 0;
}