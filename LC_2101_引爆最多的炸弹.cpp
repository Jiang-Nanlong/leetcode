#include <iostream>
#include <vector>
#include <functional>
using namespace std;

typedef long long ll;

class Solution {
public:
    // 自己用dfs做的
    int maximumDetonation(vector<vector<int>>& bombs) {
        int res = 0;
        int n = bombs.size();
        for (int i = 0; i < n; i++) {
            vector<bool> visited(n, false);
            int count = backtracking(i, visited, bombs);
            res = max(res, count);
        }
        return res;
    }

    int backtracking(int start, vector<bool>& visited,
        vector<vector<int>>& bombs) {
        int count = 1;
        visited[start] = true;
        for (int i = 0; i < visited.size(); i++) {
            if (i == start)
                continue;
            if (visited[i] == false) {
                int w = abs(bombs[start][0] - bombs[i][0]);
                int h = abs(bombs[start][1] - bombs[i][1]);
                
                // 这里下边的测试用例一直不通过，后来用了claude才知道是因为用了sqrt计算开方会有误差
                /*long long r = sqrt(1LL * w * w + 1LL * h * h);
                if (r <= bombs[start][2])
                    count += backtracking(i, visited, bombs);*/

                long long r2 = 1LL * w * w + 1LL * h * h;
                if (r2 <= 1LL * bombs[start][2] * bombs[start][2])  
                    count += backtracking(i, visited, bombs);
            }
        }
        return count;
    }

    // 这是看的别人的代码
    int maximumDetonation1(vector<vector<int>>& bombs) {

        int n = bombs.size();
        vector<vector<int>> g(n);  // 构建邻接表，如果一个炸弹可以引爆另一个就加入邻接表
        for (int i = 0; i < n; i++) {
            ll x1 = bombs[i][0], y1 = bombs[i][1], r1 = bombs[i][2];
            for (int j = i + 1; j < n; j++) {  // 这个地方我开始还在想为什么j从i+1开始就行，直到看到下边的两个if
                ll x2 = bombs[j][0], y2 = bombs[j][1], r2 = bombs[j][2];
                ll dx = x1 - x2, dy = y1 - y2;
                ll s = dx * dx + dy * dy;
                if (r1 * r1 >= s) g[i].emplace_back(j); // 如果i可以引爆j
                if (r2 * r2 >= s) g[j].emplace_back(i); // 如果j可以引爆i
            }
        }
        vector<bool> visited(n, false);
        function<int(int)> dfs = [&](int i) {
            visited[i] = true;
            int count = 1;
            for (int j : g[i]) {
                if (!visited[j])
                    count += dfs(j);
            }
            return count;
            };
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (i) fill(visited.begin(), visited.end(), false);  // 从下标1开始重置visited数组
            int count = dfs(i);
            res = max(res, count);
        }
        return res;
    }
};

int main() {
	Solution st;
	vector<vector<int>> bombs {
		{647, 457, 91}, {483, 716, 37}, {426, 119, 35}, {355, 588, 40},
		{850, 874, 49}, {232, 568, 46}, {886, 1, 30}, {54, 377, 3}, {933, 986, 50}, {305, 790, 49},
		{372, 961, 67}, {671, 314, 58}, {577, 221, 29}, {380, 147, 91}, {600, 535, 1}, {806, 329, 64},
		{536, 753, 18}, {906, 88, 23}, {436, 783, 82}, {652, 674, 45}, {449, 668, 20}, {419, 13, 66},
		{853, 767, 60}, {169, 288, 33}, {871, 608, 66}, {337, 445, 35}, {388, 623, 39}, {723, 503, 81},
		{14, 19, 19}, {98, 648, 72}, {147, 565, 93}, {655, 434, 1}, {407, 663, 22}, {805, 947, 83},
		{942, 160, 70}, {959, 496, 93}, {30, 988, 53}, {187, 849, 60}, {980, 483, 41}, {663, 150, 76},
		{268, 39, 50}, {513, 522, 75}, {61, 450, 90}, {115, 231, 12}, {346, 304, 74}, {385, 540, 23},
		{905, 178, 19}, {336, 896, 81}, {751, 811, 94}, {527, 783, 78}, {635, 965, 19}, {334, 290, 39},
		{748, 460, 77}, {414, 134, 22}, {955, 485, 29}, {925, 787, 43}, {243, 771, 75}, {675, 223, 29},
		{788, 618, 82}, {462, 544, 30}, {999, 259, 50}, {210, 146, 12}, {789, 442, 70}, {286, 36, 55},
		{451, 953, 6}, {719, 914, 14}, {664, 452, 14}, {933, 637, 29}, {206, 926, 16}, {100, 422, 98},
		{97, 333, 4}, {505, 631, 26}, {908, 287, 65}, {907, 316, 86}, {949, 185, 16}, {639, 735, 62},
		{401, 739, 18}, {605, 926, 21}, {25, 391, 69}, {80, 24, 9}, {435, 874, 92}, {940, 381, 18},
		{260, 740, 87}, {727, 515, 17}, {361, 152, 16}, {512, 470, 67}, {189, 27, 27}, {517, 439, 94},
		{159, 543, 76}, {373, 698, 38}, {781, 836, 97}, {584, 190, 23}, {383, 367, 86}, {825, 141, 63},
		{117, 926, 85}, {169, 588, 60}, {56, 981, 100}, {294, 716, 100}, {781, 370, 89}, {373, 44, 78}
	};
	cout << st.maximumDetonation(bombs) << endl;

	cout << st.maximumDetonation1(bombs) << endl;

	return 0;
}