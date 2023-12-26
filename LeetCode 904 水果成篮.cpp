#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
* 这个题还是一个滑动窗口的题，题意读了几遍没读明白，看评论上才知道是要干啥。给定一个数组fruits，数组里的每一个元素都是一个正整数，从头开始遍历，子数组中只能有两个数，找出这样的子数组的最大长度。
*/
class Solution {
public:
	int totalFruit(vector<int>& fruits) {
		int i = 0, j = 0, count = 0, result = 0;
		unordered_map<int, int> ump;
		for (; j < fruits.size(); j++) {
			ump[fruits[j]]++;
			while (ump.size() > 2) {
				/*
				ump[fruits[i]]--;
				if(ump[fruits[i]]==0)
					ump.erase(fruits[i]);
				i++;
				*/
				auto it = ump.find(fruits[i]);			//经过对比发现，这种方法更快，比上边的快一些
				--it->second;
				if (it->second == 0)
					ump.erase(it);
				i++;
			}
			result = max(result, j - i + 1);
		}
		return result;
	}
};

//开始想着得用一个额外的容器保存前边已经存在的数字，只想着存不存在的问题，而没考虑多少，所以就选的set，但是还是做不出来，
//然后看了答案才知道使用map，为了让速度更快所以用的unordered_map

int main() {
	Solution st;
	vector<int> nums{ 1,2,3,2,2 };
	int res = st.totalFruit(nums);
	cout << res << endl;
	return 0;
}