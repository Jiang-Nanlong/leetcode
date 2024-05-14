#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // 自己写的代码统计，每个单词对应的每个字母的出现次数
    vector<string> commonChars(vector<string>& words) {
        vector<vector<int>> vec(words.size(), vector<int>(26, 0));
        for (int i = 0; i < words.size(); i++) {
            for (char& c : words[i]) {
                vec[i][c - 'a']++;
            }
        }

        vector<string> res;
        for (int i = 0; i < 26; i++) {
            int count = INT_MAX;
            for (int j = 0; j < words.size(); j++) {
                count = min(count, vec[j][i]);
                if (count == 0)
                    break;
            }
            if (count) {
                char c = 'a' + i;
                string s(1, c);
                while (count--)
                    res.push_back(s);
            }
        }
        return res;
    }

    // 答案写法，比第一种方法的空间复杂度要好一些
    vector<string> commonChars1(vector<string>& words) {
        vector<int> vec(26, 0);
        for (char& c : words[0])  //先统计第一个单词中每个字母出现的次数
            vec[c - 'a']++;

        for (int i = 1; i < words.size(); i++) {  //再遍历后续单词
            int hash[26] = { 0 };
            for (char& c : words[i])  //临时统计每个单词中每个子母出现的次数
                hash[c - 'a']++;

            for (int i = 0; i < 26; i++) {
                vec[i] = min(hash[i], vec[i]);
            }
        }

        vector<string> res;
        for (int i = 0; i < 26; i++) {
            if (vec[i]) {
                char c = 'a' + i;
                string s(1, c);
                while (vec[i]--) {
                    res.push_back(s);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<string> words{ "bella","label","roller" };
    vector<string> res = st.commonChars(words);
    for (string& s : res)
        cout << s << "  ";
    cout << endl;

    vector<string> res1 = st.commonChars(words);
    for (string& s : res1)
        cout << s << "  ";
    cout << endl;
    return 0;
}