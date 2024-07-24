#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string losingPlayer(int x, int y) {
        y /= 4;
        int t = min(x, y);
        if (t % 2 == 0)
            return "Bob";
        else
            return "Alice";
    }
};

int main() {
    Solution st;
    int x = 2, y = 7;
    cout << st.losingPlayer(x, y) << endl;
    return 0;
}