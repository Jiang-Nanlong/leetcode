#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //�Լ�д�ģ�����
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] >= nums[i]) {
                dp[i] = dp[i - 1] + 1;
            }
            else
                dp[i] = dp[i - 1];
        }
        return dp[n - 1];
    }

    //�Լ�д�ģ����ԣ�����ʹ��Ѿ������ˣ�������dp���飬һ��ά��[0,i]�е��������еĸ�����һ��ά���������ʱ�������и���
    int findNumberOfLIS1(vector<int>& nums) {  // [3,1,2]������
        int n = nums.size();
        vector<int> dp(n, 1), len(n, 1);
        int maxlen = 1, index = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] >= nums[i]) {
                dp[i] = dp[i - 1] + 1;
            }
            else
                dp[i] = dp[i - 1];

            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    len[i] = max(len[i], len[j] + 1);
                }
            }
            if (len[i] >= maxlen) {
                maxlen = len[i];
                index = i;
            }
        }
        return dp[index];
    }

    //��������¼�Ĵ�
    int findNumberOfLIS2(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), len(n, 1);  // dp[i]��ʾ[0,i]������������еĸ�����len[i]��ʾ[0,i]������������еĳ���
        int maxlen = 1;  // ��¼��ĵ��������еĳ���
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {  
                    if (len[j] + 1 > len[i]) {  // ���[0,j]���������������еĳ���+1���ڵ�ǰ[0,i]���������������еĳ��ȣ�˵���ҵ���һ�������ĵ���������
                        dp[i] = dp[j];          // ��ʱ[0,i]������������еĸ����ͺ�[0,j]������������еĸ���һ��
                    }
                    else if (len[j] + 1 == len[i]) {  // ���[0,j]�ϵ�����������еĳ���+1�͵�ǰ[0,i]�ϵ�����������еĳ���һ����˵�����ҵ���һ����[0,i]������������г���һ����������
                        dp[i] += dp[j];               // ����[0,i]������������еĸ�����Ӧ�ü���[0,j]��������еĸ���
                    }
                    len[i] = max(len[i], len[j] + 1);
                }
            }
            maxlen = max(maxlen, len[i]);  // ��¼������������еĳ���
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (len[i] == maxlen)
                res += dp[i];
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 1,3,5,4,7 };
    cout << st.findNumberOfLIS2(nums) << endl;
    return 0;
}