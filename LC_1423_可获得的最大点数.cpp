#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// ����һ�����飬ÿ��ֻ�ܴ����������ȡ����һ��ȡk�������ؿ���ȡ��������

// �����������ڣ��ȼ������k������Ȼ�����μ������鿪ͷ������ͬʱ���μ����������ڵ�ֵ
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = accumulate(cardPoints.begin() + n - k, cardPoints.end(), 0);
        int res = sum;

        for (int i = 0, j = n - k; i < k; i++, j++) {
            sum += cardPoints[i];
            sum -= cardPoints[j];
            res = max(res, sum);
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> cardPoints{ 1,2,3,4,5,6,1 };
    int k = 3;
    cout << st.maxScore(cardPoints, k) << endl;
    return 0;
}