#include <iostream>
#include <vector>
using namespace std;

// ����һ������hours��Ԫ�ر�ʾ��СʱΪ��λ��ʱ�䣬�ж������ж��ٶ���ɵ�ʱ����24Сʱ��������

class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        int num[24] = { 0 };
        for (int& i : hours) {
            num[i % 24]++;
        }
        long long res = (long long)num[0] * (num[0] - 1) / 2;
        for (int i = 1; i < 12; i++) {
            res += (long long)num[i] * num[24 - i];
        }
        res += (long long)num[12] * (num[12] - 1) / 2;
        return res;
    }
};

int main() {
    Solution st;
    vector<int> hours{ 12,12,30,24,24 };
    cout << st.countCompleteDayPairs(hours) << endl;
    return 0;
}