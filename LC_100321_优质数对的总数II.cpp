#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// ��������������nums1��nums2����һ��������k������nums1[i]���Ա�nums[j] * k��������ϸ���

class Solution {
public:
    vector<int> getFactors(int num) {
        std::vector<int> factors;
        for (int i = 1; i <= std::sqrt(num); ++i) {
            if (num % i == 0) {
                factors.push_back(i);
                if (i != num / i) { // �����ظ����ƽ����������
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

        // ����nums1�е�ÿ��Ԫ�أ����������������������Щ������nums2Map�е�Ƶ��
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