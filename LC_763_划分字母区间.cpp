#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//模仿射箭和无重叠区间的问题，先计算出每个字母的开始和结束区间，然后再和这两个题一样对区间进行操作。
//但是这种在遇到s=vhaagbqkaq时会有错误，争取结果是[1,1,8]，实际结果是[2,7]，这个地方不知道咋回事，等过完年再看
class Solution {
public:
	static bool cmp(vector<int>& a, vector<int>& b) {
		return a[0] < b[0];
	}
	vector<vector<int>> getcount(string s) {   //模仿射箭的和无重叠子区间的题，获取每个字母的区间
		vector<vector<int>> hash(26, vector<int>(2, INT_MIN));
		vector<vector<int>> res;
		for (int i = 0; i < s.size(); i++) {
			if (hash[s[i] - 'a'][0] == INT_MIN)
				hash[s[i] - 'a'][0] = i;
			hash[s[i] - 'a'][1] = i;
		}
		for (int i = 0; i < s.size(); i++) {
			if (hash[i][0] != INT_MIN)
				res.push_back(hash[i]);
		}
		return res;
	}

	vector<int> partitionLabels(string s) {
		vector<int> res;
		vector<vector<int>> countLabels = getcount(s);
		sort(countLabels.begin(), countLabels.end(), cmp);
		int right = countLabels[0][1], left = 0;
		for (int i = 1; i < countLabels.size(); i++) {
			if (countLabels[i][0] > right) {
				res.push_back(right - left + 1);
				//left = countLabels[i][0];
				left = right + 1;
			}
			right = max(right, countLabels[i][1]);
		}
		res.push_back(right - left + 1);
		return res;
	}
};

int main() {
	Solution st;
	string s("vhaagbqkaq");
	vector<int>res = st.partitionLabels(s);
	for (auto i : res)
		cout << i << " ";
	return 0;
}

//这是代码随想录的pdf给出的代码，和我第一次做这个题看的力扣101的代码一模一样，感觉这个思路特别巧妙，只关注每个字母的最后位置，
//不关心开始位置。
/*
class Solution {
public:
	vector<int> partitionLabels(string s) {
		int count[27] = { 0 };
		for (int i = 0; i < s.size(); i++) {  //统计每个字母出现的最后位置
			count[s[i] - 'a'] = i;
		}
		int left = 0, right = 0;
		vector<int> res;
		for (int i = 0; i < s.size(); i++) {
			right = max(right, count[s[i] - 'a']);
			if (i == right) {  //这个判断条件有点巧妙
				res.push_back(right - left + 1);
				left = right + 1;
			}
		}
		return res;
	}
};
*/

//以下是我之前写的
/*
给定一个字符串，要把字符串划分成尽量多的片段，同一字母最多只能出现在同一片段中，划分结果需要满足要求：把这些片段按顺序链接还可以组成原来的字符串
返回一个列表，列表中每一个元素表示一个片段的长度。
注：字符串全由小写字母组成，长度1<= s.length <= 500
*/


//起初没有思路，看了LeetCode101上的提示后发现可以记录每种字母出现的最开始位置和最后位置，这样就变成区间问题了，问题就转化为求解有几部分相互独立的区间
//过了几天再重新回来看这个题我就懂了，先遍历一遍string，统计每个字符出现的最后位置，然后从头开始遍历，统计当前遍历过的字符的最大的最后位置，这样的话，
//当到达这个最大的最后位置时，说明前边几个其他的字符早已到达最后的位置，以至于最大终止位置的字符也已经遍历到最后位置了，所以这一段字符都遍历完了，所以就可以划分一下了。
/*
class Solution {
public:
	vector<int> partitionLabels(string s) {
		int count[27] = { 0 };
		for (int i = 0; i < s.size(); i++) {
			count[s[i] - 'a'] = i;
		}
		vector<int> result;
		int left = 0, right = 0;  //用来记录每一段区间的左右端点，然后计算区间长度
		for (int i = 0; i < s.size(); i++) {
			right = max(right, count[s[i] - 'a']);
			if (i == right) {
				result.push_back(right - left + 1);
				left = i + 1;
			}
		}
		return result;
	}
};

int main() {
	string s = "ababcbacadefegdehijhklij";
	string s1 = "eccbbbbdec";
	Solution S;
	vector<int> result = S.partitionLabels(s);
	for (auto& i : result) {
		cout << i << endl;
	}
	result = S.partitionLabels(s1);
	for (auto& i : result) {
		cout << i << endl;
	}
	return 0;
}
*/
