#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 二维数组points中的是一个个坐标，s[i]是poings[i]对应的字符。正方形的中心在(0,0)处，所有的边都平行于坐标轴，问正方形内最多有多少个不相同的字符。
// 字符落在正方形的边上也算是正方形内。

class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        vector<pair<int, char>> vec;
        for (int i = 0; i < points.size(); i++) {
            int x = max(abs(points[i][0]), abs(points[i][1]));
            vec.emplace_back(x, s[i]);
        }
        sort(vec.begin(), vec.end());  // 排序完以后的结果就是按坐标从小到大排序的
        bool visited[26] = { false };
        int i = 0, count = 0;
        while (i < vec.size()) {
            int x = vec[i].first;
            int temp = 0;
            while (i < vec.size() && vec[i].first == x) { // temp用来统计位于同一个正方形周上的点的个数
                if (visited[vec[i].second - 'a'])  // 如果该周上只要有一个点对应的标签被使用了，那么整个周上的坐标就不行了，只能退出了
                    return count;
                else {
                    temp++;
                    visited[vec[i].second - 'a'] = true;
                    i++;
                }
            }
            count += temp;  // 只有一周上的所有坐标对应的标签都可以被使用，才会把这一周上的点的个数加在结果里
        }
        return count;
    }
};

int main() {
    Solution st;
    vector<vector<int>> points{ {2, 2}, {-1, -2}, {-4, 4}, {-3, 1}, {3, -3} };
    string s("abdca");
    cout << st.maxPointsInsideSquare(points, s) << endl;
    return 0;
}