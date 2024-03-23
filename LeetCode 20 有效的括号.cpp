#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

//����һ����ջ����ļ��⣬�߼��ϻ���ͦ�����ġ��ҿ�ʼ�����������������ž���ջ�����������žͿ�ջ��Ԫ���ǲ����뵱ǰ������ƥ�䣬���ƥ��Ļ��ͳ�ջ����ƥ��ֱ�ӷ���false������û�������ôд���������˱��˵Ĵ����֪��������map��
class Solution {
public:
	//bool isValid(string s) {   //���ǿ��Ĵ�������¼�Ĵ���
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

	bool isValid(string s) {         //�������Լ��Ĵ��룬Ҳ����ʵ��
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

	//�ڶ������������һ��д�ļ��
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
};

void main() {
	Solution st;
	string s("()[]{}");
	cout << boolalpha << st.isValid(s) << noboolalpha << endl;
}