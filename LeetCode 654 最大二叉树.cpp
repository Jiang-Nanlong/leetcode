#include <iostream>
#include <vector>
using namespace std;

//������Ǹ���һ�����飬Ȼ���������ѡ�����ֵ��Ϊ���ڵ㣬Ȼ�����ֵ��ߵ�����λ���������ϣ����ֵ�ұߵ���λ���������ϡ�
//���Ǹ�LeetCode 105 106 һ����

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		return Helper(nums, 0, nums.size());
	}

	TreeNode* Helper(vector<int>& nums, int left, int right) {
		if (left == right) return nullptr;

		int maxvalueindex = left;
		for (int i = left; i < right; i++) {
			if (nums[maxvalueindex] < nums[i]) {
				maxvalueindex = i;
			}
		}

		TreeNode* root = new TreeNode(nums[maxvalueindex]);
		int leftBegin = left;
		int leftEnd = maxvalueindex;
		int rightBegin = maxvalueindex + 1;
		int rightEnd = right;

		root->left = Helper(nums, leftBegin, leftEnd);
		root->right = Helper(nums, rightBegin, rightEnd);

		return root;
	}
};

void main() {}