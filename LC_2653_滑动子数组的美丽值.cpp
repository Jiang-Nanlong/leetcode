#include <iostream>
#include <vector>
using namespace std;

// ����һ���������飬���ÿһ������Ϊk�������������ֵ�����������ֵ�Ķ���������������еĵ�xСԪ���Ǹ�������ô����ֵ�������Ԫ��ֵ������Ϊ0��
// �������������������ֵ��

// ��Ϊ�����nums[i]�����ݷ�ΧΪ[-50, 50]���������ҵ�xСԪ�ص�ʱ��ֱ��ʹ�ñ�����������

class Solution {
public:
	vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
		vector<int> cnt(101, 0);  // ͳ���Ӵ���ÿһ��Ԫ�صĳ��ִ������Ѹ�����ӳ�䵽������Χ
		int n = nums.size();
		vector<int> res(n - k + 1, 0);
		for (int i = 0; i < k - 1; i++) {
			++cnt[nums[i] + 50];
		}
		for (int i = k - 1; i < n; i++) {
			++cnt[nums[i] + 50];
			if (i >= k)
				--cnt[nums[i - k] + 50];

			int count = x;
			for (int j = 0; j < 50; j++) {
				count -= cnt[j];
				if (count <= 0) { // �ҵ���xСԪ��
					res[i - k + 1] = j - 50;
					break;
				}
			}
		}
		return res;
	}
};

int main() {
	Solution st;
	vector<int> nums{ -3,1,2,-3,0,-3 };
	int k = 2, x = 1;
	vector<int> res = st.getSubarrayBeauty(nums, k, x);
	for (int i : res)
		cout << i << " ";
	cout << endl;
	return 0;
}