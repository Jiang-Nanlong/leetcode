#include <iostream>
#include <vector>
using namespace std;

// 给定一个capacity表示车辆的空座位和一个数组，数组中的每一个元素表示（上车人数，起点，终点），判断对于数组中给定的行程安排，大巴车是不是可以把人都送到站。
// 也就是判断某一个站点时，车上人数是不是超过了车辆的核载人数。

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> diff(1001);
        for (auto& vec : trips) {
            int from = vec[1], to = vec[2], num = vec[0];
            diff[from] += num;
            diff[to] -= num;
        }

        for (int i = 0; i < 1001; i++) {
            if (i > 0)
                diff[i] += diff[i - 1];
            if (diff[i] > capacity)
                return false;
        }
        return true;
    }
};

int main() {
    Solution st;
    vector<vector<int>> trips{ {2,1,5},{3,3,7} };
    int capacity = 4;
    cout << boolalpha << st.carPooling(trips, capacity) << noboolalpha << endl;
    return 0;
}