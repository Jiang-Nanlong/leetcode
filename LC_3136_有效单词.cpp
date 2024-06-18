#include <iostream>
#include <unordered_set>
using namespace std;

// 一个有效的单词必须由数组和字母组成，字母大小写都行，不能少于三个字符，至少包含一个元音一个辅音。

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