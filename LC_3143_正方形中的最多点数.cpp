#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ��ά����points�е���һ�������꣬s[i]��poings[i]��Ӧ���ַ��������ε�������(0,0)�������еı߶�ƽ���������ᣬ��������������ж��ٸ�����ͬ���ַ���
// �ַ����������εı���Ҳ�����������ڡ�

class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        vector<pair<int, char>> vec;
        for (int i = 0; i < points.size(); i++) {
            int x = max(abs(points[i][0]), abs(points[i][1]));
            vec.emplace_back(x, s[i]);
        }
        sort(vec.begin(), vec.end());  // �������Ժ�Ľ�����ǰ������С���������
        bool visited[26] = { false };
        int i = 0, count = 0;
        while (i < vec.size()) {
            int x = vec[i].first;
            int temp = 0;
            while (i < vec.size() && vec[i].first == x) { // temp����ͳ��λ��ͬһ�����������ϵĵ�ĸ���
                if (visited[vec[i].second - 'a'])  // ���������ֻҪ��һ�����Ӧ�ı�ǩ��ʹ���ˣ���ô�������ϵ�����Ͳ����ˣ�ֻ���˳���
                    return count;
                else {
                    temp++;
                    visited[vec[i].second - 'a'] = true;
                    i++;
                }
            }
            count += temp;  // ֻ��һ���ϵ����������Ӧ�ı�ǩ�����Ա�ʹ�ã��Ż����һ���ϵĵ�ĸ������ڽ����
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