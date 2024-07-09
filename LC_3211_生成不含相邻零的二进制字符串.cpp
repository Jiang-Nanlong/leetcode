#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ����һ��������n���������еĳ���Ϊn���Ҳ�������������0�������ַ�����
// 1<=n<=18
// n�����ݷ�Χ��С��ֱ�ӻ�����

class Solution {
public:
    vector<string> res;
    vector<string> validStrings(int n) {
        res.clear();
        string s;
        backtracking(n, s);
        return res;
    }

    void backtracking(int n, string& s) {
        if (s.size() == n) {
            res.push_back(s);
            return;
        }

        s.push_back('1');  // ����1��ʱ�����жϣ�1�϶��ǿ��Բ����
        backtracking(n, s);
        s.pop_back();

        if (s.empty() || s.back()=='1') {  // ���sΪ0������ĩβԪ��Ϊ1��������ĩβ����0
            s.push_back('0');
            backtracking(n, s);
            s.pop_back();
        }
    }
    bool isValid(string& s) {  // ���԰Ѳ���0ʱ����ж����д��if(isValid(s))
        if (s.empty())
            return true;

        for (int i = 0; i < s.size() - 1; i++)
            if (s[i] == '0' && s[i + 1] == '0')
                return false;

        if (s.back() == '0')
            return false;

        return true;
    }
};

int main() {
    Solution st;
    vector<string> res = st.validStrings(3);
    for (auto& s : res)
        cout << s << endl;
    return 0;
}