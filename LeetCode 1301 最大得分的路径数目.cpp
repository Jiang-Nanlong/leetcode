/*
给定一个正方形的字符数组board，从数组的右下角到字符左上角，过程中可以左移，上移，左上移，但是路径中有障碍X或者数字。
可以移动的前提是到达的格子没有障碍。
一条路径的得分是路径上所有数字之和，最后返回一个列表，包含两个数，第一个数是最大的得分，第二个是得到最大得分的方案数,最后路径数对1e9+7取余。
如果没有任何路径返回终点，则返回[0,0]
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//这个感觉没思路，要先找到得分最大的路径，然后再找路径数，但是这样时间复杂度就太大了
//这次思路不太行，看了花花酱的视频才知道怎么做，看完以后发现也不是很难，
//看完他的视频发现我有个地方忽略掉了，我一直想不出怎么保存路径数，他的视频里讲的跟dp一样设置一个二维数组，表示当前点得分最大时的路径数
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
					if (m == dpScore[i + 1][j])   //如果是从右边过来，则加上右边节点的路径数
						dpPath[i][j] = (dpPath[i][j] + dpPath[i + 1][j]) % mod;
					if (m == dpScore[i][j + 1])   //如果是从下边过来，则加上下边节点的路径数
						dpPath[i][j] = (dpPath[i][j] + dpPath[i][j + 1]) % mod;
					if (m == dpScore[i + 1][j + 1])  //如果是从右下边过来，则加上右下节点的路径数
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
	//这个地方我一直输出不了，我C++这里学的不太好
	res = s.pathsWithMaxScore(board1);
	cout << res[0] + "," + res[1] << endl;

	res = s.pathsWithMaxScore(board2);
	cout << res[0] + "," + res[1] << endl;

	res = s.pathsWithMaxScore(board3);
	cout << res[0] + "," + res[1] << endl;
	return 0;
}