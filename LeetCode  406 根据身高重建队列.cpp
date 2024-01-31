#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

//每个people[i]由{h,k}组成，h表示身高，k表示他前边身高大于或等于当前人的人数。
//开始这个题不会，然后看了代码随想录的代码才慢慢反应过来，虽说已经做了一遍
//先按身高从大到小排列，身高相同，k小的在前边
//然后再遍历排序后的people，根据每一个的k往后数，因为它前边的人的身高都是大于它的。

class Solution {
public:
	static bool cmp(vector<int> a, vector<int> b) {
		if (a[0] == b[0])
			return a[1] < b[1];
		return a[0] > b[0];
	}
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		sort(people.begin(), people.end(), cmp);
		list<vector<int>> res;
		for (int i = 0; i < people.size(); i++) {
			int position = people[i][1];
			auto iterator = res.begin();
			while (position--) {
				iterator++;
			}
			res.insert(iterator, people[i]);
		}
		return vector<vector<int>>(res.begin(), res.end());
	}
};

int main() {
	Solution st;
	vector<vector<int>> people{ {7,0} ,{4,4 }, { 7,1 }, { 5,0 }, { 6,1 }, { 5,2 } };
	vector<vector<int>> res = st.reconstructQueue(people);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

//下边是之前写的代码

/*
* 一群人站成一个队列，数组people表示队列中人的属性，people[i]=[hi,ki],hi表示第i个人的身高，ki表示前边有ki个身高大于等于hi的人，
* 请根据数组内容和规则重新排序，返回格式化的数组queue，queue[i]=[hi,ki]
*/

//先按身高从大到小排序，然后从头往后遍历，按着k值进行插入，这样的话，后续插入身高矮的就不会对前边身高高的产生影响
//开始我在想会不会有这么一种情况，就是在插入的时候，比如说[5,4]吧，在把它插入到队列中的时候他会不会排在第四位，但是第三位是空着的，后来想想这种情况是不可能的，
//因为既然这里k=4，就说明最后在他前边大于等于5的数会有4个，所以在排好序以后在它前边的肯定有大于或等于4个数，不会出现我考虑的这种情况。
/*
class Solution {
private:
	static bool cmp(vector<int> a, vector<int> b) {
		if (a[0] == b[0])return a[1] < b[1];
		return a[0] > b[0];
	}
public:
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		sort(people.begin(), people.end(), cmp);
		list<vector<int>> que;
		for (int i = 0; i < people.size(); i++) {
			int position = people[i][1];
			auto it = que.begin();
			while (position--) it++;
			que.insert(it, people[i]);
		}
		//vector<vector<int>> result;
		//result.assign(que.begin(), que.end());
		//return result;
		return vector<vector<int>>(que.begin(), que.end());
	}
};

//感觉贪心的思想不太明显，只有优先按身高高的people的k值进行插入
int main() {
	vector<vector<int>> people = { {7,0},{4,4},{7,1},{5,0},{6,1},{5,2} };
	Solution s;
	vector<vector<int>> que;
	que = s.reconstructQueue(people);
	for (int i = 0; i < que.size(); i++) {
		cout << que[i][0] << "," << que[i][1] << endl;
	}
	return 0;
}
*/