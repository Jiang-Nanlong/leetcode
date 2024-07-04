#include <iostream>
using namespace std;

// 给定两个变量numBottles表示一开始有多少瓶水，numExchange表示多少个空瓶可以换一瓶水，但是每换完一次，numExchange会加1
// 返回最后总共能喝到多少瓶水

class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int num = numBottles;
        int empty = numBottles;
        while (empty >= numExchange) {
            empty -= numExchange;
            numExchange++;
            num++;
            empty++;
        }
        return num;
    }
};

int main() {
    Solution st;
    int numBottles = 13, numExchange = 6;
    cout << st.maxBottlesDrunk(numBottles, numExchange) << endl;

    return 0;
}