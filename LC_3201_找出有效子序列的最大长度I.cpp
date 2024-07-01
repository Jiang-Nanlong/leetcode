#include <iostream>
#include <vector>
using namespace std;

// ����һ���������飬�ҳ�һ����Ч��������sub��������Ԫ��֮�Ͷ�kȡ���Ľ������ͬ�������k��2
// Ҳ����(a+b)%k==(b+c)%k  ==>  a%k==c%k
// dp[i][j]��ʾ��iΪa%k����jΪb%k��������еĳ��ȣ����������ǰԪ�ض�k������Ϊj����ôdp[i][j]=dp[j][i]+1.

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        vector<vector<int>> dp(2, vector<int>(2, 0));
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i] % 2;
            for (int j = 0; j < 2; j++) {
                dp[j][x] = dp[x][j] + 1;
                res = max(res, dp[j][x]);
            }
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 1,2,3,4 };
    cout << st.maximumLength(nums) << endl;
    return 0;
}