#include <iostream>
using namespace std;

class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        int res = 0;
        for (int i = 0; i < 2; i++) {
            int count[2] = { red, blue };
            int j, cur = i;
            for (j = 1;; j++) {
                if (count[cur] < j)
                    break;
                count[cur] -= j;
                cur = (cur + 1) % 2;
            }
            res = max(res, j - 1);
        }
        return res;
    }
};

int main() {
    Solution st;
    cout << st.maxHeightOfTriangle(2, 4) << endl;
    return 0;
}