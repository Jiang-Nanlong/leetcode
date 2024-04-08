#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

//下边是我之前在浪潮的时候做的
/*
n个孩子站成一排，每个孩子最少分配一个糖果，相邻的两个孩子评分更高的孩子获得更多的糖果，返回最少的糖果数目。
最开始的时候我以为用排序的方法，从低到高，评分最低的人分一个，然后依次递增，不过这样就违反了之前每个人的位置，就改变给定的条件了
同时看到实例[1,0,2]最少需要2、1、2，一共5个糖果，然后看了LeetCode101，书中给了一个特备巧妙的算法，
因为每个孩子都至少要获得一个糖果，然后最初就把每个人的糖果设成1，然后从左往右遍历，如果右边孩子大于左边，则右边孩子的糖果数等于左边孩子糖果数+1，
然后从右向左遍历，如果左边孩子评分大于右边孩子，且糖果数低于或等于右边，则左边孩子的糖果数等于右边的+1
*/
/*
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
	int candy(vector<int>& ratings) {
		int m = ratings.size();
		if (m < 2) return m;     //看了LeetCode101补充的，可以加快速度
		vector<int> sweets(m, 1);
		for (int i = 0; i + 1 < m; i++) {
			if (ratings[i] < ratings[i + 1])
				sweets[i + 1] = sweets[i] + 1;
		}
		for (int i = m - 1; i - 1 >= 0; i--) {
			if (ratings[i - 1] > ratings[i] && sweets[i - 1] <= sweets[i]) {
				sweets[i - 1] = sweets[i] + 1;
			}
		}
		*/
		/*int sweet = 0;
		for (int i : sweets)
			sweet += i;
		return sweet;*/
		/*
				return accumulate(sweets.begin(), sweets.end(), 0);  //还可以这样写
			}
		};

		int main() {
			vector<int> ratings1 = { 1,0,2 };
			vector<int> ratings2 = { 1,2,2 };
			Solution s;
			cout << s.candy(ratings1) << endl;
			cout << s.candy(ratings2) << endl;
			return 0;
		}
		*/

		//这次是看的代码随想录的代码，思路跟之前是一样的，这也太难想了，纯纯脑筋急转弯
class Solution {
public:
	int candy(vector<int>& ratings) {
		vector<int> count(ratings.size(), 1);
		for (int i = 1; i < ratings.size(); i++) {
			if (ratings[i] > ratings[i - 1])
				count[i] = count[i - 1] + 1;
		}
		for (int i = ratings.size() - 2; i >= 0; i--) {
			if (ratings[i] > ratings[i + 1])
				count[i] = max(count[i + 1] + 1, count[i]);
		}
		int sum = 0;
		for (int i : count)
			sum += i;
		return sum;
	}

	//第二次做
	//这个思路不行，结果会大于正确的答案，因为在从右向左遍历时，有时候是count[i]已经是大于count[i+1]的了，也就不需要改动了
	int candy1(vector<int>& ratings) {  //思路错了
		if (ratings.size() == 1) return 1;
		int count = ratings.size();
		for (int i = 1; i < ratings.size(); i++) {
			if (ratings[i] > ratings[i - 1])
				count++;
		}
		for (int i = ratings.size() - 2; i >= 0; i--) {
			if (ratings[i] > ratings[i + 1])
				count++;
		}
		return count;
	}

	//这才是正确的答案
	int candy2(vector<int>& ratings) {
		if (ratings.size() == 1) return 1;
		vector<int> count(ratings.size(), 1);

		for (int i = 1; i < ratings.size(); i++) {
			if (ratings[i] > ratings[i - 1]) {
				count[i] = count[i - 1] + 1;
			}
		}
		for (int i = ratings.size() - 2; i >= 0; i--) {
			if (ratings[i] > ratings[i + 1])
				count[i] = max(count[i], count[i + 1] + 1);
		}
		return accumulate(count.begin(), count.end(), 0);
	}
};

int main() {
	Solution st;
	vector<int> ratings{ 1,3,2,2,1 };
	int sum = st.candy(ratings);
	cout << sum << endl;
	cout << st.candy2(ratings) << endl;
	return 0;
}