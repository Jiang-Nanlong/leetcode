#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });
        int count = 0;
        int pre = 0;
        for (int i = 0; i < points.size(); i++) {
            if (i == 0) {
                pre = points[0][0];
                count++;
            }
            else if (points[i][0] - pre > w) {
                pre = points[i][0];
                count++;
            }
        }
        return count;
    }
};

int main() {
    Solution st;
    vector<vector<int>> points{ {2, 1},{1, 0},{1, 4},{1, 8},{3, 5},{4, 6} };
    int w = 1;
    cout << st.minRectanglesToCoverPoints(points, w) << endl;
    return 0;
}