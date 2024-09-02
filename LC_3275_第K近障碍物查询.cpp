#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 给定一个二维数组queries，queries[i]=[x,y]，表示平面坐标系上的一个坐标，依次把数组中的坐标加入到集合中，
// 同时给定一个正整数k，结果返回一个数组results，result[i]表示把第i个坐标加入到集合中以后，距离原点第k近的坐标到原点的距离，
// 这里的(x,y)到原点的距离为|x|+|y|，如果集合中少于k个元素，则results[i] == -1

// 其实就是求第k大的元素，直接用大根堆，大根堆内维护k个元素。

class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        priority_queue<int> pq;
        vector<int> res;
        for (auto v : queries) {
            int temp = abs(v[0]) + abs(v[1]);

            if (pq.size() < k) { // 如果堆内元素个数小于k
                pq.push(temp);
                if (pq.size() == k) {
                    res.push_back(pq.top());
                }
                else {
                    res.push_back(-1);
                }
            }
            else {
                if (temp < pq.top()) {  // 如果堆内元素个数大于等于k，且当前坐标到原点的距离小于堆顶元素，则把堆顶元素弹出，当前元素入堆
                    pq.pop();
                    pq.push(temp);
                }
                res.push_back(pq.top());
            }
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<vector<int>> queries{ {1, 2},{3, 4},{2, 3},{-3, 0} };
    int k = 2;
    vector<int> res = st.resultsArray(queries, k);
    for (int i : res)
        cout << i << " ";
    cout << endl;

    return 0;
}