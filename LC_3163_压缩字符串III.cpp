#include <iostream>
#include <string>
using namespace std;

// 其实就是统计字符串中连续的相同字符的个数，最后写成“个数+字符”的格式，而且个数最多为9

class Solution {
public:
    // 感觉我这个写法的处理逻辑这么混乱的原因就是因为要通过fast-slow+1或fast-slow来计算长度，这样就导致最后一个字符的处理逻辑必须单独出来
    // 而使用count就不会面对这种问题
    string compressedString(string word) {
        string res;
        int slow = 0, fast = 0;
        while (fast <= word.size()) {
            if (fast == word.size()) {
                int len = fast - slow;
                char c = word[fast - 1];
                string str;
                while (len > 9) {
                    str = std::to_string(9) + c;
                    res += str;
                    len -= 9;
                }
                if (len > 0) {
                    str = std::to_string(len) + c;
                    res += str;
                }
                return res;
            }
            if (word[fast + 1] == word[fast]) fast++;
            else {
                int len = fast - slow + 1;
                char c = word[fast];
                string str;
                while (len > 9) {
                    str = std::to_string(9) + c;
                    res += str;
                    len -= 9;
                }
                str = std::to_string(len) + c;
                res += str;
                fast++;
                slow = fast;
            }
        }
        return res;
    }

    string compressedString1(string s) {
        string result;
        int right = 0;
        int n = s.length();

        while (right < n) {
            char c = s[right];
            int count = 1;

            while (right + 1 < n && s[right + 1] == c) {
                right++;
                count++;
            }
            while (count > 9) {
                result += to_string(9) + c;
                count -= 9;
            }
            result += to_string(count) + c;
            ++right;
        }
        return result;
    }

    string compressedString2(string word) {
        string res;
        int count = 1;
        char c = word[0];
        for (int i = 1; i < word.size(); i++) {
            if (word[i] == word[i - 1])
                count++;
            else {
                while (count) {
                    if (count > 9) {
                        res += to_string(9) + c;
                        count -= 9;
                    }
                    else {
                        res += to_string(count) + c;
                        break;
                    }
                }
                count = 1;
                c = word[i];
            }
        }
        while (count) {
            if (count > 9) {
                res += to_string(9) + c;
                count -= 9;
            }
            else {
                res += to_string(count) + c;
                break;
            }
        }
        return res;
    }
};

// compressedString1是最好的
int main() {
    Solution st;
    string s("fffffffffdddddddddddddddddddddddddmmmmooooooooooss");
    string s1("ooooss");
    cout << st.compressedString(s1) << endl;
    cout << st.compressedString1(s1) << endl;
    return 0;
}