#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

//ÿ��people[i]��{h,k}��ɣ�h��ʾ��ߣ�k��ʾ��ǰ����ߴ��ڻ���ڵ�ǰ�˵�������
//��ʼ����ⲻ�ᣬȻ���˴�������¼�Ĵ����������Ӧ��������˵�Ѿ�����һ��
//�Ȱ���ߴӴ�С���У������ͬ��kС����ǰ��
//Ȼ���ٱ���������people������ÿһ����k����������Ϊ��ǰ�ߵ��˵���߶��Ǵ������ġ�

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

//�±���֮ǰд�Ĵ���

/*
* һȺ��վ��һ�����У�����people��ʾ�������˵����ԣ�people[i]=[hi,ki],hi��ʾ��i���˵���ߣ�ki��ʾǰ����ki����ߴ��ڵ���hi���ˣ�
* ������������ݺ͹����������򣬷��ظ�ʽ��������queue��queue[i]=[hi,ki]
*/

//�Ȱ���ߴӴ�С����Ȼ���ͷ�������������kֵ���в��룬�����Ļ�������������߰��ľͲ����ǰ����߸ߵĲ���Ӱ��
//��ʼ������᲻������ôһ������������ڲ����ʱ�򣬱���˵[5,4]�ɣ��ڰ������뵽�����е�ʱ�����᲻�����ڵ���λ�����ǵ���λ�ǿ��ŵģ�����������������ǲ����ܵģ�
//��Ϊ��Ȼ����k=4����˵���������ǰ�ߴ��ڵ���5��������4�����������ź����Ժ�����ǰ�ߵĿ϶��д��ڻ����4��������������ҿ��ǵ����������
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

//�о�̰�ĵ�˼�벻̫���ԣ�ֻ�����Ȱ���߸ߵ�people��kֵ���в���
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