#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        double res = -10000;
        for (int i = 0, j = 0; j < nums.size(); j++) {
            sum += nums[j];
            if (j - i + 1 > k) {
                sum -= nums[i++];
            }
            if (j - i + 1 == k)
                res = max(res, 1.0 * sum / k);
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 1,12,-5,-6,50,3 };
    int k = 4;
    cout << st.findMaxAverage(nums, k) << endl;
    return 0;
}