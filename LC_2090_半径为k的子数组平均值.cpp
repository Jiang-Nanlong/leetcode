#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res(n, -1);
        int len = 2 * k + 1;

        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (i >= len - 1) {
                if (i >= len) {
                    sum -= nums[i - len];
                }
                res[k++] = sum / len;
            }
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 7,4,3,9,1,8,5,2,6 };
    int k = 3;
    vector<int> res = st.getAverages(nums, k);
    for (int i : res)
        cout << i << " ";
    cout << endl;
    return 0;
}