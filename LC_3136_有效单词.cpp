#include <iostream>
#include <unordered_set>
using namespace std;

// һ����Ч�ĵ��ʱ������������ĸ��ɣ���ĸ��Сд���У��������������ַ������ٰ���һ��Ԫ��һ��������

class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3)
            return false;
        unordered_set<char> yuanyin{ 'a', 'e', 'i', 'o', 'u',
                                    'A', 'E', 'I', 'O', 'U' };
        bool y = false, f = false;
        for (char c : word) {
            if (c >= '0' && c <= '9')
                continue;
            else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                if (yuanyin.find(c) != yuanyin.end())
                    y = true;
                else
                    f = true;
            }
            else
                return false;
        }
        return y && f;
    }
};

int main() {
    Solution st;
    string word("234Adas");
    cout << boolalpha << st.isValid(word) << noboolalpha << endl;
    return 0;
}