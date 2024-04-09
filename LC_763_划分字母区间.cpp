#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//ģ����������ص���������⣬�ȼ����ÿ����ĸ�Ŀ�ʼ�ͽ������䣬Ȼ���ٺ���������һ����������в�����
//��������������s=vhaagbqkaqʱ���д�����ȡ�����[1,1,8]��ʵ�ʽ����[2,7]������ط���֪��զ���£��ȹ������ٿ�
class Solution {
public:
	static bool cmp(vector<int>& a, vector<int>& b) {
		return a[0] < b[0];
	}
	vector<vector<int>> getcount(string s) {   //ģ������ĺ����ص���������⣬��ȡÿ����ĸ������
		vector<vector<int>> hash(26, vector<int>(2, INT_MIN));
		vector<vector<int>> res;
		for (int i = 0; i < s.size(); i++) {
			if (hash[s[i] - 'a'][0] == INT_MIN)
				hash[s[i] - 'a'][0] = i;
			hash[s[i] - 'a'][1] = i;
		}
		for (int i = 0; i < s.size(); i++) {
			if (hash[i][0] != INT_MIN)
				res.push_back(hash[i]);
		}
		return res;
	}

	vector<int> partitionLabels(string s) {  //�������������
		vector<int> res;
		vector<vector<int>> countLabels = getcount(s);
		sort(countLabels.begin(), countLabels.end(), cmp);
		int right = countLabels[0][1], left = 0;
		for (int i = 1; i < countLabels.size(); i++) {
			if (countLabels[i][0] > right) {
				res.push_back(right - left + 1);
				//left = countLabels[i][0];
				left = right + 1;
			}
			right = max(right, countLabels[i][1]);
		}
		res.push_back(right - left + 1);
		return res;
	}

	//�ڶ������������˺�һ��ʱ�䣬��δ��뻹���кܶ�ϸ����Ҫע��
	vector<int> partitionLabels1(string s) {
		vector<vector<int>> hash = countLabels(s);
		vector<int> res;
		sort(hash.begin(), hash.end(), cmp);
		int end = hash[0][1];
		int leftboard = 0;
		for (int i = 1; i < hash.size(); i++) {
			if (hash[i][0] < end)
				end = max(end, hash[i][1]);
			else {
				res.push_back(end - leftboard + 1);
				leftboard = hash[i][0];
				end = hash[i][1]; //ͬʱ����leftboard��end
			}
		}
		res.push_back(end - leftboard + 1);
		return res;
	}

	vector<vector<int>> countLabels(string s) {
		vector<vector<int>> hash(26, vector<int>(2, INT_MIN));
		vector<vector<int>> res;
		for (int i = 0; i < s.size(); i++) {
			if (hash[s[i] - 'a'][0] == INT_MIN)
			{
				hash[s[i] - 'a'][0] = i;
				hash[s[i] - 'a'][1] = i;  //��һ��Ҳ�Ǳ�Ҫ�ģ���ֹһ������ֻ��һ�����ʣ������������ֻ��һ�������
			}
			else
				hash[s[i] - 'a'][1] = i;
		}
		for (int i = 0; i < 26; i++) {
			if (hash[i][0] != INT_MIN) {
				res.push_back(hash[i]);
			}
		}
		return res;
	}
};

int main() {
	Solution st;
	string s("ababcbacadefegdehijhklij");
	vector<int>res = st.partitionLabels1(s);
	for (auto i : res)
		cout << i << " ";
	return 0;
}

//���Ǵ�������¼��pdf�����Ĵ��룬���ҵ�һ��������⿴������101�Ĵ���һģһ�����о����˼·�ر����ֻ��עÿ����ĸ�����λ�ã�
//�����Ŀ�ʼλ�á�
/*
class Solution {
public:
	vector<int> partitionLabels(string s) {
		int count[27] = { 0 };
		for (int i = 0; i < s.size(); i++) {  //ͳ��ÿ����ĸ���ֵ����λ��
			count[s[i] - 'a'] = i;
		}
		int left = 0, right = 0;
		vector<int> res;
		for (int i = 0; i < s.size(); i++) {
			right = max(right, count[s[i] - 'a']);
			if (i == right) {  //����ж������е�����
				res.push_back(right - left + 1);
				left = right + 1;
			}
		}
		return res;
	}
};
*/

//��������֮ǰд��
/*
����һ���ַ�����Ҫ���ַ������ֳɾ������Ƭ�Σ�ͬһ��ĸ���ֻ�ܳ�����ͬһƬ���У����ֽ����Ҫ����Ҫ�󣺰���ЩƬ�ΰ�˳�����ӻ��������ԭ�����ַ���
����һ���б��б���ÿһ��Ԫ�ر�ʾһ��Ƭ�εĳ��ȡ�
ע���ַ���ȫ��Сд��ĸ��ɣ�����1<= s.length <= 500
*/


//���û��˼·������LeetCode101�ϵ���ʾ���ֿ��Լ�¼ÿ����ĸ���ֵ��ʼλ�ú����λ�ã������ͱ�����������ˣ������ת��Ϊ����м������໥����������
//���˼��������»�����������ҾͶ��ˣ��ȱ���һ��string��ͳ��ÿ���ַ����ֵ����λ�ã�Ȼ���ͷ��ʼ������ͳ�Ƶ�ǰ���������ַ����������λ�ã������Ļ���
//����������������λ��ʱ��˵��ǰ�߼����������ַ����ѵ�������λ�ã������������ֹλ�õ��ַ�Ҳ�Ѿ����������λ���ˣ�������һ���ַ����������ˣ����ԾͿ��Ի���һ���ˡ�
/*
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
*/