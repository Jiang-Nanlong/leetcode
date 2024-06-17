#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 给定一个字符串s，s中都是小写字母，把字符串分割成多个平衡子字符串，平衡子字符串也就是串中每种字母出现的次数相同的字符串。
// 返回s最小能分割成多少个平衡子字符串

class Solution {
public:
    // 这是最开始的代码
    // 其实这个题的dp数组和递推公式都还算简单，dp[i]表示以第i个字符结尾的字符串最少能分割成多少个平衡子字符串
    // 递推公式如果[j+1,i]是平衡子字符串，那么dp[i]=dp[j]+1;
    int minimumSubstringsInPartition(string s) {
        vector<int> dp(s.size(), INT_MAX);
        dp[0] = 1;
        for (int i = 1; i < s.size(); i++) { // 从第1个字符开始算起
            int cnt[26] = { 0 };
            int x = 0, y = 0; // x表示子串中有几种字符，y表示字符出现的最高频率
            for (int j = i; j >= 0; j--) {  // 判断[j,i]的子字符串是不是平衡的
                int t = ++cnt[s[j] - 'a'];
                if (t == 1)
                    x++;
                y = max(y, t);
                if (x * y == i - j + 1)  // 如果[j,i]之间是平衡的
                    if (j > 0)
                        dp[i] = min(dp[i], dp[j - 1] + 1);
                    else if (j == 0) // 如果j是0，说明从从0到i都是平衡的，那么dp[i]直接等于1就行
                        dp[i] = 1;
            }
        }
        for (auto i : dp)
            cout << i << " ";
        cout << endl;
        return dp[s.size() - 1];
    }


    // 因为上边的代码的递推公式太复杂，所以有了下边的，把dp数组的长度增加1个
    int minimumSubstringsInPartition1(string s) {
        vector<int> dp(s.size()+1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= s.size(); i++) {  //不过这里讨论的不再是[j,i]，而是[j,i)，其实还是从第0个字符开始算。也就是把以i-1为结尾的字符串的最小分割数存放在dp[i]中
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