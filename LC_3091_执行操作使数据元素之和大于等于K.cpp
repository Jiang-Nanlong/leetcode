#include <iostream>
using namespace std;

class Solution {
public:
    int minOperations(int k) {
        if (k == 1)
            return 0;
        int res = INT_MAX;
        for (int i = 1; i <= k; i++) {  // ��kƽ����Ϊi��
            int count = k / i;
            if (k % i != 0)  // ���k/i���������Ͱѽ����һ������������ȡ��
                count++;
            res = min(res, count - 1 + i - 1);  // ��һ������Ϊk/i����ȡ����Ҫcount-1����������ٱ��i����ͬ�ģ���Ҫi-1��
        }
        return res;
    }
};

int main() {
    Solution st;
    cout << st.minOperations(11) << endl;
    return 0;
}