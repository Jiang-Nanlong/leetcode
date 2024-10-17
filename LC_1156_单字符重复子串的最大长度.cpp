#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int maxRepOpt1(string text) {
        int count[26];
        memset(count, 0, sizeof(count));
        for (char c : text)
            count[c - 'a']++;

        int maxlen = 0;
        int i = 0;
        while (i < text.size()) {
            int j = i;
            while (j < text.size() && text[i] == text[j])  // ��ͳ��ǰ�����ͬ��Ԫ��
                j++;

            int k = j + 1;  // �����м䲻��ͬ��Ԫ��
            while (k < text.size() && text[i] == text[k])  // ��ͳ�ƺ�����ͬ��Ԫ��
                k++;

            if (k - i - 1 < count[text[i] - 'a'])  // ����Ӵ�����ͬ��Ԫ�ظ���С�������ַ����и�Ԫ�صĸ�������ô�Ϳ������Ӵ�֮��ѡһ������Ԫ���滻�м䲻ͬ��Ԫ��
                maxlen = max(maxlen, k - i);
            else
                maxlen = max(maxlen, k - i - 1);   // ����Ӵ�����ͬ��Ԫ�ظ����Ѿ��������ַ����и�Ԫ�صĸ�������ô��ֻ�������һ��Ԫ���滻�м䲻ͬ��Ԫ��
            i = j;
        }
        return maxlen;
    }
};

int main() {
    Solution st;
    string text("aaabaaa");
    cout << st.maxRepOpt1(text) << endl;
    return 0;
}