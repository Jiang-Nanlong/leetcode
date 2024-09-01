#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int n = startTime.size();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (startTime[i] <= queryTime && endTime[i] >= queryTime)
                ++res;
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> startTime{ 1,2,3 }, endTime{ 3,2,7 };
    int queryTime = 4;
    cout << st.busyStudent(startTime, endTime, queryTime) << endl;
    return 0;
}