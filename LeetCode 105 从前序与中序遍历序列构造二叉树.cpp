#include <iostream>
#include <vector>
using namespace std;

//������LeetCode 106 һ���������ص�����ȷ�����ڵ㣬Ȼ��ָ��������������С�

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

	//�ڶ�������ֱ��ʹ���Ż���ĳ���
	TreeNode* buildTree1(vector<int>& preorder, vector<int>& inorder) {
		return buildTreeHelper(preorder, 0, preorder.size(), inorder, 0,
			inorder.size());
	}
	TreeNode* buildTreeHelper(vector<int>& preorder, int preorderbegin,
		int preorderend, vector<int>& inorder,
		int inorderbegin, int inorderend) {
		if (inorderbegin == inorderend)
			return nullptr;
		int rootvalue = preorder[preorderbegin];
		TreeNode* root = new TreeNode(rootvalue);
		int rootvalueIndexofInorder = inorderbegin;
		for (; rootvalueIndexofInorder < inorderend; rootvalueIndexofInorder++)
			if (inorder[rootvalueIndexofInorder] == rootvalue)
				break;

		int leftinorderbegin = inorderbegin,
			leftinorderend = rootvalueIndexofInorder;
		int leftpreorderbegin = preorderbegin + 1,
			leftpreorderend =
			preorderbegin + 1 + rootvalueIndexofInorder - inorderbegin;

		int rightinorderbegin = leftinorderend + 1,
			rightinorderend = inorderend;
		int rightpreorderbegin = leftpreorderend,
			rightpreorderend = preorderend;

		root->left =
			buildTreeHelper(preorder, leftpreorderbegin, leftpreorderend,
				inorder, leftinorderbegin, leftinorderend);
		root->right =
			buildTreeHelper(preorder, rightpreorderbegin, rightpreorderend,
				inorder, rightinorderbegin, rightinorderend);
		return root;
	}
};

void main() {}