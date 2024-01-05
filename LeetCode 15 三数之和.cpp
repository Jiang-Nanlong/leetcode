#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

//����֮�͵���0�������������ֱ���ʲô������ÿ����Ԫ�鲻���ظ�
//���������ù�ϣ����������ʱ��̫���ˣ����ǵ���˫ָ�����ȽϿ졣

class Solution {
public:
	//vector<vector<int>> threeSum(vector<int>& nums) {
	//	vector<vector<int>> res;
	//	sort(nums.begin(), nums.end());
	//	for (int i = 0; i < nums.size(); i++) {
	//		if (nums[i] > 0) break;
	//		if (i > 0 && nums[i] == nums[i - 1]) continue;
	//		unordered_set<int> uset;
	//		for (int j = i + 1; j < nums.size(); j++) {
	//			if (j > i + 2 && nums[j] == nums[j - 1]) continue;   //������һֱ�벻ͨΪɶ����j>i+1�������Ժ��֪�����ս�ѭ����ʱ��j=i+1,�����ǰ���j�ǽ���е����Ļ����������ǵڶ��������д��j>i+1�Ļ���������������continue�ˣ���Զ�ղ���������
	//			//��������ֻ����j>i+2
	//			int c = 0 - nums[i] - nums[j];
	//			if (uset.find(c) != uset.end()) {
	//				res.push_back({ nums[i],nums[j],c });
	//				uset.erase(c);
	//			}
	//			else {
	//				uset.insert(nums[j]);
	//			}
	//		}
	//	}
	//	return res;
	//}

	//�ϱߵ�ʹ�ù�ϣ��ʵ�ֵģ��±�������˫ָ��ʵ�ֵģ�����˫ָ���˼·����
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>>  res;
		int length = nums.size();
		sort(nums.begin(), nums.end());
		for (int k = 0; k < length - 2; k++) {
			if (nums[k] > 0) break;
			if (k > 0 && nums[k] == nums[k - 1]) continue; //����ʹ��nums[k] == nums[k+1]��������������������������{-1��-1,2}���֣��ͻᱨ��
			int i = k + 1, j = length - 1;
			while (i < j) {
				int sum = nums[k] + nums[i] + nums[j];
				if (sum == 0) {
					res.push_back({ nums[k],nums[i],nums[j] });
					while (i < j && nums[i] == nums[++i]);
					while (i < j && nums[j] == nums[--j]);
				}
				else if (sum < 0) {
					while (i < j && nums[i] == nums[++i]);
				}
				else if (sum > 0) {
					while (i < j && nums[j] == nums[--j]);
				}
			}
		}
		return res;
	}
};




int main() {
	Solution st;
	vector<int> nums{ -1,-1,2,1 };
	vector<vector<int>> res = st.threeSum(nums);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[0].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
	return 0;
}