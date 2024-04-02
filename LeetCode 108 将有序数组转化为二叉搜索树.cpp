#include <iostream>
#include <vector>
using namespace std;

//��һ���������飬��������ת��Ϊһ���߶�ƽ��Ķ���������

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//��ʵ��������ǰ������������������������������������һ�����������ʱ��ʹ�ñ������������ҿ����䶼�С�
//���ҹ����ʱ�򣬽ڵ㶼��ȡ������м�λ�ã��������������ĸ߶�ƽ�ⶼ����Ȼ��Ȼ����
class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return Helper(nums, 0, nums.size() - 1);
	}

	TreeNode* Helper(vector<int>& nums, int begin, int end) {
		if (end < begin) return nullptr;
		int mid = begin + (end - begin) / 2;
		TreeNode* temp = new TreeNode(nums[mid]);

		int leftbegin = begin;
		int leftend = mid - 1;

		int rightbegin = mid + 1;
		int rightend = end;

		temp->left = Helper(nums, leftbegin, leftend);
		temp->right = Helper(nums, rightbegin, rightend);

		return temp;
	}

	//�ڶ�����
	TreeNode* sortedArrayToBST1(vector<int>& nums) {
		return sortedArrayToBSTHelper(nums, 0, nums.size());
	}

	TreeNode* sortedArrayToBSTHelper(vector<int>& nums, int begin, int end) {  //����ҿ�����
		if (begin == end)
			return nullptr;
		int size = end - begin;

		TreeNode* root = new TreeNode(nums[begin + size / 2]);
		root->right = sortedArrayToBSTHelper(nums, begin + size / 2 + 1, end);
		root->left = sortedArrayToBSTHelper(nums, begin, begin + size / 2);
		return root;
	}

	//��΢����һ��
	TreeNode* sortedArrayToBST2(vector<int>& nums) {
		return sortedArrayToBSTHelper(nums, 0, nums.size());
	}

	TreeNode* sortedArrayToBSTHelper(vector<int>& nums, int begin, int end) {
		if (begin == end)
			return nullptr;
		int mid = begin + (end - begin) / 2;

		TreeNode* root = new TreeNode(nums[mid]);
		root->right = sortedArrayToBSTHelper(nums, mid + 1, end);
		root->left = sortedArrayToBSTHelper(nums, begin, mid);
		return root;
	}
};

void main() {}