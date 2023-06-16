/*
����һ�������ε��ַ�����board������������½ǵ��ַ����Ͻǣ������п������ƣ����ƣ������ƣ�����·�������ϰ�X�������֡�
�����ƶ���ǰ���ǵ���ĸ���û���ϰ���
һ��·���ĵ÷���·������������֮�ͣ���󷵻�һ���б���������������һ���������ĵ÷֣��ڶ����ǵõ����÷ֵķ�����,���·������1e9+7ȡ�ࡣ
���û���κ�·�������յ㣬�򷵻�[0,0]
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//����о�û˼·��Ҫ���ҵ��÷�����·����Ȼ������·��������������ʱ�临�ӶȾ�̫����
//���˼·��̫�У����˻���������Ƶ��֪����ô���������Ժ���Ҳ���Ǻ��ѣ�
//����������Ƶ�������и��ط����Ե��ˣ���һֱ�벻����ô����·������������Ƶ�ｲ�ĸ�dpһ������һ����ά���飬��ʾ��ǰ��÷����ʱ��·����
class Solution {
public:
	int mod = pow(10, 9) + 7;
	vector<int> pathsWithMaxScore(vector<string>& board) {
		int n = board.size();
		vector<vector<int>> dpScore(n + 1, vector<int>(n + 1, 0)), dpPath(n + 1, vector<int>(n + 1, 0));
		board[0][0] = board[n - 1][n - 1] = '0';
		dpPath[n - 1][n - 1] = 1;
		for (int i = n - 1; i >= 0; i--) {
			for (int j = n - 1; j >= 0; j--) {
				if (board[i][j] != 'X') {
					int m = max({ dpScore[i + 1][j], dpScore[i][j + 1], dpScore[i + 1][j + 1] });
					dpScore[i][j] = m + (board[i][j] - '0');
					if (m == dpScore[i + 1][j])   //����Ǵ��ұ߹�����������ұ߽ڵ��·����
						dpPath[i][j] = (dpPath[i][j] + dpPath[i + 1][j]) % mod;
					if (m == dpScore[i][j + 1])   //����Ǵ��±߹�����������±߽ڵ��·����
						dpPath[i][j] = (dpPath[i][j] + dpPath[i][j + 1]) % mod;
					if (m == dpScore[i + 1][j + 1])  //����Ǵ����±߹�������������½ڵ��·����
						dpPath[i][j] = (dpPath[i][j] + dpPath[i + 1][j + 1]) % mod;
				}
			}
		}
		return { dpPath[0][0] ? dpScore[0][0] : 0,dpPath[0][0] };
	}
};

int main() {
	vector<string> board1 = { "E23","2X2","12S" };
	vector<string> board2 = { "E12","1X1","21S" };
	vector<string> board3 = { "E11","XXX","11S" };
	Solution s;
	vector<int> res(2);
	//����ط���һֱ������ˣ���C++����ѧ�Ĳ�̫��
	res = s.pathsWithMaxScore(board1);
	cout << res[0] + "," + res[1] << endl;

	res = s.pathsWithMaxScore(board2);
	cout << res[0] + "," + res[1] << endl;

	res = s.pathsWithMaxScore(board3);
	cout << res[0] + "," + res[1] << endl;
	return 0;
}