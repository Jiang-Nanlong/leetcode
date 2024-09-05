#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int res = 0, maxangry = 0, angry = 0;
        int n = customers.size();
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0)
                res += customers[i];
            else
                angry += customers[i];
            if (i == minutes - 1)
                maxangry = angry;

            if (i >= minutes) {
                if (grumpy[i - minutes] == 1)
                    angry -= customers[i - minutes];
                maxangry = max(maxangry, angry);
            }
        }
        return res + maxangry;
    }
};

int main() {
    Solution st;
    vector<int> customers{ 1, 0, 1, 2, 1, 1, 7, 5 }, grumpy{ 0, 1, 0, 1, 0, 1, 0, 1 };
    int minutes = 3;
    cout << st.maxSatisfied(customers, grumpy, minutes) << endl;
    return 0;
}