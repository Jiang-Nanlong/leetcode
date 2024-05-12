#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //暴力解法
    int maximumEnergy(vector<int>& energy, int k) {
        int res = INT_MIN;
        for (int i = 0; i < energy.size(); i++) {
            int j = i;
            int count = energy[j];
            while ((j + k) < energy.size()) {
                j += k;
                count += energy[j];
            }
            res = max(res, count);
        }
        return res;
    }

    //动态规划做
    int maximumEnergy1(vector<int>& energy, int k) {
        int n = energy.size();

        for (int i = k; i < n; i++) {
            energy[i] = max(energy[i], energy[i - k] + energy[i]);
        }
        
        for (int i : energy)
            cout << i << " ";
        cout << endl;
        int res = energy[n - k];

        for (int i = n - k + 1; i < n; i++) {
            res = max(res, energy[i]);
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> energy = { 5,-10,4,3,5,-9,9,-7 };
    int k = 2;
    cout << st.maximumEnergy1(energy, k) << endl;
    return 0;
}