#include <iostream>
#include <vector>
using namespace std;

// ����һ���������飬ɾ��һ�������飬ʹ��ʣ�µ�Ԫ���Ƿǵݼ��ģ�����Ҫɾ���������̳���

class Solution {
public:
	int findLengthOfShortestSubarray(vector<int>& arr) {
		int n = arr.size();
		int left = 0, right = n - 1;
		while (left + 1 < n && arr[left] <= arr[left + 1])
			left++;

		while (right - 1 >= 0 && arr[right] >= arr[right - 1])
			right--;

		if (left >= right)
			return 0;
		int minlen = min(n - left - 1, right);
		for (int i = 0, j = right; i <= left; i++) {
			while (j < n && arr[i] > arr[j])
				j++;
			minlen = min(minlen, j - i - 1);
		}
		return minlen;
	}

	int findLengthOfShortestSubarray1(vector<int>& arr) {
		int n = arr.size();
		int right = n - 1;

		while (right > 0 && arr[right] >= arr[right - 1])
			right--;

		if (right == 0)
			return 0;
		int minlen = right;
		for (int i = 0, j = right; i == 0 || arr[i - 1] <= arr[i]; i++) {
			while (j < n && arr[i] > arr[j])
				j++;
			minlen = min(minlen, j - i - 1);
		}
		return minlen;
	}
};

int main() {
	Solution st;
	vector<int> arr{ 1,2,3,10,4,2,3,5 };
	cout << st.findLengthOfShortestSubarray(arr) << endl;
	cout << st.findLengthOfShortestSubarray1(arr) << endl;
	return 0;
}