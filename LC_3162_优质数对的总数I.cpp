#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int res = 0;
        for (int i : nums1) {
            for (int j : nums2) {
                if (i % (j * k) == 0)
                    res++;
            }
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums1 = { 1, 3, 4 }, nums2 = { 1, 3, 4 };
    int k = 1;
    cout << st.numberOfPairs(nums1, nums2, k) << endl;
    return 0;
}