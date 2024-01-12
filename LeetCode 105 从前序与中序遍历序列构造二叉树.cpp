#include <iostream>
#include <vector>
using namespace std;

//这个题和LeetCode 106 一样，都是重点在于确定根节点，然后分割两个遍历的序列。

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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.size() == 0 || inorder.size() == 0) return nullptr;
		return Helper(preorder, 0, preorder.size(), inorder, 0, inorder.size());
	}

	TreeNode* Helper(vector<int>& preorder, int preorderBegin, int preorderEnd, vector<int>& inorder, int inorderBegin, int inorderEnd) {
		if (preorderBegin == preorderEnd) return nullptr;

		int rootvalue = preorder[preorderBegin];
		TreeNode* root = new TreeNode(rootvalue);
		if (preorderEnd - preorderBegin == 1) return root;

		int index;
		for (index = inorderBegin; index < inorderEnd; index++) {
			if (inorder[index] == rootvalue)
				break;
		}

		int leftinorderBegin = inorderBegin;
		int leftinorderEnd = index;

		int rightinorderBegin = index + 1;
		int rightinorderEnd = inorderEnd;

		int leftpreorderBegin = preorderBegin + 1;
		int leftpreorderEnd = preorderBegin + 1 + index - inorderBegin;

		int rightpreorderBegin = leftpreorderEnd;
		int rightpreorderEnd = preorderEnd;

		root->left = Helper(preorder, leftpreorderBegin, leftpreorderEnd, inorder, leftinorderBegin, leftinorderEnd);
		root->right = Helper(preorder, rightpreorderBegin, rightpreorderEnd, inorder, rightinorderBegin, rightinorderEnd);

		return root;
	}
};

void main() {}