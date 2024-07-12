#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
using namespace std;

// ����������������������̫�鷳��
// ����һ��nums���飬��һ��queriies���飬queriies�����е�ÿһ��Ԫ����vector<int> ���ͣ�vector[0]��ʾ��ǵڼ���Ԫ�أ�vector[0]�Ǳ�Ǽ�����ǰ�����л�û��ǵ���С��Ԫ�ء�
// ����ÿһ�α���꣬ʣ�µ�û�б�ǵ�Ԫ�صĺ͡�
// ��ʼ������������������������ˣ�Ȼ��Ҫ��ǵ�Ԫ�ص��±�ͻ����ˣ���������ֱ������Ҫ��Ԫ�غ�������ɵ�pair�������������ȿ���ѡ����СԪ�أ��ֿ���֪�������±ꡣ

class Solution {
public:

	/*vector<long long> unmarkedSumArray(vector<int>& nums,
		vector<vector<int>>& queries) {
		vector<int> temp;
		for (int i = 0, j = 0; i < nums.size(); i++) {
			if (j < queries.size() && i == queries[j][0]) {
				j++;
			}
			else {
				temp.push_back(nums[i]);
			}
		}
		sort(temp.begin(), temp.end());
		long long sum = accumulate(nums.begin(), nums.end(), 0);
		vector<long long> res;
		for (int i = 0, j = 0; i < queries.size(); i++) {
			vector<int> query = queries[i];
			int index = query[0];
			int len = query[1];

			sum -= nums[index];
			while (len-- && j<temp.size()) {
				sum -= temp[j];
				j++;
			}
			res.push_back(sum);
		}
		return res;
	}*/


	/*vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
		vector<int> temp(nums.begin(), nums.end());
		sort(temp.begin(), temp.end());
		int n = nums.size();
		unordered_map<int, int> umap;
		for (int i = 0; i < n; i++) {
			if (umap.find(temp[i]) == umap.end())
				umap[temp[i]] = i;
		}
		vector<int> visited(n, false);
		vector<long long> res;
		int i = 0;
		long long sum = accumulate(temp.begin(), temp.end(), 0);

		for (vector<int>& query : queries) {
			int num = nums[query[0]];
			int count = query[1];

			int index = umap[num];
			while (temp[index] == num && visited[index]) {
				index++;
			}
			if (temp[index] == num) {
				visited[index] = true;
				sum -= num;
			}

			while (i < n && count) {
				if (visited[i] == false) {
					visited[i] = true;
					count--;
					sum -= temp[i];
				}
				i++;
			}
			res.push_back(sum);
		}
		return res;
	}*/


	vector<long long> unmarkedSumArray(vector<int>& nums,
		vector<vector<int>>& queries) {
		vector<pair<int, int>> temp;
		int n = nums.size();

		for (int i = 0; i < n; i++) {
			temp.push_back({ nums[i], i });
		}
		sort(temp.begin(), temp.end());

		vector<int> visited(n, false);
		vector<long long> res;
		int i = 0;  // ��Ӧtemp��������ã�ָ����С�Ļ�û��ǵ�Ԫ��
		long long sum = accumulate(nums.begin(), nums.end(), 0LL);

		for (vector<int>& query : queries) {
			int index = query[0];
			int count = query[1];

			if (!visited[index]) {
				visited[index] = true;
				sum -= nums[index];
			}

			while (i < n && count) {
				pair<int, int> cur = temp[i];
				if (!visited[cur.second]) {
					visited[cur.second] = true;
					sum -= cur.first;
					count--;
				}
				i++;
			}

			res.push_back(sum);
		}
		return res;
	}

};

int main() {
	Solution st;
	vector<int> nums{ 1,2,2,1,2,3,1 };
	vector<vector<int>> queries{ {1,2},{3,3},{4,2} };
	vector<long long> res = st.unmarkedSumArray(nums, queries);
	for (int i : res)
		cout << i << "  ";
	cout << endl;
	return 0;
}