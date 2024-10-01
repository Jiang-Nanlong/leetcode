#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0;
        unordered_map<char, int> umap;
        for (int i = 0, j = 0; j < s.size(); j++) {
            char c = s[j];
            umap[c]++;
            while (umap[c] > 1) {
                --umap[s[i++]];
            }
            maxlen = max(maxlen, j - i + 1);
        }
        return maxlen;
    }
};
int main() {
    Solution st;
    string s("abcabcbb");
    cout << st.lengthOfLongestSubstring(s) << endl;
    return 0;
}