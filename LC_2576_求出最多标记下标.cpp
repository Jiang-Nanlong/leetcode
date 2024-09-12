#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ����һ�����飬һ��ʼ������±궼û�б���ǣ�����ִ����������²�����
// ѡ������������ͬ��δ��ǵ��±�i��j������2*nums[i] <= nums[j]������±�i��j
// ִ��������������Σ�����nums�������Ա���ǵ��±���Ŀ

class Solution {
public:
	int maxNumOfMarkedIndices(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int n = nums.size();
		int left = n / 2 - 1, right = n - 1;
		int res = 0;
		while (left >= 0) {
			if (nums[left] * 2 <= nums[right]) {
				res += 2;
				right--;
				left--;
			}
			else {
				left--;
			}
		}
		return res;
	}

	// ̰�ĵ����룬�����ǰk�������k���������С�ڵ���k�����ԣ������Ե�������k֮������ȣ�Ҳ����kԽ�࣬����Ҳ��Խ�ࡣ
	// ����һ��������ϵ����ô�����ö�����
	int maxNumOfMarkedIndices1(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int n = nums.size();
		auto check = [&](int k) {
			for (int i = 0; i < k; i++) {
				if (2 * nums[i] > nums[i + n - k])
					return false;
			}
			return true;
			};

		int left = 0, right = n / 2 + 1;
		while (left + 1 < right) {
			int mid = (left + right) / 2;
			if (check(mid))
				left = mid;
			else
				right = mid;
		}
		return left * 2;
	}
};

int main() {
	Solution st;
	vector<int> nums{ 9,2,5,4 };
	cout << st.maxNumOfMarkedIndices(nums) << endl;
	cout << st.maxNumOfMarkedIndices1(nums) << endl;
	return 0;
}