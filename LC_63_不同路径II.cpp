#include <iostream>
#include <vector>
using namespace std;

//��������һ������������һ��Ķ�ά���������ϰ���ҿ�ʼ�������ϰ����Ӱ�쵽�������λ�ú����ұߺ��±ߵ�λ�ã�����ô�����������
//��������ֻͨҪ���ϰ���λ�õ�dp����д��0���У�
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if (obstacleGrid[m - 1][n - 1] == 1 || obstacleGrid[0][0] == 1) return 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < n && obstacleGrid[0][i] == 0; i++) dp[0][i] = 1;
        for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++) dp[i][0] = 1;
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) continue;
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }

    //�ڶ�����
    int uniquePathsWithObstacles1(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 1));
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0;

        bool flag = false;
        for (int i = 0; i < m; i++) {
            if (obstacleGrid[i][0] == 1)
                flag = true;
            if (flag) dp[i][0] = 0;
        }

        flag = false;
        for (int i = 0; i < n; i++) {
            if (obstacleGrid[0][i] == 1)
                flag = true;
            if (flag) dp[0][i] = 0;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }

    //�Ż�dp�����Ժ��
    int uniquePathsWithObstacles2(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0;

        vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            if (i == 0)
                dp[i] = 1;
            else if (obstacleGrid[0][i] == 1)
                dp[i] = 0;
            else
                dp[i] = dp[i - 1];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                //���ѭ����߲��ÿ��ǵ�0��λ����ʲô����0��λ��ֱ������һ��λ�ù�������������ֻ��Ҫ�ж��ǲ����ϰ�������ǲ��ǵ�0��Ԫ�ؾ���
                if (obstacleGrid[i][j] == 1)
                    dp[j] = 0;
                else if (j != 0)
                    dp[j] += dp[j - 1];
            }
        }
        return dp[n - 1];
    }
};

int main() {
    Solution st;
    vector<vector<int>> obstacleGrid{ {0,0,0},{0,1,0},{0,0,0} };
    cout << st.uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}