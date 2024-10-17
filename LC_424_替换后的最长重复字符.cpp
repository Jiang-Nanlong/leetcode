#include <iostream>
#include <vector>
using namespace std;

// ����һ���ַ���s��һ���Ǹ�����k�����԰��ַ����е������ַ��������޸ģ�����޸�k�Σ����ذ���ͬ���ַ�����Ӵ��ĳ���

// ���ǻ��������⣬
// ͳ�ƴ�������ͬ�ַ��������ִ�������������Ӵ��ĳ��ȼ�ȥ��������ִ����Ľ������k��˵����ʱҪ��С����


class Solution {
public:
    int characterReplacement(string s, int k) {
        int count[26];
        memset(count, 0, sizeof(count));

        int res = 0;
        int mx = 0;
        for (int i = 0, j = 0; j < s.size(); j++) {
            mx = max(mx, ++count[s[j] - 'A']);
            while (j - i + 1 - mx > k) {
                mx = max(mx, --count[s[i++] - 'A']);
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};

int main() {
    Solution st;
    string s("KRSCDCSONAJNHLBMDQGIFCPEKPOHQIHLTDIQGEKLRLCQNBOHNDQGHJPNDQPERNFSSSRDEQLFPCCCARFMDLHADJADAGNNSBNCJQOF");
    int k = 4;
    cout << st.characterReplacement(s, k) << endl;
    return 0;
}