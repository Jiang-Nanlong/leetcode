#include <iostream>
using namespace std;

// ���һ�����ܱ����ĸ�λ֮���������ͷ��ظ�λ֮�ͣ����򷵻�-1

class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int y = x;
        int num = 0;
        while (y) {
            num += y % 10;
            y /= 10;
        }
        if (x % num == 0) return num;
        return -1;
    }
};

int main() {
    Solution st;
    cout << st.sumOfTheDigitsOfHarshadNumber(18) << endl;
    return 0;
}