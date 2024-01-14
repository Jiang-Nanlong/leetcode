#include <iostream>
using namespace std;


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
	TreeNode* insertIntoBST(TreeNode* root, int val) {  //递归
		if (root == nullptr) {
			TreeNode* temp = new TreeNode(val);
			return temp;
		}

		if (root->val > val) root->left = insertIntoBST(root->left, val);
		if (root->val < val) root->right = insertIntoBST(root->right, val);

		return root;
	}

	//递归函数也可以没有返回值，不过要记录前一个节点
	TreeNode* parent;
	void Helper(TreeNode* cur, int val) {
		if (cur == nullptr) {
			cur = new TreeNode(val);
			if (parent->val > val) parent->left = cur;
			else parent->right = cur;
			return;
		}
		parent = cur;
		if (cur->val > val) Helper(cur->left, val);
		if (cur->val < val) Helper(cur->right, val);
		return;
	}
	TreeNode* insertIntoBST2(TreeNode* root, int val) {
		parent = nullptr;
		if (root == nullptr) {
			root = new TreeNode(val);
			return root;
		}
		Helper(root, val);
		return root;

	}

	//迭代
	TreeNode* insertIntoBST1(TreeNode* root, int val) {
		if (root == nullptr) {
			root = new TreeNode(val);
			return root;
		}
		TreeNode* parent = nullptr, * cur = root;

		while (cur) {
			parent = cur;
			if (cur->val > val)
				cur = cur->left;
			else if (cur->val < val)
				cur = cur->right;
			else break;
		}
		TreeNode* temp = new TreeNode(val);
		if (val < parent->val) parent->left = temp;
		else parent->right = temp;
		return root;
	}
};

void main() {

}