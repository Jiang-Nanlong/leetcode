#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

// �ҳ��ַ���s�������ַ���p����λ�ʵ��Ӵ�������¼��Щ��λ���Ӵ�����ʼλ��

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (p.size() > s.size())
            return {};

        int count[26] = { 0 };
        vector<int> res;
        for (char c : p)
            ++count[c - 'a'];

        for (int i = 0; i < p.size() - 1; ++i)
            --count[s[i] - 'a'];

        for (int i = p.size() - 1; i < s.size(); ++i) {
            --count[s[i] - 'a'];
            if (isMatch(count))
                res.push_back(i - p.size() + 1);
            ++count[s[i - p.size() + 1] - 'a'];
        }
        return res;
    }
    // �о��ϱ����ֶ����������ڵ�ʱ�临�Ӷȸ��ߣ�����ÿ��s�е�Ԫ�ض�Ҫ�ж�һ����������ǲ���һ�¡�
  // �����ò������������ڸ���
    vector<int> findAnagrams1(string s, string p) {
        int count[26];
        memset(count, 0, sizeof(count));
        for (char c : p)
            ++count[c - 'a'];

        vector<int> res;
        int n = s.size();
        for (int i = 0, j = 0; j < n; j++) {
            char c = s[j];
            --count[c - 'a'];
            while (count[c - 'a'] < 0) {
                ++count[s[i++] - 'a'];
            }

            // ����ط���Ϊʲôj-i+1==p.size()��ʱ���˵�����ҵ�����λ�����أ�ע����С���ڵ�������ֻ�е�������ĳ���ʵĳ��ִ�������p�еĳ��ִ�������С���ڣ�
            // ��ô�����е�ÿ���ʵĳ��ִ�����С�ڵ���p�г��ֵĴ����������е���ĸ�����ֶ���ͬ����ôֻ������λ���ˡ�
            if (j - i + 1 == p.size())
                res.push_back(i);
        }
        return res;
    }

private:
    bool isMatch(int* p) {
        for (int i = 0; i < 26; i++)
            if (p[i] != 0)
                return false;

        return true;
    }
};

int main() {
    Solution st;
    string s("cbaebabacd"), p("abc");
    vector<int> res = st.findAnagrams(s, p);
    for (int i : res)
        cout << i << " ";
    cout << endl;
    return 0;
}