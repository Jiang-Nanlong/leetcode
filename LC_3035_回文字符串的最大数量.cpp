#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ����һ���ַ�������words��words[i]��һ���ַ����������ַ���s1��s2֮��������ַ�����Σ�s1��s2������ͬһ�ַ������������words������ж��ٸ����Ĵ�

// ��ʵ�������൱����words�����������ַ������쳤��Ϊwords��ÿ���ַ������ȵĻ��Ĵ����������๹����ٸ����Ĵ���
// �϶����ȹ��쳤����С�ģ���Ϊ���ĵ��ַ������١�
// �����������ȵ��ַ������м��ַ�����ʹ�ø���Ϊ�������ַ���Ҳ����ʹ�ø���Ϊż�����ַ�������ʹ�ø���Ϊż�����ַ�ʱ����ʹ��һ���ַ����������������
// ����ż�����ȵ��ַ���ʱ��ֻ��ʹ�ø���Ϊż�������ַ���

class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        int num[26];
        memset(num, 0, sizeof(num));
        int n = words.size();
        vector<int> wordLen(n);

        for (int i = 0; i < n; ++i) {  // ͳ�������ַ����ֵĴ������Ѿ�Ҫ�����ÿ���ַ����ĳ���
            string word = words[i];
            wordLen[i] = word.size();
            for (char c : word)
                num[c - 'a']++;
        }

        int odd = 0, even = 0;  // ͳ�����г��������κ�ż�����ַ����ֵĴ���
        for (int i = 0; i < 26; ++i) {
            if (num[i] % 2 == 1) {  // �����ǰ�ַ����������Σ���ô�����Է�Ϊ(num[i]-1)/2���ɶԳ��ֵ�ż����1������
                even += num[i] - 1;
                odd += 1;
            }
            else if (num[i] > 0 && num[i] % 2 == 0) {  // �����ǰ���ִ�����ż���Σ���ô�Ϳ��Էֳ�num[i]/2���ɶԳ��ֵ�ż��
                even += num[i];
            }
        }

        int res = 0;
        sort(wordLen.begin(), wordLen.end());  // ��Ҫ������ַ�����С���������ȹ��쳤��С���ַ���

        for (int len : wordLen) {
            if (len % 2 == 1) {  // �����ǰҪ������ַ�������Ϊ����
                if (odd > 0 && even >= len - 1) {
                    odd -= 1;
                    even -= len - 1;
                    res++;
                }
                else if (odd == 0 && even >= len) {
                    even -= len + 1;
                    odd += 1;
                    res++;
                }
            }
            else {  // �����ǰҪ������ַ�������Ϊż��
                if (even >= len) {
                    even -= len;
                    res++;
                }
            }
        }

        return res;
    }
};

int main() {
    Solution st;
    vector<string> words{ "abbb","ba","aa" };
    cout << st.maxPalindromesAfterOperations(words) << endl;
    return 0;
}