#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // ����Ǽ������������������
    long long countSubarrays(vector<int>& nums, int k) {
        int maxnum = INT_MIN;
        for (int i : nums)
            maxnum = max(maxnum, i);

        long long res = 0;
        int fre = 0;
        for (int i = 0, j = 0; j < nums.size(); j++) {
            fre += nums[j] == maxnum;
            while (fre == k) {
                fre -= nums[i++] == maxnum;
            }
            res += i;
        }
        return res;
    }

    // ����Ǽ������������������
    long long countSubarrays1(vector<int>& nums, int k) {
        int maxnum = INT_MIN;
        for (int i : nums)
            maxnum = max(maxnum, i);

        long long res = 0;
        int fre = 0;
        for (int i = 0, j = 0; j < nums.size(); j++) {
            fre += nums[j] == maxnum;
            while (fre == k) {
                res += (nums.size() - j);
                fre -= nums[i++] == maxnum;
            }
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 1,3,2,3,3 };
    int k = 2;
    cout << st.countSubarrays(nums, k) << endl;
    cout << st.countSubarrays1(nums, k) << endl;
    return 0;
}