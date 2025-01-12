//
// Created by ������ on 25-1-12.
//
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

// ����һ��m*n�ľ����һ������k�������(0,0)������ֻ�����һ����£����յ���(m-1,n-1)������·�����ܱ�k������·����

// �����������йأ���˰Ѷ�άdp������һά��dp[i][j][v]��ʾ����(i,j)��������Ϊv��·����
// ��˵��ƹ�ʽΪdp[i + 1][j + 1][(v + grid[i][j]) % k] =dp[i][j + 1][v]+dp [i + 1][j][v]
// ��ʼ״̬dp[0][0][grid[0][0]%k]=1

// ����Ϊ�˷����ʼ������dp��ǰ��ά��Ϊm+1��n+1��������ʼ�����ͱ�Ϊdp[0][1][0]=1����dp[1][0][0]=1�������е����롣
// ���Ͻǵ�һ��Ԫ�ض�Ӧ��dp[1][1][grid[0][0]%k]=1���൱�ڰѵ��ƹ�ʽ�е�i=0��j=0,v=0��Ȼ��Ϳ���ȷ����ʼ������

class Solution {
    const int MOD = 1e9 + 7;

public:
    int numberOfPaths(vector<vector<int> > &grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int dp[m + 1][n + 1][k];
        memset(dp, 0, sizeof(dp));
        dp[1][0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int v = 0; v < k; v++) {
                    dp[i + 1][j + 1][(v + grid[i][j]) % k] =
                            (dp[i][j + 1][v] + dp[i + 1][j][v]) % MOD;
                }
            }
        }
        return dp[m][n][0];
    }
};

int main() {
    Solution st;
    vector<vector<int> > grid{{5, 2, 4}, {3, 0, 5}, {0, 7, 2}};
    int k = 3;
    cout << st.numberOfPaths(grid, k) << endl;
    return 0;
}
