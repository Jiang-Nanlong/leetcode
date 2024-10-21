#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int check(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int res = 0;
        for (int i = 0; i < n1; i++) {
            int j = 0, k = n2 - 1;
            long long a = 1LL * nums1[i] * nums1[i];
            while (j < k) {
                long long b = 1LL * nums2[j] * nums2[k];
                if (a == b) {
                    if (nums2[j] == nums2[k]) {
                        res += (k - j + 1) * (k - j) / 2;
                        break;
                    }
                    else {
                        int count1 = 1, count2 = 1;
                        while (nums2[j] == nums2[++j])
                            count1++;
                        while (nums2[k] == nums2[--k])
                            count2++;
                        res += count1 * count2;
                    }
                }
                else if (a > b) {
                    j++;
                }
                else if (a < b)
                    k--;
            }
        }
        return res;
    }
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        return check(nums1, nums2) + check(nums2, nums1);
    }
};

int main() {
    Solution st;
    vector<int> nums1{ 1,1 }, nums2{ 1,1,1 };
    cout << st.numTriplets(nums1, nums2) << endl;
    return 0;
}