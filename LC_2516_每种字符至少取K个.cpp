#include <iostream>
#include <string>
using namespace std;

// ����һ������a,b,c�����ַ���ɵ��ַ�����һ���Ǹ�����k��ÿ�β������Դ��ַ���������һ��ȡ��һ���ַ��������ÿ���ַ�����ȡ��k����
// �������ٵĲ�������

class Solution {
public:
    // �������Լ����ģ����ǰ���ԭ����˼·����Ŀ��˵ÿ���ַ�����ȡk����Ҳ���Ǵ����ڵ��ַ������n-k��
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


    // ���ɽ������������������
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
            count[val]--;  // ����ѽ��봰�ڵ�Ԫ�ض���һ��Ҳ����ֱ�ӰѴ������Ԫ����ΪҪ���ֵ�Ԫ��
            // Ȼ������Ϳ������Ϊ�������ÿ��Ԫ�ض����ٱ���k����
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