#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n + 1, 0);
        for (auto& vec : bookings) {
            int first = vec[0], last = vec[1], seats = vec[2];
            diff[first] += seats;
            if (last + 1 <= n)
                diff[last + 1] -= seats;
        }
        for (int i = 1; i <= n; i++)
            diff[i] += diff[i - 1];
        return vector<int>(diff.begin() + 1, diff.end());
    }
};

int main() {
    Solution st;
    vector<vector<int>> bookings{ {1,2,10},{2,3,20},{2,5,25} };
    int n = 5;
    vector<int> res = st.corpFlightBookings(bookings, n);
    for (int i : res)
        cout << i << " ";
    cout << endl;
    return 0;
}