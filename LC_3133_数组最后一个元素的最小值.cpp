#include <iostream>
using namespace std;

// ������������n��x������һ������Ϊn�����������飬�����������������Ԫ�صİ�λ��������x
// �����˼·��ʵ�ܼ򵥣�����ĵ�һ��������x��Ȼ��Ҫ�����е�����λ��������x���ͱ��뱣��x�ж�����1λ���䣬ֻ�ı�0λ��
// �����һ�������������е�ÿһ��Ԫ�ض���������չ�����Ա�x��ԭ����0����Щλ����Щλ����ɵ����ֱ���1,2,3...
// ���Ե�n��������ʵ������n-1�Ķ��������x�Ķ�������Ϊ0��λ��

class Solution {
public:
    long long minEnd(int n, int x) {
        short num[64] = { 0 };
        n -= 1;
        for (int i = 0; x; x >>= 1, i++) {
            num[i] = x & 1;
        }

        int i = 0;
        while (n) {
            while (num[i] == 1)
                i++;
            num[i] = n & 1;
            i++;
            n >>= 1;
        }
        long long res = 0;
        for (int i = 63; i >= 0; i--) {
            res = res * 2 + num[i];
        }
        return res;
    }

    long long minEnd1(int n, int x) {
        long long res = x;
        n -= 1;
        int i = 0;
        while (n) {
            while (res >> i & 1)
                i++;
            res |= (long long)(n & 1) << i;
            i++;
            n >>= 1;
        }
        return res;
    }
};

int main() {
    Solution st;
    cout << st.minEnd1(6715154, 7193485) << endl;
    return 0;
}