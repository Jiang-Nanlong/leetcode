#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int score = 0, n = tokens.size();
        int i = 0, j = n - 1;
        while (i <= j) {
            if (power >= tokens[i]) {
                score++;
                power -= tokens[i];
                i++;
            }
            else {
                if (i < j && score > 0) {
                    power += tokens[j];
                    score--;
                    j--;
                }
                else
                    break;
            }
        }
        return score;
    }
};

int main() {
    Solution st;
    vector<int> tokens{ 100,200,300,400 };
    int power = 200;
    cout << st.bagOfTokensScore(tokens, power) << endl;
    return 0;
}