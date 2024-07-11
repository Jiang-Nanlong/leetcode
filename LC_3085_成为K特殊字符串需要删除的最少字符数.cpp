#include <iostream>
#include <vector>
using namespace std;

// 给定一个字符串word和一个整数k，如果字符串中每两个字符出现次数的差的绝对值都小于等于k，就认为这是一个特殊字符串。
// 返回把字符串变成特殊字符串需要的最少删除数量。

// 因为都是小写字母，所以数据数量只有26个。
// 要想保证任意两个字符出现次数的差的绝对值都小于等于k，只需要最大的出现次数和最小出现次数的差小于等于k即可。
// 这里的数据量只有26，完全可以用暴力解法，尝试把每一个出现次数都当做最小的出现次数，如果字符的出现次数比最小的出现次数还小，那么直接删除这种元素。
// 如果元素的次数减去最小出现次数大于等于k了，就把这个差变成k，也就是把元素出现次数变为最小出现次数+k

class Solution {
public:
    int minimumDeletions(string word, int k) {
        int f[26];
        memset(f, 0, sizeof(f));

        for (char c : word)
            f[c - 'a']++;

        vector<int> freq;

        for (int i : f)
            if (i)
                freq.push_back(i);

        int res = INT_MAX;
        for (int i = 0; i < freq.size(); i++) {
            int temp = 0;

            for (int j = 0; j < freq.size(); j++) {
                if (freq[j] < freq[i])  // 如果元素出现次数小于最小出现次数，直接删除
                    temp += freq[j];
                else if (freq[j] > freq[i] + k)  // 如果元素出现次数-最小出现次数 >= k，就把这个差变成k，也就是把元素出现次数变成最小出现次数+k
                    temp += (freq[j] - freq[i] - k);
            }
            res = min(res, temp);
        }
        return res;
    }
};

int main() {
    Solution st;
    string word("aabcaba");
    int k = 0;
    cout << st.minimumDeletions(word, k) << endl;
    return 0;
}