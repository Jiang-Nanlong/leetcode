#include <iostream>
using namespace std;

// n个乘客上飞机，第一个乘客把机票弄丢了，然后它随便坐，后边的人如果自己的位置被占了，他也随便坐。
// 问第n个乘客正确坐到自己位置上的概率。

// 其实就是个概率论的问题

class Solution {
public:
    double nthPersonGetsNthSeat(int n) { return n == 1 ? 1 : 0.5; }
};

int main() {
    Solution st;
    cout << st.nthPersonGetsNthSeat(3) << endl;
    return 0;
}