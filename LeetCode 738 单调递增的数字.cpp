/*
* ����һ���Ǹ�����N���ҳ�С�ڵ���N�������������֤�����ĸ�λ�ǵ��������ģ��˴����������Ķ����Ǳ�����һ����xy��x<=y��
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//����ʾ���Ժ��Һ����ҵ�һ�����ɣ����ǵ����λ������Сλ�Ļ�����ĿҪ�������������λһ���Ǳ�ԭ���λС1��Ȼ���ߵ�������999��
//�����ָо���������һ������������һ�����ձ�Ĺ���

//���˴��Ժ�ȷʵ�ǰ�������ɣ�������û���ǵ�����˳����ֻ���������е�ĳ��λ����֮��Ĺ�ϵ��û�п��Ǳ�������
//�Ӹ�λ���α����������λ�ȵ�λ����ô��λ--����λ���9
class Solution {
public:
	int monotoneIncreasingDigits(int n) {
		//��ôд�Ļ���������100ʱ�ͻ�������90������Ԥ�ڽ����99,ͬ������9874587������Ľ��Ҳ���ԣ�
		/*string s = to_string(n);
		for (int i = s.size() - 1; i > 0; i--) {
			if (s[i - 1] > s[i]) {
				s[i - 1]--;
				s[i] = '9';
			}
		}
		return atoi(s.c_str());*/
		//���Ǵ��ϵ�˼·��һЩ����¼���һ���ǵ�����λ�ã��������λ��֮�����ȫ�����9
		string s = to_string(n);
		//int flag = 0;  ��ôд���� ���ڱ������ǵ�������������999999...
		int flag = s.size();  //����ôд
		for (int i = s.size() - 1; i > 0; i--) {
			if (s[i - 1] > s[i]) {
				flag = i;
				s[i - 1]--;
			}
		}
		for (int i = flag; i < s.size(); i++) {
			s[i] = '9';
		}
		return atoi(s.c_str());
	}
};

int main() {
	Solution s;
	cout << s.monotoneIncreasingDigits(332) << endl;
	cout << s.monotoneIncreasingDigits(100) << endl;
	cout << s.monotoneIncreasingDigits(9874587) << endl;
	cout << s.monotoneIncreasingDigits(1234) << endl;
	return 0;
}