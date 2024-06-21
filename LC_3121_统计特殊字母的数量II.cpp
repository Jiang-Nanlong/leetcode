#include <iostream>
#include <string>
using namespace std;

// 如果一个小写字母c都出现在它的大写字母之前，就说c是一个特殊字母。统计特殊字母的个数。
// 其实就是统计每一种小写字母最后一次出现的位置，和对应大写字母第一次出现的位置。判断小写字母的最后出现位置是不是小于大写字母的第一次出现位置。

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