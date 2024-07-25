#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ������������nums��changeIndices�����ȷֱ�Ϊn��m��һ��ʼnums�е��±궼��δ��ǵģ��ӵ�1�뵽��m�룬ÿһ�붼����ִ�����¼��ֲ�����
// 1. ѡ��nums�е�һ���±꣬��nums[i]��1
// 2. ���nums[changeIncies[i]]==0���ͱ��nums�����е��±�changeIncies[i]
// 3. ʲôҲ����

// ��ʵ���԰�nums[i]�����ĳһ�ſ��Եĸ�ϰ������changeIncies[i]��ʾ��һ����Կ���һ�š����Ե�������븴ϰ�����ſ���Ҫ�ĸ�ϰ������

// �������������û����ö��ַ�����

class Solution {
public:
	int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
		int n = nums.size(), m = changeIndices.size();
		if (n > m)
			return -1;

		vector<int> last(n);  // ����ͳ��ÿ�ſγ����Ŀ���ʱ��
		auto check = [&](int time) {   // check��������ͳ���ڸ�����ʱ����ڣ��ܷ�������еĿ���
			fill(last.begin(), last.end(), -1);  //��ʼ�����еĿ���ʱ�䶼��Ϊ-1
			for (int i = 0; i < time; i++)
				last[changeIndices[i] - 1] = i;    // ͳ�������ڵ�ÿ�ſε������ʱ��

			if (find(last.begin(), last.end(), -1) != last.end())   // ����������������䣬������һ�ſ�û�����Ŀ���ʱ�䣬�������ʱ���ڲ���������еĿ���
				return false;

			int count = 0;
			for (int i = 0; i < time; i++) {    // ���Ǵ�ͷ�����������
				int index = changeIndices[i] - 1;  
				if (i == last[index]) {  // �����һ����ĳһ�ε������ʱ�䣬���ԡ�����֮ǰ�������ڼ�ȥ���ſ���Ҫ�ĸ�ϰʱ�䡣
					if (count < nums[index])
						return false;
					count -= nums[index];
				}
				else  // ������첻���κ�һ�ſε������ʱ�䣬�ͰѸ�ϰ������һ
					count++;
			}
			return true;
			};

		int left = n, right = m + 1;
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (check(mid))
				right = mid;
			else
				left = mid+1;
		}
		return right > m ? -1 : right;
	}
};

int main() {
	Solution st;
	vector<int> nums{ 2,2,0 }, changeIndices{ 2,2,2,2,3,2,2,1 };
	cout << st.earliestSecondToMarkIndices(nums, changeIndices) << endl;
	return 0;
}