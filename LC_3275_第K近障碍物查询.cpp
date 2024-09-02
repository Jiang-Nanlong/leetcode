#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ����һ����ά����queries��queries[i]=[x,y]����ʾƽ������ϵ�ϵ�һ�����꣬���ΰ������е�������뵽�����У�
// ͬʱ����һ��������k���������һ������results��result[i]��ʾ�ѵ�i��������뵽�������Ժ󣬾���ԭ���k�������굽ԭ��ľ��룬
// �����(x,y)��ԭ��ľ���Ϊ|x|+|y|���������������k��Ԫ�أ���results[i] == -1

// ��ʵ�������k���Ԫ�أ�ֱ���ô���ѣ��������ά��k��Ԫ�ء�

class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        priority_queue<int> pq;
        vector<int> res;
        for (auto v : queries) {
            int temp = abs(v[0]) + abs(v[1]);

            if (pq.size() < k) { // �������Ԫ�ظ���С��k
                pq.push(temp);
                if (pq.size() == k) {
                    res.push_back(pq.top());
                }
                else {
                    res.push_back(-1);
                }
            }
            else {
                if (temp < pq.top()) {  // �������Ԫ�ظ������ڵ���k���ҵ�ǰ���굽ԭ��ľ���С�ڶѶ�Ԫ�أ���ѶѶ�Ԫ�ص�������ǰԪ�����
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