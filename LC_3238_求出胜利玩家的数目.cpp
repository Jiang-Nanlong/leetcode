#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        vector<vector<int>> score(n, vector<int>(11, 0));
        for (int i = 0; i < pick.size(); i++) {
            score[pick[i][0]][pick[i][1]]++;
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= 10; j++) {
                if (score[i][j] > i) {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution st;
    int n = 4;
    vector<vector<int>> pick{ {0,0},{1,0},{1,0},{2,1},{2,1},{2,0} };
    cout << st.winningPlayerCount(n, pick) << endl;
    return 0;
}