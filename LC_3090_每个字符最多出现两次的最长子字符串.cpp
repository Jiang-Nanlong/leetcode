#include <iostream>
#include <unordered_map>
using namespace std;

//����һ������������

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

    // �ڶ�����
    int maximumLengthSubstring1(string s) {
        unordered_map<char, int> umap;
        int slow = 0, fast = 0;
        int res = 0;
        while (fast < s.size()) {
            umap[s[fast]]++;
            while (umap[s[fast]] > 2) {
                umap[s[slow]]--;
                slow++;
            }
            res = max(res, fast - slow + 1);
            fast++;
        }
        return res;
    }
};

int main() {
    Solution st;
    string s("bcbbbcba");
    cout << st.maximumLengthSubstring(s) << endl;
    cout << st.maximumLengthSubstring1(s) << endl;
    return 0;
}