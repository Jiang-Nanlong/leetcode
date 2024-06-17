#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ����һ���ַ���s��s�ж���Сд��ĸ�����ַ����ָ�ɶ��ƽ�����ַ�����ƽ�����ַ���Ҳ���Ǵ���ÿ����ĸ���ֵĴ�����ͬ���ַ�����
// ����s��С�ָܷ�ɶ��ٸ�ƽ�����ַ���

class Solution {
public:
    // �����ʼ�Ĵ���
    // ��ʵ������dp����͵��ƹ�ʽ������򵥣�dp[i]��ʾ�Ե�i���ַ���β���ַ��������ָܷ�ɶ��ٸ�ƽ�����ַ���
    // ���ƹ�ʽ���[j+1,i]��ƽ�����ַ�������ôdp[i]=dp[j]+1;
    int minimumSubstringsInPartition(string s) {
        vector<int> dp(s.size(), INT_MAX);
        dp[0] = 1;
        for (int i = 1; i < s.size(); i++) { // �ӵ�1���ַ���ʼ����
            int cnt[26] = { 0 };
            int x = 0, y = 0; // x��ʾ�Ӵ����м����ַ���y��ʾ�ַ����ֵ����Ƶ��
            for (int j = i; j >= 0; j--) {  // �ж�[j,i]�����ַ����ǲ���ƽ���
                int t = ++cnt[s[j] - 'a'];
                if (t == 1)
                    x++;
                y = max(y, t);
                if (x * y == i - j + 1)  // ���[j,i]֮����ƽ���
                    if (j > 0)
                        dp[i] = min(dp[i], dp[j - 1] + 1);
                    else if (j == 0) // ���j��0��˵���Ӵ�0��i����ƽ��ģ���ôdp[i]ֱ�ӵ���1����
                        dp[i] = 1;
            }
        }
        for (auto i : dp)
            cout << i << " ";
        cout << endl;
        return dp[s.size() - 1];
    }


    // ��Ϊ�ϱߵĴ���ĵ��ƹ�ʽ̫���ӣ����������±ߵģ���dp����ĳ�������1��
    int minimumSubstringsInPartition1(string s) {
        vector<int> dp(s.size()+1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= s.size(); i++) {  //�����������۵Ĳ�����[j,i]������[j,i)����ʵ���Ǵӵ�0���ַ���ʼ�㡣Ҳ���ǰ���i-1Ϊ��β���ַ�������С�ָ��������dp[i]��
            int cnt[26] = { 0 };
            int x = 0, y = 0;
            for (int j = i - 1; j >= 0; j--) {  
                int t = ++cnt[s[j] - 'a'];
                if (t == 1)
                    x++;
                y = max(y, t);
                if (x * y == i - j)
                    dp[i] = min(dp[i], dp[j] + 1);
            }
        }
        for (auto i : dp)
            cout << i << " ";
        cout << endl;
        return dp[s.size()];
    }
};

int main() {
    Solution st;
    string s("abababaccddb");
    cout << st.minimumSubstringsInPartition(s) << endl;
    cout << st.minimumSubstringsInPartition1(s) << endl;
    return 0;
}