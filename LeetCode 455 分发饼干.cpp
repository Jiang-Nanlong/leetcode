/*
����һ������̰���㷨�ļ���
��ĿҪ��ÿ�����Ӷ���һ��θ��ֵ�������д�С��������ɵĴ�С���ڵ��ں��ӵ�θ��ֵ��˵�����ɿ����ú��ӳԱ�����������ö��ٸ����ӳԱ�
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
�����������һ��Ӧ���ȰѺ�������ͱ������鶼���д�С���������Ȼ��ѭ���������飬���Ӧ�ı�������ÿ�ζ�����һ�εĽ����������
*/
class Solution {
public:
	int findContentChildren(vector<int>& child, vector<int>& cookie) {
		sort(child.begin(), child.end());
		sort(cookie.begin(), cookie.end());
		int children = 0, cookies = 0;
		while (children < child.size() && cookies < cookie.size()) {
			if (child[children] <= cookie[cookies])   //���ԳԱ�
				children++;
			cookies++;
		}
		return children;
	}
};
//������˼·�Ƚϼ򵥣�����˵�ǲ���Ҫ�κε��㷨˼·��������������

int main() {
	vector<int> child1 = { 1,2,3 }, cookie1 = { 1,1 };
	vector<int> child2 = { 1,2 }, cookie2 = { 1,2,3 };
	Solution s;
	cout << s.findContentChildren(child1, cookie1) << endl;
	cout << s.findContentChildren(child2, cookie2) << endl;

	return 0;
}