#include <iostream>
#include <vector>
#include <functional>
using namespace std;

// ��LeetCode 3038��࣬����3038ֻ��ɾ��ǰ�������ַ����������ɾ��ǰ�������������������ǰ�������������Ҫ��ÿ��ɾ����ʱ�������ַ���һ��ķ���һ�����������Ĳ���������

// �������ǵݹ�+���仯����

class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));   // ��¼[i,j]�����ڵĲ�����������ʼֵ��Ϊ-1

        function<int(int, int, int)> dfs = [&](int i, int j, int score) {
            if (j - i < 1)  // ��������ڵ��ַ�����һ��
                return 0;

            if (dp[i][j] != -1)  // ����������ϵĲ�����������-1��˵���Ѿ�������ˣ����仯������ֱ��ʹ�þ�����
                return dp[i][j];

            // �±߿�ʼ��������[i,j]�ϵĲ�������
            int res = 0;
            if (nums[i] + nums[i + 1] == score)  // �������ǰ�����ַ��ĺ��������ͬ����ɾ��ǰ�����ַ�
                res = max(res, 1 + dfs(i + 2, j, score));
            if (nums[i] + nums[j] == score)      // ������������ַ��ĺ��������ͬ����ɾ�������ַ�
                res = max(res, 1 + dfs(i + 1, j - 1, score));
            if (nums[j - 1] + nums[j] == score)  // �������������ַ��ĺ��������ͬ����ɾ���������ַ�
                res = max(res, 1 + dfs(i, j - 2, score));

            dp[i][j] = res;  // ������dp[i][j]��ֵ
            return res;
        };

        int a = dfs(2, n - 1, nums[0] + nums[1]);
        int b = dfs(1, n - 2, nums[0] + nums[n - 1]);
        int c = dfs(0, n - 3, nums[n - 2] + nums[n - 1]);
        return max({ a, c, b }) + 1;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 3,2,1,2,3,4 };
    cout << st.maxOperations(nums) << endl;
    return 0;
}