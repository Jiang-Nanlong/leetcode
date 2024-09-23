#include <iostream>
#include <vector>
#include <string>
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