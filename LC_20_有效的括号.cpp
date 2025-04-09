#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

//这是一个用栈解决的简单题，逻辑上还是挺清晰的。我开始想的是如果碰到左括号就入栈，碰到右括号就看栈顶元素是不是与当前右括号匹配，如果匹配的话就出栈，不匹配直接返回false，但是没想出来怎么写，后来看了别人的代码才知道可以用map。
class Solution {
public:
	//bool isValid(string s) {   //这是看的代码随想录的代码
	//	if (s.size() % 2 != 0) return false;
	//	stack<char> stk;
	//	for (auto& c : s) {
	//		if (c == '(') stk.push(')');
	//		else if (c == '{') stk.push('}');
	//		else if (c == '[') stk.push(']');
	//		else if (stk.empty() || stk.top() != c) return false;
	//		else stk.pop();
	//	}
	//	return stk.empty();
	//}

	bool isValid(string s) {         //这是我自己的代码，也可以实现
		if (s.size() % 2 != 0) return false;
		stack<char> stk;
		unordered_map<char, char> ump;
		ump['('] = ')';
		ump['{'] = '}';
		ump['['] = ']';
		for (auto& c : s) {
			if (c == '(' || c == '{' || c == '[')
				stk.push(c);
			else {
				if (!stk.empty() && c == ump[stk.top()])
					stk.pop();
				else
					return false;
			}
		}
		return stk.empty();
	}

	//第二次做，不如第一回写的简洁
	bool isValid1(string s) {
		unordered_map<char, char> umap = { {')', '('}, {']', '['}, {'}', '{'} };
		stack<char> stk;
		for (char& c : s) {
			if (c == '{' || c == '[' || c == '(')
				stk.push(c);
			else {
				if (!stk.empty()) {
					char temp = stk.top();
					if (temp == umap[c])
						stk.pop();
					else
						return false;
				}
				else
					return false;
			}
		}
		return stk.empty();
	}

	bool isValid2(string s) {
		unordered_map<char, char> umap{{'(', ')'}, {'{', '}'}, {'[', ']'}};
		stack<char> stk;
		for (char c : s) {
			if (umap.contains(c))
				stk.push(c);
			else {
				if (!stk.empty()&&umap[stk.top()] == c)
					stk.pop();
				else
					return false;
			}
		}
		if (!stk.empty())
			return false;
		return true;
	}
};

void main() {
	Solution st;
	string s("()[]{}");
	cout << boolalpha << st.isValid(s) << noboolalpha << endl;
}
