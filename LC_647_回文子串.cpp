#include <iostream>
#include <vector>
using namespace std;

//����һ���ַ������������л����Ӵ��ĸ���
//��ʼ������ⲻ֪����ô����dp���飬��ʼ���ó�һά���ˣ���Ϊ�뵽����ֻ��һ���ַ������������ֻ��������ˣ��Ϳ�����Ƶ
//�����dp�������õ��ر����dp[i][j]��ʾ�ַ����д�s[i]��s[j]���Ӵ��Ƿ���һ�������Ӵ�
//��ô��s[i]==s[j]ʱ���ͷ�Ϊ���������
//0.i==j��i��jָ��ͬһ���ַ�����ô�϶��ǻ����Ӵ���
//1.i=j-1��Ҳ����i��jָ�����ڵ������ַ��������������ַ�������ȵģ�����Ҳ��һ�������Ӵ�
//2.j-i>1��j��i֮����Ŷ���һ�����ַ�������Ϊi��jָ����ȵ��ַ�������ֻ��Ҫ��i��j֮����ַ����Ƿ�Ϊ�����Ӵ�

class Solution {
public:
	int countSubstrings(string s) {
		vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
		int count = 0;
		for (int i = 0; i < s.size(); i++) {  //��ʼ������ʵ����ĳ�ʼ���͵�0�����һ����ÿ���ַ�����һ�������Ӵ������Լ�Ȼ�±�д����������ˣ�����ĳ�ʼ��д��д��һ��
			dp[i][i] = true;
		}
		for (int i = s.size() - 1; i >= 0; i--) {  //����ı���˳��Ҳ��˵������Ϊ�ӵ���������ĵ��ƹ�ʽ���Կ�����dp�����Ǵ������Ƴ����ϣ����Բ�����ԭ���Ĵ������£��������ұ�������Ӧ���Ǵ������ϣ��������ұ���
			for (int j = i; j < s.size(); j++) {
				if (s[i] == s[j]) {
					if (j - i <= 1)  //ǰ�������
						dp[i][j] = true;
					else
						dp[i][j] = dp[i + 1][j - 1];  //��2�����
				}
				if (dp[i][j]) count++;
			}
		}
		return count;
	}

	//�ڶ�����������û���������������ĵ��ƹ�ʽͦ�򵥣�����dp����Ķ������룬����벻�Զ��壬��ô�����ҵ��ƹ�ʽ
	// dp[i][j]��ʾ��s[i]��s[j]���Ӵ��Ƿ���һ�������Ӵ�
	int countSubstrings1(string s) {
		vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
		int res = 0;
		for (int i = s.size() - 1; i >= 0; i--) {
			for (int j = i; j < s.size(); j++) {
				if (s[i] == s[j]) {
					if (j - i <= 1) {
						res++;
						dp[i][j] = true;
					}
					else if (dp[i + 1][j - 1] == true) {
						res++;
						dp[i][j] = true;
					}
				}
			}
		}
		return res;
	}

	//˫ָ��ⷨ���о������ͨ���׶�
	int countSubstrings2(string s) {
		int res = 0;
		for (int i = 0; i < s.size(); i++) {
			res += lengthofpalindromic(s, i, i);  // ������iΪ���ĵ��ַ����ǻ����Ӵ��ĸ���
			res += lengthofpalindromic(s, i, i + 1);  // ������i��i+1Ϊ���ĵ��ַ����ǻ����Ӵ��ĸ���
		}
		return res;
	}

	int lengthofpalindromic(string& s, int left, int right) {
		int res = 0;
		while (left >= 0 && right < s.size() && s[left] == s[right]) {
			left--;
			right++;
			res++;
		}
		return res;
	}
};

int main() {
	Solution st;
	string s("aaaaa");
	cout << st.countSubstrings(s) << endl;
	cout << st.countSubstrings1(s) << endl;
	cout << st.countSubstrings2(s) << endl;
	return 0;
}