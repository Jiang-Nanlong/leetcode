#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <list>
using namespace std;

// 矩阵edges表示一个无向图，edges[i]有三个元素，分别是from，to，val
// 数组disappear表示每个节点消失的时间，如果一个节点到达了消失时间就不可以再访问这个节点
// 返回从0开始到达每个节点所需的最小时间
// 典型的dijkstra算法，不过要加一个条件，判断到达一个顶点的时间是不是小于该顶点的disappear时间

class Solution1 {
    // 这套代码是按着代码随想录的模版写的
public:
    class comparison {
    public:
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        }
    };
    struct edge {
        int to;
        int val;
        edge(int t, int w) : to(t), val(w) {}
    };
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<list<edge>> grid(n);
        for (auto& e : edges) {
            grid[e[0]].push_back(edge(e[1], e[2]));
            grid[e[1]].push_back(edge(e[0], e[2]));
        }

        vector<int> minDist(n, -1);
        vector<int> visited(n, false);

        priority_queue<pair<int, int>, vector<pair<int, int>>, comparison> pq;
        pq.emplace(pair<int, int>(0, 0));
        minDist[0] = 0;

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            if (visited[cur.first]) continue;  // 这个判断语句对运行时间影响还挺大
            visited[cur.first] = true;
            for (edge& e : grid[cur.first]) {
                if (!visited[e.to]) {
                    int time = minDist[cur.first] + e.val;
                    if (time < disappear[e.to] && (minDist[e.to] == -1 || minDist[e.to] > minDist[cur.first] + e.val)) {
                        minDist[e.to] = time;
                        pq.emplace(pair<int, int>(e.to, time));
                    }
                }
            }
        }
        return minDist;
    }
};

class Solution2 {
    // 这套代码是自己写的
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int, int>>> grid(n);  // 这里不用edge结构体了，而是直接用pair，first表示to，second表示val
        for (auto& e : edges) {
            grid[e[0]].push_back({ e[1], e[2] });
            grid[e[1]].push_back({ e[0], e[2] });
        }

        vector<int> minDist(n, -1);
        vector<int> visited(n, false);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;  
        // 这里为了使用库的greater函数来排序，所以要把小顶堆里的pair和grid里的pair反过来，也就是pair.first表示到达这个节点的路径长度，pair.second表示节点
        // 这样在使用greater函数排序的时候，优先考虑pair.first，也就是路径长度
        pq.emplace(pair<int, int>(0, 0));
        minDist[0] = 0;

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            if (visited[cur.second])  // 如果一个节点被访问了
                continue;
            visited[cur.second] = true;
            for (auto& e : grid[cur.second]) {  // 遍历以cur.second为起点的所有边
                if (!visited[e.first]) {
                    int time = minDist[cur.second] + e.second;  // 计算到达e.first顶点的路径长度
                    if (time < disappear[e.first] && (minDist[e.first] == -1 || minDist[e.first] > time)) {  // 如果路径长度小于这个点消失的时间，同时minDist对应的位置为-1或者长度更长，则更新minDist数组
                        minDist[e.first] = time;
                        pq.emplace(pair<int, int>(time, e.first));
                    }
                }
            }
        }
        return minDist;
    }
};

int main() {
    Solution1 st1;
    int n = 3;
    vector<vector<int>> edges{ {0,1,2},{1,2,1},{0,2,4} };
    vector<int> disappear{ 1,1,5 };
    vector<int> res1 = st1.minimumTime(n, edges, disappear);
    for (int i : res1)
        cout << i << " ";
    cout << endl;

    Solution2 st2;
    vector<int> res2 = st2.minimumTime(n, edges, disappear);
    for (int i : res2)
        cout << i << " ";
    cout << endl;

    return 0;
}