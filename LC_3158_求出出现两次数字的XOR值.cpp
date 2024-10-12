#include <iostream>
#include <vector>
using namespace std;

// 给定一个数组，数组中的数字要么出现两次要么出现一次，返回数组中所有出现两次的数字的XOR值
// 数组长度和数组中数字的长度都是[1,50]

class Solution {
public:
    // 一开始自己做的，就是用最简单的方法
    int duplicateNumbersXOR(vector<int>& nums) {
        int cnt[51];
        memset(cnt, 0, sizeof(cnt));
        for (int i : nums)
            cnt[i]++;

        int res = 0;
        for (int i = 1; i < 51; i++)
            if (cnt[i] == 2)
                res ^= i;

        return res;
    }

    // 注意到数字的范围，完全可以用一个longlong型的数字中的每一位表示每个数字的出现次数
    int duplicateNumbersXOR1(vector<int>& nums) {
        int res = 0;
        long long cnt = 0;
        for (int i : nums) {
            if (cnt >> i & 1)  // 如果值为i的数字已经出现过了，那么说明这是第二次出现，因为一个数字要么出现一次，要么出现两次
                res ^= i;
            else
                cnt |= 1LL << i;  // 否则就加入到longlong型中去
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 10,18,7,10,18 };
    cout << st.duplicateNumbersXOR(nums) << endl;
    cout << st.duplicateNumbersXOR1(nums) << endl;
    return 0;
}