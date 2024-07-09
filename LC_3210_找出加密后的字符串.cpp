#include <iostream>
#include <string>
using namespace std;

// �����ַ���s�е�ÿ���ַ�������ߵĵ�k���ַ��滻

class Solution {
public:
    string getEncryptedString(string s, int k) {
        string res(s);
        for (int i = 0; i < s.size(); i++)
            res[i] = s[(i + k) % s.size()];
        return res;
    }

    string getEncryptedString1(string s, int k) {
        k %= s.size();
        string left = s.substr(k);
        string right = s.substr(0, k);
        return left + right;
    }
};

int main() {
    Solution st;
    string s("dart");
    int k = 3;
    cout << st.getEncryptedString(s, k) << endl;
    cout << st.getEncryptedString1(s, k) << endl;
    return 0;
}