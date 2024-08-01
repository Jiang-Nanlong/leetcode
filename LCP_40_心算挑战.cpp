#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 给定一个数组cards，可以选择数组中的cnt个数字加起来，但是结果一定要是偶数，返回最大的结果。

class Solution {
public:
    int maxmiumScore(vector<int>& cards, int cnt) {
        sort(cards.begin(), cards.end(), [&](int& a, int& b) { return a > b; });
        int res = 0;

        vector<int> odd, even;
        int preodd = 0;
        for (int i : cards) {
            if (i % 2 == 1) {  // 奇数两两之和加入到odd数组
                if (preodd != 0) {
                    odd.push_back(preodd + i);
                    preodd = 0;
                }
                else
                    preodd = i;
            }
            else  // 偶数加入到even数组
                even.push_back(i);
        }

        int i = 0, j = 0, k = 0;
        int oddnum = odd.size(), evennum = even.size();
        for (i = cnt; i > 0 && (j < oddnum || k < evennum); --i) {
            if (i >= 2) {  // 如果现在有两个及两个以上的数可以选择，我们既可以选择两个奇数，也可以选择一个偶数
                if (j < oddnum && k < evennum - 1) {  // 如果两个数组都可用
                    if (odd[j] >= even[k] + even[k + 1]) {
                        res += odd[j++];
                        i -= 1;
                    }
                    else {
                        res += even[k++];
                    }
                }
                else if (j < oddnum) {  // 仅有odd数组可用
                    res += odd[j++];
                    i -= 1;
                }
                else {  // 仅有even数组可用
                    res += even[k++];
                }
            }
            else if (k < evennum)  // i==1的情况，只能选择一个偶数加入到结果
                res += even[k++];
        }
        if (i != 0)  // 如果最后遍历完两个数组，没有累加到cnt个数字，直接返回0
            return 0;
        return res;
    }
};

int main() {
	Solution st;
	vector<int> cards{ 1,2,8,9 };
	int cnt = 3;
	cout << st.maxmiumScore(cards, cnt) << endl;
	return 0;
}