//
// Created by ������ on 25-1-13.
//
#include <vector>
#include <iostream>
using namespace std;

// ����һ�����󣬾����е�ÿ��Ԫ�ر�ʾ�����λ�ú�Ѫ���仯����������������Ͻǳ�����Ҫ�������½ǣ�ֻ�����һ������ߣ����ĳ��λ�õ�Ѫ����Ϊ0��0���£��ͻ����������������������Ҫ����Ѫ�����Ե����½ǣ�

// ���Ե����룬�����½ǳ����Ժ��Ѫ��Ϊ1�����Կ��԰�dp[i][j]��ʾ�յ���dungeon[i][j]ʱ�����Ѫ����Ϊ�˷������ó�ʼ״̬�����԰�dp������Ϊm+1*n+1ά�ģ����Գ�ʼ״̬�ͱ�Ϊdp[m][n-1]=dp[m-1][n]=1
// ����ĳ��λ�ã������Դ������ұ߹��������±ߣ�ֻ��Ҫ��ע��С���Ǹ����У���Ϊֻ��֤��·������ͨ���У����ö�����ͨ������Ӻ���ǰ�ߵ�(i,j)�Ժ󣬷���Ѫ��<=0��˵����ʱ���Ѫ����Ϊ1����ΪҪ��֤����

class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();

        vector<vector<int> > dp(m + 1, vector<int>(n + 1, INT_MAX));
        dp[m][n - 1] = dp[m - 1][n] = 1;

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int val = min(dp[i + 1][j], dp[i][j + 1]);
                dp[i][j] = max(val - dungeon[i][j], 1);
            }
        }

        return dp[0][0];
    }
};

int main() {
    Solution st;
    vector<vector<int> > dungeon{{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
    cout << st.calculateMinimumHP(dungeon) << endl;

    return 0;
}
