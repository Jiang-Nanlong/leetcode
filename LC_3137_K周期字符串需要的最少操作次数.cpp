#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        unordered_map<string, int> umap;
        int count = 0, maxsame = 0;
        for (int i = 0; i < word.size(); i += k) {
            string str = word.substr(i, k);
            umap[str]++;
            count++;
            maxsame = max(maxsame, umap[str]);
        }

        return count - maxsame;
    }
};

int main() {
    Solution st;
    string word("leetcodeleet");
    int k = 4;
    cout << st.minimumOperationsToMakeKPeriodic(word, k) << endl;
    return 0;
}