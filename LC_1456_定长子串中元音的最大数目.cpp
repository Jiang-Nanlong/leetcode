#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> uset{ 'a', 'e', 'i', 'o', 'u' };
        int count = 0, res = 0;
        for (int i = 0, j = 0; j < s.size(); j++) {
            if (uset.find(s[j]) != uset.end())
                count++;
            if (j - i + 1 > k) {
                if (uset.find(s[i++]) != uset.end())
                    count--;
            }
            res = max(res, count);
        }
        return res;
    }
};

int main() {
    Solution st;
    string s("abciiidef");
    int k = 3;
    cout << st.maxVowels(s, k) << endl;
    return 0;
}