/*
����һ�����飬��0��1��ɣ�0����û���ֻ���1�����ֻ��ˣ����ڵ�����ز���ͬʱ�ֻ������򶼻���ȥ������һ�����飬�ж��ܷ��ڲ�������ֲ��������������n�໨��
���򷵻�true�����ܷ���false
*/
#include <iostream>
#include <vector>
using namespace std;

//�Ҹо����Դ�ͷ�������飬�������0�Ļ����Ϳ�������ǲ��ǽ���������0������ǵĻ���˵����������������0�п�������һ�Ż�������Ļ��Ͳ��ܡ�
// ����i��i+1��i+2����0����˵��������һ������Ȼ���´δ�i+3������ʼ����
//��¼һ�������ж��ٸ��������n�Ƚ�
class Solution {
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		/*int count = 0, m = flowerbed.size();
		if (m == 0) return false;
		if(m==1)
		for (int i = 0; i < m - 2 && count < n; i++) {
			if (i == 0 && flowerbed[0] == 0 && flowerbed[1] == 0) {
				flowerbed[0] = 1;
				count++;
			}
			else if (flowerbed[i] == 0 && flowerbed[i + 1] == 0 && flowerbed[i + 2] == 0) {
				flowerbed[i + 1] = 1;
				count++;
			}
		}
		if (flowerbed[m - 2] == 0 && flowerbed[m - 1] == 0) count++;
		if (count >= n)return true;
		else return false;*/
		//��ʵ֤���ҵ�˼·���ˣ��������Ӿ��ϱȽ�ֱ�۵�˼·��û����̰���㷨�����������ϱ��˵����ۺ��ִ���Ҳû����д����ô����
		//���ǵ�˼·��һ������Ҫ��һ����ֻ��ע��ǰ��ͺ�ߵ����ڵ㣬���ù�עǰ�ߵĵ㣬��Ϊ����֮��ĸ���������ֱ�Ӹ����������������ֲ�ĵ㣬
		//���ҵ�˼·�ǹ�עǰ�к������㣬��ô����ͱ�úܸ����ˣ����ǵķ���ֻ��Ҫ����00��01��10����������ٸ��ݲ�ͬ���������������Ӧ�ĸ��ӡ�
		//��
		int m = flowerbed.size(), i = 0;
		//while (i < m) {
		//	if (flowerbed[i] == 0) {
		//		if (i == m - 1) {  //��������һ����
		//			n--;
		//			break;
		//		}
		//		if (flowerbed[i + 1] == 0) {  //00,��ǰλ�ÿ����ֻ�
		//			n--;
		//			i += 2;
		//		}
		//		else if (flowerbed[i + 1] == 1) {  //01����ǰλ�ò����ֻ�����һ��λ��Ҳ�����ֻ�����Ϊ������11�����������i+2λ�ñ�Ϊ0������ֱ������i+3λ��
		//			i += 3;
		//		}
		//	}
		//	else {  //��ǰλ��Ϊ1����ֱ������i+2
		//		i += 2;
		//	}
		//}
		//return n <= 0;
		//������뻹�������Ż�һ��
		for (i = 0; i < m && n > 0;) {
			if (flowerbed[i] == 1) {
				i += 2;
			}
			else if (i == m - 1 || flowerbed[i + 1] == 0) {
				n--;
				i += 2;
			}
			else {
				i += 3;
			}
		}
		return n <= 0;
	}
};
//д���Ժ���˼·Ҳͦ�򵥣�Ϊɶ��ʱ��û�������أ���
int main() {
	vector<int> flowerbed1 = { 1,0,0,0,1 };
	int n1 = 1, n2 = 2;
	Solution s;
	vector<int> flowerbed2 = { 0,0,1,0,1 };
	vector<int> flowerbed3 = { 1,0,1,0,0 };

	cout << s.canPlaceFlowers(flowerbed1, n1) << endl;
	cout << s.canPlaceFlowers(flowerbed1, n2) << endl;
	cout << s.canPlaceFlowers(flowerbed2, 1) << endl;
	cout << s.canPlaceFlowers(flowerbed3, 1) << endl;
	return 0;
}