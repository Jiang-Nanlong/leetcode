#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int x1 = coordinate1[0] - 'a' + 1;
        int x2 = coordinate2[0] - 'a' + 1;
        int y1 = coordinate1[1] - '0';
        int y2 = coordinate2[1] - '0';

        if ((x1 % 2 == 1 && x2 % 2 == 1) || (x1 % 2 == 0 && x2 % 2 == 0)) {
            if (y1 % 2 == y2 % 2)
                return true;
            else
                return false;
        }
        else if (x1 % 2 || x2 % 2) {
            if (y1 % 2 == y2 % 2)
                return false;
            else
                return true;
        }
        return false;
    }
};

int main() {
    Solution st;
    string coordinate1("a1"), coordinate2("c3");
    cout << boolalpha << st.checkTwoChessboards(coordinate1, coordinate2) << noboolalpha << endl;
    return 0;
}