#include <iostream>
#include <string>
using namespace std;

// 给定一个仅有a,b,c三种字符组成的字符串和一个非负整数k，每次操作可以从字符串的任意一端取走一个字符，必须把每种字符至少取走k个，
// 返回最少的操作次数

class Solution {
public:
    // 这是我自己做的，还是按着原来的思路，题目中说每种字符最少取k个，也就是窗口内的字符最多有n-k个
    int takeCharacters(string s, int k) {
        int count[3];
        memset(count, 0, sizeof(count));
        for (char c : s)
            count[c - 'a']++;

        if (count[0] < k || count[1] < k || count[2] < k)
            return -1;
        count[0] -= k;
        count[1] -= k;
        count[2] -= k;

        int cnt[3];
        int maxlen = 0;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0, j = 0; j < s.size(); j++) {
            int val = s[j] - 'a';
            cnt[val]++;
            while (cnt[val] > count[val]) {
                cnt[s[i++] - 'a']--;
            }
            maxlen = max(maxlen, j - i + 1);
        }

        return s.size() - maxlen;
    }


    // 灵茶山艾府的做法，更巧妙
    int takeCharacters1(string s, int k) {
        int count[3];
        memset(count, 0, sizeof(count));
        for (char c : s)
            count[c - 'a']++;

        if (count[0] < k || count[1] < k || count[2] < k)
            return -1;

        int maxlen = 0;
        for (int i = 0, j = 0; j < s.size(); j++) {
            int val = s[j] - 'a';
            count[val]--;  // 这里把进入窗口的元素都减一，也就是直接把窗口外的元素作为要出现的元素
            // 然后题意就可以理解为窗口外的每种元素都至少保留k个。
            while (count[val] < k) {
                count[s[i++] - 'a']++;
            }
            maxlen = max(maxlen, j - i + 1);
        }

        return s.size() - maxlen;
    }
};

int main() {
    Solution st;
    string s("aabaaaacaabc");
    int k = 2;
    cout << st.takeCharacters(s, k) << endl;
    cout << st.takeCharacters1(s, k) << endl;
    return 0;
}