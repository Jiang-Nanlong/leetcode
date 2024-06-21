#include <iostream>
#include <string>
using namespace std;

// ���һ��Сд��ĸc�����������Ĵ�д��ĸ֮ǰ����˵c��һ��������ĸ��ͳ��������ĸ�ĸ�����
// ��ʵ����ͳ��ÿһ��Сд��ĸ���һ�γ��ֵ�λ�ã��Ͷ�Ӧ��д��ĸ��һ�γ��ֵ�λ�á��ж�Сд��ĸ��������λ���ǲ���С�ڴ�д��ĸ�ĵ�һ�γ���λ�á�

class Solution {
public:
    int numberOfSpecialChars(string word) {
        int smalllastappear[26], bigfirstappear[26];
        memset(smalllastappear, 200002, sizeof(smalllastappear));
        memset(bigfirstappear, -1, sizeof(bigfirstappear));

        for (int i = 0; i < word.size(); i++) {
            if (word[i] >= 'a' && word[i] <= 'z') {
                smalllastappear[word[i] - 'a'] = i;
            }
            else {
                if (bigfirstappear[word[i] - 'A'] == -1)
                    bigfirstappear[word[i] - 'A'] = i;
            }
        }

        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (smalllastappear[i] < bigfirstappear[i])
                count++;
        }
        return count;
    }
};

int main() {
    Solution st;
    string s("aaAbcBC");
    cout << st.numberOfSpecialChars(s) << endl;
    return 0;
}