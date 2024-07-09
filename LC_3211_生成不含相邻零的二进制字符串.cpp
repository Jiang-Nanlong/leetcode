#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 给定一个正整数n，返回所有的长度为n，且不包含两个相邻0的所有字符串。
// 1<=n<=18
// n的数据范围很小，直接回溯做

class Solution {
public:
    vector<string> res;
    vector<string> validStrings(int n) {
        res.clear();
        string s;
        backtracking(n, s);
        return res;
    }

    void backtracking(int n, string& s) {
        if (s.size() == n) {
            res.push_back(s);
            return;
        }

        s.push_back('1');  // 插入1的时候不用判断，1肯定是可以插入的
        backtracking(n, s);
        s.pop_back();

        if (s.empty() || s.back()=='1') {  // 如果s为0，或者末尾元素为1，可以在末尾插入0
            s.push_back('0');
            backtracking(n, s);
            s.pop_back();
        }
    }
    bool isValid(string& s) {  // 可以把插入0时候的判断语句写成if(isValid(s))
        if (s.empty())
            return true;

        for (int i = 0; i < s.size() - 1; i++)
            if (s[i] == '0' && s[i + 1] == '0')
                return false;

        if (s.back() == '0')
            return false;

        return true;
    }
};

int main() {
    Solution st;
    vector<string> res = st.validStrings(3);
    for (auto& s : res)
        cout << s << endl;
    return 0;
}