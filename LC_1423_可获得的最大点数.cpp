#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// 给你一个数组，每次只能从数组的两端取数，一共取k个，返回可以取到的最大和

// 定长滑动窗口，先计算最后k个数，然后依次加入数组开头的数，同时依次减掉滑出窗口的值
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