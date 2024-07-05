#include <iostream>
#include <vector>
using namespace std;

// A��B����������Ϸ��A��0��ʼ�ߣ��������1���÷־ͼ�1���������0���÷־ͼ�1.A�ߵ�һ���ؿ���B����ʣ�µģ��Ʒֹ���һ����
// ��A�÷ֱ�B�ߣ�����Ҫ��ɶ��ٹء�����ÿ������Ҫ���һ���ؿ���
// ���еĹؿ���һ���ܵĵ÷��ǹ̶��ģ����ܵ÷ּ�ȥA�ĵ÷־���B�ĵ÷֡�
// ֻҪA�ĵ÷� > �ܷ�-A�ĵ÷ּ��ɡ�
// ����A�����ߵ���n�أ�����ߵ�n-1�أ���ΪB������һ�ء�

class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int n = possible.size();
        vector<int> pre_sum(n, 0);
        pre_sum[0] = possible[0] == 1 ? 1 : -1;

        for (int i = 1; i < n; i++) {
            if (possible[i] == 1)
                pre_sum[i] = pre_sum[i - 1] + 1;
            else
                pre_sum[i] = pre_sum[i - 1] - 1;
        }
        int sum = pre_sum[n - 1];
        for (int i = 0; i < n; i++) {
            if (pre_sum[i] > sum - pre_sum[i] && i != n - 1)
                return i + 1;
        }
        return -1;
    }
};

int main() {
    Solution st;
    vector<int> possible{ 1,0,1,0 };
    cout << st.minimumLevels(possible) << endl;
    return 0;
}