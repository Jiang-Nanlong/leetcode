#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 给定一个字符串，仅包含T或F，和一个正整数k，依次操作中可以把字符串中的字符T修改为F 或 把F修改为T，问在不超过k次操作的情况下，最大连续的T或F的数目。

// 这是一个滑动窗口题，统计窗口内一种字符的数量，比如说F，当F的数量小于等于k时，说明在当前窗口内的F可以在k次操作内都变成T，这时候T的最大连续数量就是right-left+1.
// 如果窗口内F的数量超过k时，说明不能在k次操作中把窗口内的F都变成T，这时候就要缩小窗口。
// 当统计字符T时，步骤也是一样。

class Solution {
public:
    int helper(string& answerKey, char c, int k) {
        int n = answerKey.size();
        int count_c = 0, res = 0;
        for (int i = 0, j = 0; j < n; ++j) {
            if (answerKey[j] == c)
                count_c++;

            while (count_c > k) {
                if (answerKey[i++] == c)
                    count_c--;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }

    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(helper(answerKey, 'T', k), helper(answerKey, 'F', k));
    }
};

int main() {
    Solution st;
    string answerKey("TTFTTFTT");
    int k = 1;
    cout << st.maxConsecutiveAnswers(answerKey, k) << endl;

	return 0;
}