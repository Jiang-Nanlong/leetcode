#include <iostream>
using namespace std;

//��һ���������������ҳ�ĳ��ֵ����val�Ľڵ㣬����ҵ��ͷ��ؽڵ�ָ�룬�Ҳ����ͷ���null

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
	TreeNode* searchBST(TreeNode* root, int val) {
		if (root == nullptr) return nullptr;
		if (root->val == val) return root;

		TreeNode* leftresult = nullptr, * rightresult = nullptr;
		if (root->val > val) leftresult = searchBST(root->left, val);
		if (root->val < val) rightresult = searchBST(root->right, val);
		if (leftresult) return leftresult;
		if (rightresult) return rightresult;
		return nullptr;
	}

	//���뻹���Լ�һ��
	TreeNode* searchBST1(TreeNode* root, int val) {
		if (root == nullptr || root->val == val) return root;

		if (root->val > val)
			return searchBST1(root->left, val);
		else
			return searchBST1(root->right, val);
	}

	//������Ҳ������������򵥵ĵ����˰�
	TreeNode* searchBST2(TreeNode* root, int val) {
		while (root) {
			if (root->val > val)
				root = root->left;
			else if (root->val < val)
				root = root->right;
			else
				return root;
		}
		return nullptr;
	}
};

void main() {}