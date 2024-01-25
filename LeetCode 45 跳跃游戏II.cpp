#include <iostream>
#include <vector>
using namespace std;

//感觉这个题真难，想不明白，跳跃游戏那题只要判断能否到达终点就行，这个题要找到到达终点最小需要几步
//我开始想的是，如果是覆盖范围发生改变，步数就+1，但是不对。
//感觉把这个题想成下台阶比较好想通，一个台阶就相当于当前覆盖范围所能达到的地方，同时当前台阶的不同位置也会改变下一个台阶所能到达的最远位置，
//如果当前台阶走到头了，还不能到达终点，就只能到下一个台阶继续重复这个过程，直到终点在某一层台阶上，最后台阶数就是最小的跳跃次数。
//但是这也是根据答案反推的，要是让我自己想，我还是想不通。

class Solution {
public:
	int jump(vector<int>& nums) {
		if (nums.size() == 1) return 0;
		int curcover = 0, nextcover = 0;
		int count = 0;
		for (int i = 0; i <= nums.size(); i++) {
			nextcover = max(i + nums[i], nextcover);
			if (i == curcover) {
				count++;
				curcover = nextcover;
				if (nextcover >= nums.size() - 1)
					break;
			}

		}
		return count;
	}

	//感觉下边的代码更好理解
	int jump1(vector<int>& nums) {
		if (nums.size() == 1) return 0;
		int curcover = 0, nextcover = 0;
		int count = 0;
		for (int i = 0; i <= nums.size(); i++) {
			nextcover = max(i + nums[i], nextcover);
			if (i == curcover) {  //到达当前台阶的末尾
				if (curcover != nums.size() - 1) {  //如果当前也不是终点
					count++;
					curcover = nextcover;
					if (nextcover >= nums.size() - 1) //如果下一个台阶可以到终点
						break;
				}
				else  //如果当前已经到终点了
					break;
			}

		}
		return count;
	}
};

int main() {
	Solution st;
	vector<int> nums{ 2,3,1,1,4 };
	int res = st.jump1(nums);
	cout << res << endl;
	return 0;
}