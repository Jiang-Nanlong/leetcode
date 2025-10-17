#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (words.empty() || words[0].size() > s.size())
            return res;

        int word_len = words[0].size();
        int num_word = words.size();
        int total_len = word_len * num_word;

        unordered_map<string, int> ump;
        for (string& word : words)
            ump[word]++;

        for (int i = 0; i < word_len; i++) {
            int left = i;
            int word_found = 0;
            unordered_map<string, int> curr;
            for (int right = i; right <= s.size() - word_len;
                 right += word_len) {
                string substr = s.substr(right, word_len);
                if (ump.find(substr) != ump.end()) {
                    curr[substr]++;
                    word_found++;

                    while (curr[substr] > ump[substr]) {
                        string remove_substr = s.substr(left, word_len);
                        curr[remove_substr]--;
                        word_found--;
                        left += word_len;
                    }

                    if (word_found == num_word) {
                        res.push_back(left);
                        string remove_substr = s.substr(left, word_len);
                        curr[remove_substr]--;
                        word_found--;
                        left += word_len;
                    }
                } else {
                    curr.clear();
                    word_found = 0;
                    left = right + word_len;
                }
                 }
        }
        return res;
    }
};

int main() {
    Solution st;
    string s("barfoothefoobarman");
    vector<string> words{"foo","bar"};
    vector<int> res = st.findSubstring(s, words);
    for (int i:res)
        cout << i << endl;
    return 0;
}