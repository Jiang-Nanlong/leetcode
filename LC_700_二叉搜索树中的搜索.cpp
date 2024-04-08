#include <iostream>
using namespace std;

//在一个二叉搜索树中找出某个值等于val的节点，如果找到就返回节点指针，找不到就返回null

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

	//代码还可以简化一下
	TreeNode* searchBST1(TreeNode* root, int val) {
		if (root == nullptr || root->val == val) return root;

		if (root->val > val)
			return searchBST1(root->left, val);
		else
			return searchBST1(root->right, val);
	}

	//迭代法也能做，这是最简单的迭代了吧
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

	//第二遍再做首先想到的还是迭代法，这个递归一下子没想起来。
	TreeNode* searchBST3(TreeNode* root, int val) {
		if (root == nullptr || root->val == val)
			return root;
		if (root->val > val)
			return searchBST(root->left, val);
		if (root->val < val)
			return searchBST(root->right, val);
		return nullptr;
	}
};

void main() {}
