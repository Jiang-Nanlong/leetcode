#include <iostream>
#include <string>
using namespace std;

// ���������ַ���s1��s2���ж�s1�Ƿ�Ϊs2��ĳ���Ӵ����������

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;

        int count[26] = { 0 };
        int n1 = s1.size(), n2 = s2.size();
        for (char c : s1)
            count[c - 'a']++;

        for (int i = 0; i < n1 - 1; i++)
            --count[s2[i] - 'a'];

        for (int i = n1 - 1; i < n2; i++) {
            --count[s2[i] - 'a'];
            if (ismatch(count))
                return true;
            ++count[s2[i - n1 + 1] - 'a'];
        }
        return false;
    }

private:
    bool ismatch(int* p) {
        for (int i = 0; i < 26; i++)
            if (p[i] != 0)
                return false;

        return true;
    }
};

int main() {
    Solution st;
    string s1("horse"), s2("ros");
    cout << boolalpha << st.checkInclusion(s1, s2) << noboolalpha << endl;
    return 0;
}