#include <iostream>
#include <string>
#include <stack>
using namespace std;

//���������Ϊ��Ҫɾ�����ڵ�����ͬ�����ַ���ԭ����ֻ��ɾ�����ڵ�ͬ���������ַ�
class Solution {
public:
	string removeDuplicates(string s) {
		/*
		stack<char> stk;   //��ʼ��û����զ���£���ΪҪ�����������ڵ�ͬ���ַ������Բ�֪��զд���Ϳ��˴�������¼�Ĵ��롣����֪����ֻ�����������ڵ��ַ��Ժ󣬷�����Ҳ��д����
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

		/*string res;     //���ʡȥ����ջ��������string����ջ
		for (auto& c : s) {
			if (res.empty() || res.back() != c) {
				res.push_back(c);
			}
			else
				res.pop_back();
		}
		return res;*/

		int top = 0;           //�����������������ĳ����õ�˫ָ��ķ���
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

	//�������������������Ϊ��Ҫɾ���������ظ�������ɾ�����ڵ������ظ������
	string removeDuplicates1(string s) {
		stack<char> stk;
		string res;
		for (char& c : s) {
			bool flag = false;
			while (!stk.empty() && stk.top() == c) {  //����ɾ�������������ظ������flag�ж�c�Ƿ��ǰ�ߵ��ظ���������ظ�����ջ
				stk.pop();
				flag = true;
			}
			if (flag == false)
				stk.push(c);
		}
		while (!stk.empty()) {
			res += stk.top();
			stk.pop();
		}
		reverse(res.begin(), res.end());
		return res;
	}
	//����ǽ�ɾ�����ڵ��������Ͳ���while��flag��
	string removeDuplicates2(string s) {
		stack<char> stk;
		string res;
		for (char& c : s) {
			if (!stk.empty() && stk.top() == c) 
				stk.pop();
			else
				stk.push(c);
		}
		while (!stk.empty()) {
			res += stk.top();
			stk.pop();
		}
		reverse(res.begin(), res.end());
		return res;
	}
};

int main() {
	Solution st;
	string s("abbbaca");
	cout << st.removeDuplicates(s) << endl;
	return 0;
}