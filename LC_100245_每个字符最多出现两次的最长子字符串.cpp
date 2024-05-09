#include <iostream>
#include <unordered_map>
using namespace std;

//ÓÖÊÇÒ»µÀ»¬¶¯´°¿ÚÌâ

class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> umap;
        int maxLength = 0;
        for (int fast = 0, slow = 0; fast < s.size(); fast++) {
            umap[s[fast]]++;
            while (umap[s[fast]] > 2) {
                if (umap[s[slow]]-- == 0)
                    umap.erase(s[slow]);
                slow++;
            }
            maxLength = max(maxLength, fast - slow + 1);
        }
        return maxLength;
    }
};

int main() {
    Solution st;
    string s("bcbbbcba");
    cout << st.maximumLengthSubstring(s) << endl;
    return 0;
}
