#include <iostream>
using namespace std;

// n���˿��Ϸɻ�����һ���˿Ͱѻ�ƱŪ���ˣ�Ȼ�������������ߵ�������Լ���λ�ñ�ռ�ˣ���Ҳ�������
// �ʵ�n���˿���ȷ�����Լ�λ���ϵĸ��ʡ�

// ��ʵ���Ǹ������۵�����

class Solution {
public:
    double nthPersonGetsNthSeat(int n) { return n == 1 ? 1 : 0.5; }
};

int main() {
    Solution st;
    cout << st.nthPersonGetsNthSeat(3) << endl;
    return 0;
}