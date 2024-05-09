/*
给定一个数组，由0和1组成，0代表没有种花，1代表种花了，相邻的两块地不能同时种花，否则都会死去，给定一个数组，判断能否在不打破种植规则的情况下种入n多花，
能则返回true，不能返回false
*/
#include <iostream>
#include <vector>
using namespace std;

//我感觉可以从头遍历数组，如果遇到0的话，就看它后边是不是借着有两个0，如果是的话，说明在这连续的三个0中可以种入一颗花，否则的花就不能。
// 比如i、i+1、i+2都是0，那说明可以种一个花，然后下次从i+3继续开始遍历
//记录一共可以中多少个，最后与n比较
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
		//事实证明我的思路错了，就是人视觉上比较直观的思路，没有用贪心算法，看了力扣上别人的评论后发现代码也没有我写的这么复杂
		//他们的思路有一个很重要的一点是只关注当前点和后边的相邻点，不用关注前边的点，因为会在之后的各类讨论中直接根据情况跳到可能种植的点，
		//而我的思路是关注前中后三个点，这么程序就变得很复杂了，他们的方法只需要讨论00、01和10三种情况，再根据不同的情况往后跳到相应的格子。
		//唉
		int m = flowerbed.size(), i = 0;
		//while (i < m) {
		//	if (flowerbed[i] == 0) {
		//		if (i == m - 1) {  //如果是最后一个点
		//			n--;
		//			break;
		//		}
		//		if (flowerbed[i + 1] == 0) {  //00,当前位置可以种花
		//			n--;
		//			i += 2;
		//		}
		//		else if (flowerbed[i + 1] == 1) {  //01，当前位置不能种花，下一个位置也不能种花，因为不存在11的情况，所以i+2位置必为0，所以直接跳到i+3位置
		//			i += 3;
		//		}
		//	}
		//	else {  //当前位置为1，则直接跳到i+2
		//		i += 2;
		//	}
		//}
		//return n <= 0;
		//这个代码还可以在优化一下
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
//写完以后发现思路也挺简单，为啥当时就没想起来呢，嚓
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
