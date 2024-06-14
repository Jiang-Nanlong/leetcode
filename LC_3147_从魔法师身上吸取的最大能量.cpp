#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        vector<int> dp(energy.size(), 0);
        for (int i = 0; i < k; i++)
            dp[i] = energy[i];

        for (int i = k; i < energy.size(); i++) {
            dp[i] = max(energy[i], dp[i - k] + energy[i]);
        }

        int i = energy.size() - 1, res = INT_MIN;
        while (k--) {
            res = max(res, dp[i--]);
        }
        return res;
    }

    //其实还可以再优化一下，直接使用energy数组当做dp数组
    int maximumEnergy1(vector<int>& energy, int k) {
        for (int i = k; i < energy.size(); i++) {
            energy[i] = max(energy[i], energy[i - k] + energy[i]);
        }

        int i = energy.size() - 1, res = INT_MIN;
        while (k--) {
            res = max(res, energy[i--]);
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> energy{ 5,-10,4,3,5,-9,9,-7 };
    int k = 2;
    cout << st.maximumEnergy(energy, k) << endl;
    cout << st.maximumEnergy1(energy, k) << endl;
    return 0;
}