#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <list>
using namespace std;

// ����edges��ʾһ������ͼ��edges[i]������Ԫ�أ��ֱ���from��to��val
// ����disappear��ʾÿ���ڵ���ʧ��ʱ�䣬���һ���ڵ㵽������ʧʱ��Ͳ������ٷ�������ڵ�
// ���ش�0��ʼ����ÿ���ڵ��������Сʱ��
// ���͵�dijkstra�㷨������Ҫ��һ���������жϵ���һ�������ʱ���ǲ���С�ڸö����disappearʱ��

class Solution1 {
    // ���״����ǰ��Ŵ�������¼��ģ��д��
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
            if (visited[cur.first]) continue;  // ����ж���������ʱ��Ӱ�컹ͦ��
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
    // ���״������Լ�д��
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int, int>>> grid(n);  // ���ﲻ��edge�ṹ���ˣ�����ֱ����pair��first��ʾto��second��ʾval
        for (auto& e : edges) {
            grid[e[0]].push_back({ e[1], e[2] });
            grid[e[1]].push_back({ e[0], e[2] });
        }

        vector<int> minDist(n, -1);
        vector<int> visited(n, false);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;  
        // ����Ϊ��ʹ�ÿ��greater��������������Ҫ��С�������pair��grid���pair��������Ҳ����pair.first��ʾ��������ڵ��·�����ȣ�pair.second��ʾ�ڵ�
        // ������ʹ��greater���������ʱ�����ȿ���pair.first��Ҳ����·������
        pq.emplace(pair<int, int>(0, 0));
        minDist[0] = 0;

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            if (visited[cur.second])  // ���һ���ڵ㱻������
                continue;
            visited[cur.second] = true;
            for (auto& e : grid[cur.second]) {  // ������cur.secondΪ�������б�
                if (!visited[e.first]) {
                    int time = minDist[cur.second] + e.second;  // ���㵽��e.first�����·������
                    if (time < disappear[e.first] && (minDist[e.first] == -1 || minDist[e.first] > time)) {  // ���·������С���������ʧ��ʱ�䣬ͬʱminDist��Ӧ��λ��Ϊ-1���߳��ȸ����������minDist����
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