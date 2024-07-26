#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// 给定两个正整数数组，arr1和arr2，找出所有的arr1元素和arr2元素组成的数对中最长公共前缀的长度。
// 可以用哈希表存储arr2数组中每一个元素的所有前缀，然后再统计arr1中元素的每一个前缀在哈希表中是否可以找到相同的前缀
// 开始用暴力做，但是超时了
// 1 <= arr1.length, arr2.length <= 5 * 10^4, 1 <= arr1[i], arr2[i] <= 108

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> uset;
        for (int x : arr2) {
            uset.insert(x);
            while (x) {
                uset.insert(x / 10);
                x /= 10;
            }
        }
        int res = 0;
        for (int x : arr1) {
            int len = 0, t = x;
            for (int i = x; x; x /= 10)
                len++;
            while (len) {
                if (uset.find(t) != uset.end())
                    res = max(res, len);
                t /= 10;
                len--;
            }
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> arr1{ 1,10,100 }, arr2{ 1000 };
    cout << st.longestCommonPrefix(arr1, arr2) << endl;
    return 0;
}