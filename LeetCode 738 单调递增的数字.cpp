/*
* 给定一个非负整数N，找出小于等于N的最大整数，保证整数的各位是单调递增的，此处单调递增的定义是比如有一个数xy，x<=y。
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//看了示例以后，我好像找到一个规律，就是当最高位大于最小位的话，题目要求的这个数的最高位一定是比原最高位小1，然后后边的数都是999，
//不过又感觉对于任意一个数，还会有一个更普遍的规律

//看了答案以后，确实是按这个规律，但是我没考虑到遍历顺序，我只想着整数中的某两位数字之间的关系，没有考虑遍历方向
//从个位依次遍历，如果高位比低位大，那么高位--，低位变成9
class Solution {
public:
	int monotoneIncreasingDigits(int n) {
		//这么写的话，当输入100时就会出错，输出90，但是预期结果是99,同样对于9874587，输出的结果也不对，
		/*string s = to_string(n);
		for (int i = s.size() - 1; i > 0; i--) {
			if (s[i - 1] > s[i]) {
				s[i - 1]--;
				s[i] = '9';
			}
		}
		return atoi(s.c_str());*/
		//还是答案上的思路好一些，记录最后一个非递增的位置，最后对这个位置之后的数全都变成9
		string s = to_string(n);
		//int flag = 0;  这么写不行 对于本来就是递增的数都会变成999999...
		int flag = s.size();  //得这么写
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