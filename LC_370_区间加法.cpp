#include <iostream>
#include <vector>
using namespace std;

// 差分数组第一题
// 假设你有一个长度为 n 的数组，初始情况下所有的数字均为 0。给定一个数组updates，每个元素是一个三元组[startIndex, endIndex, inc]，
// 将startindex和endindex（包括startindex和endindex）增加inc，返回最后数组的内容。

class Solution {
public:
	vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
		vector<int> res(length, 0);
		for (auto& vec : updates) {
			int left = vec[0], right = vec[1], val = vec[2];
			res[left] += val;
			if (right + 1 < length)
				res[right + 1] -= val;
		}
		for (int i = 1; i < length; i++)
			res[i] += res[i - 1];
		return res;
	}
};

int main() {
	Solution st;
	int length = 5;
	vector<vector<int>> updates{ {1, 3, 2},{2, 4, 3},{0, 2, -2} };
	vector<int> res = st.getModifiedArray(length, updates);
	for (int i : res)
		cout << i << " ";
	cout << endl;
	return 0;
}