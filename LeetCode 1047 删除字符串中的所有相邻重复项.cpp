#include <iostream>
#include <string>
#include <stack>
using namespace std;

//这个题我以为是要删除相邻的所有同样的字符，原来是只让删除相邻的同样的两个字符
class Solution {
public:
	string removeDuplicates(string s) {
		/*
		stack<char> stk;   //开始我没看懂咋回事，以为要消除所有相邻的同种字符，所以不知道咋写，就看了代码随想录的代码。后来知道了只消除两个相邻的字符以后，发现我也能写出来
		for(auto &c:s){
			if(stk.empty()||c!=stk.top())
				stk.push(c);
			else{
				stk.pop();
			}
		}
		s = "";
		while(!stk.empty()){
			s+=stk.top();
			stk.pop();
		}
		reverse(s.begin(),s.end());
		return s;
		*/

		/*string res;     //这个省去了用栈，而是用string代替栈
		for (auto& c : s) {
			if (res.empty() || res.back() != c) {
				res.push_back(c);
			}
			else
				res.pop_back();
		}
		return res;*/

		int top = 0;           //这是在评论区看到的程序，用的双指针的方法
		for (char ch : s) {
			if (top == 0 || s[top - 1] != ch) {
				s[top++] = ch;
			}
			else {
				top--;
			}
		}
		s.resize(top);
		return s;
	}
};

int main() {
	Solution st;
	string s("abbbaca");
	cout << st.removeDuplicates(s) << endl;
	return 0;
}