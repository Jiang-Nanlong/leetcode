#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//�������Ҫ����һ��������k��Ȼ��������е�ĳһԪ�ػ��߶��Ԫ�ط�ת��k�Σ������������
//�������Ȱ������С��������Ȼ�������е���С��0ʱ�ͷ�ת�������ľͰѾ���ֵ�Ƚϴ��������ת��
//�����������ת�꣬k������0����kΪż������ֱ�ӷ�������ͣ����k���������Ǿ���������һ�Σ��ѵ�ǰ��С������תһ�£�Ȼ��sum��ȥ���Ķ���
//��Ϊ֮ǰ�ǰ������ӵģ�����ʵӦ�ü�ȥ���������м���������������

class Solution {
public:
	int largestSumAfterKNegations(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		int sum = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (k > 0 && nums[i] <= 0) {
				nums[i] = -nums[i];
				k--;
			}
			sum += nums[i];
		}
		if (k % 2 == 0) return sum;
		else {
			sort(nums.begin(), nums.end());
			return sum - 2 * nums[0];
		}
	}

	//��������¼�Ĵ��룬�����ֻ����һ�Σ����������ǰ��ž���ֵ�Ӵ�С��˳�������Ļ����k����ʣ�ֻ࣬��Ҫ��ȥ�������һ������
	int largestSumAfterKNegations1(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end(), cmp);
		int sum = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (k > 0 && nums[i] <= 0) {
				nums[i] = -nums[i];
				k--;
			}
			sum += nums[i];
		}
		if (k % 2 == 0) return sum;
		else return sum - 2 * nums[nums.size() - 1];

	}
	static bool cmp(int a, int b) {
		return abs(a) > abs(b);
	}

	//�ڶ��������������������Σ��ղſ�֮ǰд�Ĵ��룬��Ȼ����ֻ����һ��
	int largestSumAfterKNegations2(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		int sum = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] < 0 && k>0) {
				nums[i] = -nums[i];
				k--;
			}
			sum += nums[i];
		}
		sort(nums.begin(), nums.end());

		if (k % 2 == 0) return sum;
		else return sum - 2 * nums[0];
	}
};

int main() {
	Solution st;
	vector<int> nums{ 3,-1,0,2 };
	int sum = st.largestSumAfterKNegations(nums, 3);
	cout << sum << endl;
	sum = st.largestSumAfterKNegations1(nums, 3);
	cout << sum << endl;
	return 0;
}