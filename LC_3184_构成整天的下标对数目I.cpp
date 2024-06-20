#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        int res = 0;
        for (int i = 0; i < hours.size() - 1; i++) {
            for (int j = i + 1; j < hours.size(); j++) {
                if ((hours[i] + hours[j]) % 24 == 0)
                    res++;
            }
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> hours{ 12,12,30,24,24 };
    cout << st.countCompleteDayPairs(hours) << endl;
    return 0;
}