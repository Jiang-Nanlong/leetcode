/*
����һ���ַ�����Ҫ���ַ������ֳɾ������Ƭ�Σ�ͬһ��ĸ���ֻ�ܳ�����ͬһƬ���У����ֽ����Ҫ����Ҫ�󣺰���ЩƬ�ΰ�˳�����ӻ��������ԭ�����ַ���
����һ���б��б���ÿһ��Ԫ�ر�ʾһ��Ƭ�εĳ��ȡ�
ע���ַ���ȫ��Сд��ĸ��ɣ�����1<= s.length <= 500
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//���û��˼·������LeetCode101�ϵ���ʾ���ֿ��Լ�¼ÿ����ĸ���ֵ��ʼλ�ú����λ�ã������ͱ�����������ˣ������ת��Ϊ����м������໥����������
//���˼��������»�����������ҾͶ��ˣ��ȱ���һ��string��ͳ��ÿ���ַ����ֵ����λ�ã�Ȼ���ͷ��ʼ������ͳ�Ƶ�ǰ���������ַ����������λ�ã������Ļ���
//����������������λ��ʱ��˵��ǰ�߼����������ַ����ѵ�������λ�ã������������ֹλ�õ��ַ�Ҳ�Ѿ����������λ���ˣ�������һ���ַ����������ˣ����ԾͿ��Ի���һ���ˡ�
class Solution {
public:
	vector<int> partitionLabels(string s) {
		int count[27] = { 0 };
		for (int i = 0; i < s.size(); i++) {
			count[s[i] - 'a'] = i;
		}
		vector<int> result;
		int left = 0, right = 0;  //������¼ÿһ����������Ҷ˵㣬Ȼ��������䳤��
		for (int i = 0; i < s.size(); i++) {
			right = max(right, count[s[i] - 'a']);
			if (i == right) {
				result.push_back(right - left + 1);
				left = i + 1;
			}
		}
		return result;
	}
};

int main() {
	string s = "ababcbacadefegdehijhklij";
	string s1 = "eccbbbbdec";
	Solution S;
	vector<int> result = S.partitionLabels(s);
	for (auto& i : result) {
		cout << i << endl;
	}
	result = S.partitionLabels(s1);
	for (auto& i : result) {
		cout << i << endl;
	}
	return 0;
}