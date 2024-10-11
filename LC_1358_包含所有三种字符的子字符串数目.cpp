#include <iostream>
#include <string>
using namespace std;

// ����һ���ַ�����������a,b,c�����ַ�������a,b,c�����ٳ���һ�ε����ַ�������Ŀ����ͬ�ַ������Ρ�

class Solution {
public:
    int numberOfSubstrings(string s) {
        int count[3];
        memset(count, 0, sizeof(count));
        int res = 0;
        for (int i = 0, j = 0; j < s.size(); j++) {
            // �൱�ڹ̶������Ҷ˵㣬�ƶ���˵㣬ֱ������������ʱ����ô����˵�����������ַ����뵽�����к�
            // �����������������ַ�����
            count[s[j] - 'a']++;
            while (count[0] > 0 && count[1] > 0 && count[2] > 0)
                count[s[i++] - 'a']--;
            res += i;
        }
        return res;
    }
};

int main() {
    Solution st;
    string s("aaacb");
    cout << st.numberOfSubstrings(s) << endl;
    return 0;
}