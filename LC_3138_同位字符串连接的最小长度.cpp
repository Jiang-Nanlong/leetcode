#include <iostream>
#include <array>
using namespace std;

// ����һ���ַ������ж��ǲ�����һϵ�е�ͬλ�ַ�����ɣ�ͬλ�ַ��������ַ�������ͬ�������в�һ����ͬ���ַ���
// ����ͬλ�ַ�������С���ȡ�
// ���һ���ַ������ɶ��ͬλ�ַ�����ɣ���ôͬλ�ַ����ĳ���һ���������ַ������ȵ����ӣ����ַ������100000��100000�������Ӹ���������Ϊ83160����128�����ӣ�
// ���Կ���ֱ��ö�����п��ܵ�ͬλ�ַ����ĳ��ȣ�Ȼ���ж������ַ����ǲ��ǿ��Էָ�ɶ��ͬλ�ַ���

class Solution {
public:
    int minAnagramLength(string s) {
        int n = s.size();
        auto check = [&](int len) {
            array<int, 26> num{};
            for (int j = 0; j < len; j++)
                num[s[j] - 'a']++;

            for (int j = len; j < n; j += len) {
                array<int, 26> num1{};
                for (int k = j; k < j + len; k++) {
                    num1[s[k] - 'a']++;
                }
                if (num1 != num)
                    return false;
            }
            return true;
            };
        for (int len = 1; len <= n / 2; len++) {
            if (n % len == 0 && check(len))
                return len;
        }
        return n;
    }
};


int main() {
    Solution st;
    string s("jjj");
    cout << st.minAnagramLength(s) << endl;
    return 0;
}