#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// ����һ��ֻ����Q,W,E,R�����ַ����ַ���������ѡ��һ���Ӵ������е������޸ģ�ʹ������ַ������޸Ľ��Ϊÿ���ַ���������ͬ��
// Ҳ����ÿ���ַ��ĸ�����ռ�����ַ�����1/4������ʵ�������ַ���Ҫ�滻������Ӵ��ĳ��ȡ�

// ���ǻ��������⣬�����о���������С���ڵ������Ƚ�����
// �����ʵ���ÿ����Ӵ��ڵ�����Ӧ����ô�䣬��ΪֻҪ������ÿ���ַ�������������������1/4���С�
// ���Է����룬����Ӵ����ĳ���ַ���������������1/4��ô�����Ӵ�����ô�ı䶼������һ������Ҫ����ַ�����
// ����ֻҪ�Ӵ�֮���ÿ���ַ�������������1/4�����ǾͿ��Գ����������Ӵ���

class Solution {
public:
    int balancedString(string s) {
        int n = s.size() / 4;
        unordered_map<char, int> uamp;
        for (char c : s)
            uamp[c]++;
        if (uamp['Q'] == n && uamp['W'] == n && uamp['E'] == n &&
            uamp['R'] == n)
            return 0;

        int minlen = INT_MAX;
        for (int i = 0, j = 0; j < s.size(); j++) {
            uamp[s[j]]--;
            while (uamp['Q'] <= n && uamp['W'] <= n && uamp['E'] <= n &&
                uamp['R'] <= n) {
                minlen = min(minlen, j - i + 1);
                uamp[s[i++]]++;
            }
        }
        return minlen;
    }
};

int main() {
    Solution st;
    string s("WWEQERQWQWWRWWERQWEQ");
    cout << st.balancedString(s) << endl;
    return 0;
}