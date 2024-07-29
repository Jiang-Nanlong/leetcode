#include <iostream>
#include <vector>
using namespace std;

// ����һ������[l,r]���ж��������ж������ֲ����������֡�
// ����������ָ�����������⣬֮��������������
// ÿ��������һ������1����ô����1����һ��������

class Solution {
public:

    // ��ʵ����д�����򿴿��������ֶ�����Щ������Щ��ֻ��������������һ����1����һ����һ������
    // ÿһ������������ʵ��������������������ƽ��
    void getnum() {
        for (int i = 1; i < 500; i++) {
            int count = 0;
            for (int j = 1; j < i; j++) {
                if (i % j == 0)
                    count++;
            }
            if (count == 2)
                cout << i << endl;
        }
    }

    int nonSpecialCount(int l, int r) {
        vector<int> prime = getPrime(sqrt(r));
        int res = 0;
        for (int i : prime) {
            int ii = i * i;
            if (ii >= l && ii <= r)
                res++;
        }
        return r - l + 1 - res;
    }

    // ������˹����ɸ����������
    // Ҫ���n���ڵ���������������Ѳ����ڸ���n�����������ı������޳���ʣ�µĶ���������
    vector<int> getPrime(int r) {
        vector<bool> isprime(r + 1, true);
        isprime[0] = false;
        isprime[1] = false;
        for (int i = 2; i * i <= r; i++)  // ����ֻ��Ҫ�㵽����n����
            if (isprime[i]) {
                for (int j = i * i; j <= r; j += i)
                    isprime[j] = false;
            }
        vector<int> res;
        for (int i = 2; i <= r; i++)
            if (isprime[i])
                res.push_back(i);
        return res;
    }

    
};

int main() {
    Solution st;
    st.getnum();
    cout << st.nonSpecialCount(4, 16) << endl;
    return 0; 
}