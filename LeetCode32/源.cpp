#include<iostream>
#include<stack>
using namespace std;
/*
    开始想到的是注释掉的方法，但是在遇到")()())"的时候就不行了，
    但是看到评论有一种方法就是先用栈查找出所有可以匹配的括号，这一步比较简单，能匹配的置为0，不行的置为1，然后再查找连续的最多的0即可，
    这一题还可以用动态规划实现，但是我还没有尝试。先占个位过两天用上述方法和动态规划实现以下。

    然后就看了答案，感觉答案特别巧妙，一下子想不到，
*/
class Solution {
private:
    string s = ")()())";
public:
    int longestValidParentheses() {
        //第一种方法
        /*stack<char> st;
        int maxamount = 0, amount = 0;
        for (char c : s) {
            if (c == '(') st.push(c);
            else {
                if (!st.empty()) {
                    st.pop();
                    amount += 2;
                    maxamount = maxamount > amount ? maxamount : amount;
                }
                else
                {
                    amount = 0;
                    continue;
                }

            }

        }
        return maxamount;*/

        //答案的方法
        stack<int> st;
        st.push(-1);
        int maxamount = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') st.push(i);
            else {
                st.pop();
                if (st.empty()) {
                    st.push(i);
                }
                else
                {
                    maxamount = maxamount > (i - st.top()) ? maxamount : (i - st.top());
                }
            }
        }
        return maxamount;
    }
};

int main() {
    Solution *S = new Solution();
    cout << S->longestValidParentheses() << endl;

}
