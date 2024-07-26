#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++)
                if (isPrefixAndSuffix(words[i], words[j]))
                    res++;
        }
        return res;
    }

    bool isPrefixAndSuffix(string str1, string str2) {
        if (str1.size() > str2.size())
            return false;

        int n = str1.size(), m = str2.size();
        return str1 == str2.substr(0, n) && str1 == str2.substr(m - n);
    }
};

int main() {
    Solution st;
    vector<string> words{ "a","aba","ababa","aa" };
    cout << st.countPrefixSuffixPairs(words) << endl;
    return 0;
}