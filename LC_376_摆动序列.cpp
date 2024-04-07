#include <iostream>
#include <vector>
using namespace std;

//如果数字之间的差严格按照正负数交替出现，就称数字是摆动序列。第一个差可能是正也可能是负，少于两个元素的序列也是摆动序列。
//返回数组中摆动的数字个数
//感觉这个题是真难，我只能想到要用1和2的差和2与3的差进行比较，其余的想不到，而且如果遇到平坡就不会了，到现在也想不通这个题是怎么用贪心解决的。

class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		if (nums.size() < 2) return nums.size();
		int prediff = 0, nextdiff = 0, result = 1;  //result=1，默认最后一个元素是。
		//prediff=0假想在第0个之前还有一个节点，这个节点和nums[0]一样，这样在nums[0]这个节点就能使用下边的代码了
		for (int i = 0; i < nums.size() - 1; i++) {
			nextdiff = nums[i + 1] - nums[i];
			if ((prediff >= 0 && nextdiff < 0) || (prediff <= 0 && nextdiff > 0)) {
				//这里的判断条件写成这样，主要是因为当遇到平坡时，如1,2,2,2,1，摆动序列是3，把条件写成这样统计的其实是最后边那个2，
				//按说应该也可以统计最左边那个2，但是我把条件改了以后还是不对，不知道为啥
				result++;
				prediff = nextdiff;  //这个地方有点不太懂
			}
		}
		return result;
	}
};

//看评论说这个题还可以用动态规划解决。以后学了动态规划再来看
//这个题弄的我真迷糊，特别是prediff=nextdiff那里

void main() {
	Solution st;
	vector<int> nums{ 1,7,4,9,2,5 };
	cout << st.wiggleMaxLength(nums) << endl;
}
