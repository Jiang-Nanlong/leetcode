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

	//�ڶ���������ʼ���õĹ�ϣ���ڹ�ϣ������0-a-b�������������ȥ�����ѣ�Ȼ�����˫ָ�������ˡ�
	vector<vector<int>> threeSum1(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> res;
		for (int i = 0; i < nums.size() - 2; i++) {
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			if (nums[i] > 0)
				break;
			int left = i + 1, right = nums.size() - 1;
			while (left < right) {
				int sum = nums[i] + nums[left] + nums[right];
				if (sum == 0) {
					res.push_back({ nums[i], nums[left], nums[right] });
					while (left < right && nums[left] == nums[++left]);
					while (left < right && nums[right] == nums[--right]);
				}
				else if (sum < 0) {
					while (left < right && nums[left] == nums[++left])
						;
				}
				else {
					while (left < right && nums[right] == nums[--right])
						;
				}
			}
		}
		return res;
	}

	// ����������
	vector<vector<int>> threeSum2(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> res;
		for (int i = 0; i < nums.size() - 2; i++) {
			int j = i + 1, k = nums.size() - 1;
			if (nums[i] + nums[i + 1] + nums[i + 2] > 0)
				break;
			if (nums[i] + nums[k - 1] + nums[k] < 0)
				continue;
			if (i > 0 && nums[i] == nums[i - 1]) continue;

			while (j < k) {
				int sum = nums[i] + nums[j] + nums[k];
				/*if (sum == 0) {
					res.push_back({ nums[i], nums[j], nums[k] });

					while (j<k&&nums[j] == nums[++j]);

					while (j<k&&nums[k] == nums[--k]);

				}
				else if (sum < 0)
					j++;
				else if (sum > 0)
					k--;*/
				if (sum == 0) {
					res.push_back({ nums[i], nums[j], nums[k] });

					while (j < k && nums[j] == nums[j + 1]) j++;  // �⼸��whileѭ�����j<k�Ǳ���ģ���Ϊnums����Ϊ{0,0,0}���֣��ڵ���j��kʱ���ܻ�Խ�硣��ʵ��j<nums.size()-1��k>=1������Ҳ�У����ǲ���j<k���
					j++;
					while (j < k && nums[k] == nums[k - 1]) k--;
					k--;
				}
				else if (sum < 0) {
					while (j < k && nums[j] == nums[j + 1]) j++;
					j++;
				}
				else if (sum > 0) {
					while (j < k && nums[k] == nums[k - 1]) k--;
					k--;
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

	res.clear();
	vector<int> nums1{ -1,0,1,2,-1,-4 };
	res = st.threeSum1(nums1);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[0].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}

	res.clear();
	vector<int> nums2{ -1,0,1,2,-1,-4 };
	res = st.threeSum2(nums2);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[0].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
	return 0;
}