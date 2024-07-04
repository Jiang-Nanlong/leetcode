#include <iostream>
using namespace std;

// ������������numBottles��ʾһ��ʼ�ж���ƿˮ��numExchange��ʾ���ٸ���ƿ���Ի�һƿˮ������ÿ����һ�Σ�numExchange���1
// ��������ܹ��ܺȵ�����ƿˮ

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