#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

// 给定一个数组，如果其中一个子数组中的任意两个元素之差的绝对值小于等于2，就说明这是满足要求的，返回所有满足要求的子数组的数目

// 开始的时候我想着是要记录一下窗口中最大值和最小值，然后移动窗口时只需要移动到最大值的右边一个点就可以了，这样和最小值的差就是小于等于2的了
// 不过后来看示例发现，并不都是最小值一定在最大值的右边，也可能在最大值的左边，这时候就要考虑是最大值还是最小值移除窗口了，情况就比较复杂了。
// 后来看了灵茶山艾府的代码发现可以用map和multiset来实现，比之前简单多了

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long res = 0;
        map<int, int> mp;
        for (int i = 0, j = 0; j < nums.size(); j++) {
            mp[nums[j]]++;
            while (mp.rbegin()->first - mp.begin()->first > 2) {
                if (--mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                i++;
            }
            res += j - i + 1;
        }
        return res;
    }

    long long continuousSubarrays1(vector<int>& nums) {
        long long res = 0;
        multiset<int> mset;
        for (int i = 0, j = 0; j < nums.size(); j++) {
            mset.insert(nums[j]);
            while (*mset.rbegin() - *mset.begin() > 2) {
                mset.erase(mset.find(nums[i]));
                i++;
            }
            res += j - i + 1;
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 35,35,36,37,36,37,38,37,38 };
    cout << st.continuousSubarrays(nums) << endl;
    cout << st.continuousSubarrays1(nums) << endl;
    return 0;
}