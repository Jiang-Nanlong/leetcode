#include <iostream>
#include <vector>
using namespace std;

// ��������һ��
// ��������һ������Ϊ n �����飬��ʼ��������е����־�Ϊ 0������һ������updates��ÿ��Ԫ����һ����Ԫ��[startIndex, endIndex, inc]��
// ��startindex��endindex������startindex��endindex������inc�����������������ݡ�

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