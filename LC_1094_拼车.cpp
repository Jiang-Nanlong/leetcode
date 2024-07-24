#include <iostream>
#include <vector>
using namespace std;

// ����һ��capacity��ʾ�����Ŀ���λ��һ�����飬�����е�ÿһ��Ԫ�ر�ʾ���ϳ���������㣬�յ㣩���ж϶��������и������г̰��ţ���ͳ��ǲ��ǿ��԰��˶��͵�վ��
// Ҳ�����ж�ĳһ��վ��ʱ�����������ǲ��ǳ����˳����ĺ���������

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