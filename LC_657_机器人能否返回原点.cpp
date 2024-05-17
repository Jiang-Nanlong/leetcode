#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int count[4] = { 0 };
        for (char& c : moves) {
            if (c == 'U')
                count[0]++;
            else if (c == 'D')
                count[1]++;
            else if (c == 'L')
                count[2]++;
            else
                count[3]++;
        }
        if (count[0] == count[1] && count[2] == count[3])
            return true;
        return false;
    }

    bool judgeCircle1(string moves) {
        int x = 0, y = 0;
        for (char& c : moves) {
            if (c == 'U')
                y++;
            else if (c == 'D')
                y--;
            else if (c == 'L')
                x--;
            else
                x++;
        }
        if (x == 0 && y == 0)
            return true;
        return false;
    }
};

int main() {
    Solution st;
    string moves = "UD";
    cout << boolalpha << st.judgeCircle(moves) << endl;
    cout << st.judgeCircle1(moves) << noboolalpha << endl;
    return 0;
}