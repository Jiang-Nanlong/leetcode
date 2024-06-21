#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

// ͳ��word�еļ��д�д����Сд����ĸ�ĸ���

class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> uset(word.begin(), word.end());
        int count = 0;
        for (auto it = uset.begin(); it != uset.end(); it++) {
            if (*it >= 'a' && *it <= 'z') {
                if (uset.find((*it) - 32) != uset.end())
                    count++;
            }
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