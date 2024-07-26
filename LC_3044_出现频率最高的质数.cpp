#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int mostFrequentPrime(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        unordered_map<int, int> umap;
        int dir[8][2]{ 0, 1, 1, 0, -1, 0, 0, -1, 1, 1, -1, -1, 1, -1, -1, 1 };

        auto get = [&](int i, int j) {
            for (int k = 0; k < 8; k++) {
                int sum = 0;
                for (int x = i, y = j; x >= 0 && x < m && y >= 0 && y < n; x += dir[k][0], y += dir[k][1]) {
                    sum = sum * 10 + mat[x][y];
                    if (sum > 10 && isPrime(sum))
                        umap[sum]++;
                }
            }
            };

        int res = -1, fre = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                get(i, j);

        for (auto it = umap.begin(); it != umap.end(); it++) {
            cout << it->first << ":" << it->second << endl;
            if (it->second == fre)
                res = max(res, it->first);
            if (it->second > fre) {
                fre = it->second;
                res = it->first;
            }
        }
        return res;
    }
    bool isPrime(int n) {
        if (n <= 1)
            return false;
        if (n <= 3)
            return true;
        if (n % 2 == 0 || n % 3 == 0)
            return false;

        int sqrtn = sqrt(n);
        for (int i = 3; i <= sqrtn; i++)
            if (n % i == 0)
                return false;

        return true;
    }
};

int main() {
    Solution st;
    vector<vector<int>> mat{ {1,1},{9,9},{1,1} };
    cout << st.mostFrequentPrime(mat) << endl;
    return 0;
}