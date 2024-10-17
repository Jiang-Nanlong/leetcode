#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int maxRepOpt1(string text) {
        int count[26];
        memset(count, 0, sizeof(count));
        for (char c : text)
            count[c - 'a']++;

        int maxlen = 0;
        int i = 0;
        while (i < text.size()) {
            int j = i;
            while (j < text.size() && text[i] == text[j])  // 先统计前半段相同的元素
                j++;

            int k = j + 1;  // 跳过中间不相同的元素
            while (k < text.size() && text[i] == text[k])  // 再统计后半段相同的元素
                k++;

            if (k - i - 1 < count[text[i] - 'a'])  // 如果子串中相同的元素个数小于整个字符串中该元素的个数，那么就可以再子串之后选一个这种元素替换中间不同的元素
                maxlen = max(maxlen, k - i);
            else
                maxlen = max(maxlen, k - i - 1);   // 如果子串中相同的元素个数已经是整个字符串中该元素的个数，那么就只能用最后一个元素替换中间不同的元素
            i = j;
        }
        return maxlen;
    }
};

int main() {
    Solution st;
    string text("aaabaaa");
    cout << st.maxRepOpt1(text) << endl;
    return 0;
}