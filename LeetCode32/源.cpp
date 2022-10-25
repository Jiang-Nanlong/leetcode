#include<iostream>
#include<stack>
using namespace std;
/*
    ��ʼ�뵽����ע�͵��ķ���������������")()())"��ʱ��Ͳ����ˣ�
    ���ǿ���������һ�ַ�����������ջ���ҳ����п���ƥ������ţ���һ���Ƚϼ򵥣���ƥ�����Ϊ0�����е���Ϊ1��Ȼ���ٲ�������������0���ɣ�
    ��һ�⻹�����ö�̬�滮ʵ�֣������һ�û�г��ԡ���ռ��λ�����������������Ͷ�̬�滮ʵ�����¡�

    Ȼ��Ϳ��˴𰸣��о����ر����һ�����벻����
*/
class Solution {
private:
    string s = ")()())";
public:
    int longestValidParentheses() {
        //��һ�ַ���
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

        //�𰸵ķ���
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
