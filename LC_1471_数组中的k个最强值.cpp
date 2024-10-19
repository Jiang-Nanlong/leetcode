#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> getStrongest(vector<int>& arr, int k) {
		sort(arr.begin(), arr.end());
		int n = arr.size(), mid = (n - 1) / 2, m = arr[mid];
		int i = 0, j = n - 1;
		int index = 0;
		vector<int> res(k);

		while (i < mid && j > mid && index < k) {
			if (m - arr[i] <= arr[j] - m)
				res[index++] = arr[j--];
			else
				res[index++] = arr[i++];
		}
		if (index < k) {
			if (i == mid)
				while (index < k)
					res[index++] = arr[j--];
			else
				while (index < k)
					res[index++] = arr[i++];
		}
		return res;
	}
};

int main() {
	Solution st;
	vector<int> arr{ 6,7,11,7,6,8 };
	int k = 5;
	vector<int> res = st.getStrongest(arr, k);
	for (int& i : res)
		cout << i << " ";
	cout << endl;
	return 0;
}