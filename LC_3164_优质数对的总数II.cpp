#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // ����һ��ʼ���������ȼ����ÿ��������������������Ȼ������numberOfPairs�����ڲ��ҡ�ʱ�临�Ӷ���On3
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


    // ���ʱ�临�Ӷ�ֻ��On2����ʵ˼·����һ����
    long long numberOfPairs1(vector<int>& nums1, vector<int>& nums2, int k) {
        static int pp[1000005];
        memset(pp, 0, sizeof(pp));
        for (int& num : nums2) {
            num *= k;
            if (num <= 1e6)  // �������nums2����k�Ժ�Ľ������1e6�Ͳ�ͳ���ˣ���Ϊnums1�е�������С�ڵ���1e6�ģ�����������϶��Ͳ�������nums1��������
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