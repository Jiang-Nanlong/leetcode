#include <iostream>
#include <string>
using namespace std;

// ����һ���ַ�������ʾһ�����֣�ɾ���ַ����еļ����ַ���ʣ�µ��ַ���ɵ��ַ������Ա�25������������С��ɾ��������
// �ַ���������ǰ��0
// �ܱ�25���������ֶ�����00,25,50,75��β�����Ե�������ַ���������ҵ���0������5��0.����ҵ���5��������2��7

class Solution {
public:
    int minimumOperations(string num) {
        int n = num.size();
        bool find_0 = false, find_5 = false;
        for (int i = n - 1; i >= 0; i--) {
            char c = num[i];
            if (c == '0') {
                if (find_0)
                    return n - i - 2;
                else
                    find_0 = true;
            }
            if (c == '2' || c == '7')
                if (find_5)
                    return n - i - 2;

            if (c == '5') {
                if (find_0)
                    return n - i - 2;
                find_5 = true;
            }
        }
        return n - find_0;
    }
};

int main() {
    Solution st;
    string num("2245047");
    cout << st.minimumOperations(num) << endl;
    return 0;
}