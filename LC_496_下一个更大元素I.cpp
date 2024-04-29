#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

//������������nums1��nums2��nums1��nums2���Ӽ����ҳ�nums1[i]��nums2�ж�Ӧ�ĵ�һ�����Ԫ�أ���󷵻�����res��res[i]��num1[i]��nums2�����е�һ����nums1[i]���ֵ

class Solution {
public:

	//�������Լ�д�Ĵ���
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, int> ump;
		stack<int> stk;
		vector<int> temp(nums2.size(), -1), res(nums1.size(), 0);
		for (int i = 0; i < nums2.size(); i++)
			ump.insert({ nums2[i],i });

		for (int i = 0; i < nums2.size(); i++) {
			while (!stk.empty() && nums2[i] > nums2[stk.top()]) {
				temp[stk.top()] = nums2[i];
				stk.pop();
			}
			stk.push(i);
		}

		for (int i = 0; i < nums1.size(); i++) {
			res[i] = temp[ump[nums1[i]]];
		}
		return res;
	}

	//�±��Ǵ�������¼�Ĵ��룬�о���������ã���Ϊnums1��nums2���Ӽ������ܶ��ߵĳ��Ȳ��Ƚϴ󣬲���һ����Ҫ��nums2�ĵ�һ������Ԫ�������
	vector<int> nextGreaterElement1(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, int> ump;
		stack<int> stk;
		vector<int> res(nums1.size(), -1);
		for (int i = 0; i < nums1.size(); i++) {
			ump[nums1[i]] = i;
		}
		for (int i = 0; i < nums2.size(); i++) {
			while (!stk.empty() && nums2[i] > nums2[stk.top()]) {
				if (ump.count(nums2[stk.top()]) > 0) {
					res[ump[nums2[stk.top()]]] = nums2[i];
				}
				stk.pop();
			}
			stk.push(i);
		}
		return res;
	}

	//�ڶ���������ʼ��ʱ���Ǹ���һ��һ�����������nums2�����������һ�����Ԫ�ض��������Ȼ������nums1�е�Ԫ�ؽ���ƥ��
	//Ȼ����벻����Ӧ����ôŪ�ˣ���������һ��֮ǰ�ύ�Ĵ���
	vector<int> nextGreaterElement2(vector<int>& nums1, vector<int>& nums2) {
		stack<int> stk;
		vector<int> res(nums1.size(), -1);
		unordered_map<int, int> umap;
		for (int i = 0; i < nums1.size(); i++)
			umap[nums1[i]] = i;

		for (int i = 0; i < nums2.size(); i++) {
			while (!stk.empty() && nums2[i] > nums2[stk.top()]) {
				if (umap.find(nums2[stk.top()]) != umap.end()) {
					res[umap[nums2[stk.top()]]] = nums2[i];
				}
				stk.pop();
			}
			stk.push(i);
		}
		return res;
	}

	//��ôдҲ�У����ǲ����ϱߵĺ�
	vector<int> nextGreaterElement3(vector<int>& nums1, vector<int>& nums2) {
		stack<int> stk;
		vector<int> res(nums1.size(), -1), temp(nums2.size(), -1);
		unordered_map<int, int> umap;
		for (int i = 0; i < nums2.size(); i++)
			umap[nums2[i]] = i;

		for (int i = 0; i < nums2.size(); i++) {
			while (!stk.empty() && nums2[i] > nums2[stk.top()]) {
				temp[stk.top()] = nums2[i];
				stk.pop();
			}
			stk.push(i);
		}

		for (int i = 0; i < nums1.size(); i++) {
			res[i] = temp[umap[nums1[i]]];
		}
		return res;
	}
};

int main() {
	Solution st;
	vector<int> nums1 = { 4, 1, 2 }, nums2 = { 1, 3, 4, 2 };
	vector<int> res = st.nextGreaterElement(nums1, nums2);
	for (auto i : res)
		cout << i << "  ";

	cout << endl;
	vector<int> res1 = st.nextGreaterElement1(nums1, nums2);
	for (auto i : res1)
		cout << i << "  ";
	return 0;
}