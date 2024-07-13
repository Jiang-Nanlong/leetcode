#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(),
            [](int& a, int& b) { return a > b; });
        long long sum = 0;
        for (int i = 0; i < k; i++) {
            sum += 1LL * (happiness[i] - i > 0 ? happiness[i] - i : 0);
        }
        return sum;
    }
};

int main() {
    Solution st;
    vector<int> happiness{ 1,2,3 };
    int k = 2;
    cout << st.maximumHappinessSum(happiness, k) << endl;
    return 0;
}