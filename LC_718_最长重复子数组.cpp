#include <iostream>
#include <vector>
using namespace std;

//题目给定两个数组，返回数组中连续的相同的字符串的最长长度。

//dp[i][j]表示nums1中以i-1为结尾，nums2中以j-1为结尾的字符串的连续公共子数组的长度。为什么dp[i][j]要表示i-1和j-1位，而不是表示i位和j位呢，因为在初始化的时候如果也就是判断nums1的第一个字符和nums2中的字符会可能一样，同理，
//nums2中的第一个字符和nums1中的字符也可以能一样，这样的话，在初始化dp数组时就得进行判断，就比较啰嗦。
//如果用dp[i][j]表示以i-1为结尾和j-1为结尾的字符串的话，就同意初始化为0就行了，后边的都可以自己根据递推公式自己推导出来。

//这个题的难点是dp数组的创建和dp[i][j]的意思，以及初始化的问题。

class Solution {
public:
	int findLength(vector<int>& nums1, vector<int>& nums2) {
		vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
		int res = 0;
		for (int i = 1; i <= nums1.size(); i++) {
			for (int j = 1; j <= nums2.size(); j++) {
				if (nums1[i - 1] == nums2[j - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1;

				if (dp[i][j] > res) //最大长度不一定出现在dp数组的有下角
					res = dp[i][j];
			}
		}
		return res;
	}

	//下边的代码是dp[i][j]表示以i为结尾和以j为结尾的字符串的最长重复子数组的长度
	//在初始化的时候有点麻烦，其实也还好，这种看起来更好理解一些。
	int findLength1(vector<int>& nums1, vector<int>& nums2) {
		vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), 0));
		int res = 0;
		for (int i = 0; i < nums2.size(); i++) if (nums1[0] == nums2[i]) dp[0][i] = 1;
		for (int i = 0; i < nums1.size(); i++) if (nums1[i] == nums2[0]) dp[i][0] = 1;

		for (int i = 0; i < nums1.size(); i++) {  //这里的i和j确实是不能从1开始，因为最后结果可能是1，既只有初始化的时候，有的数字是相同的，但是后边的全不同，如果i和j从1开始的话就会跳过这些相同的数字，最后返回0
			for (int j = 0; j < nums2.size(); j++) {
				if (nums1[i] == nums2[j] && i > 0 && j > 0)
					dp[i][j] = dp[i - 1][j - 1] + 1;

				if (dp[i][j] > res)
					res = dp[i][j];
			}
		}
		return res;
	}
};

int main() {
	Solution st;
	vector<int> nums1{ 1,2,3,2,1 }, nums2{ 3,2,1,4,7 };
	cout << st.findLength(nums1, nums2) << endl;
	cout << st.findLength1(nums1, nums2) << endl;
	return 0;
}
