#include <iostream>
#include <algorithm>
using namespace std;

//判断一个数是不是平衡二叉树

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
	bool isBalanced(TreeNode* root) {
		return Height(root) == -1 ? false : true;
	}
	int Height(TreeNode* node) {  //注意递归三要素
		if (node == nullptr) return 0;

		int leftHeight = Height(node->left);
		if (leftHeight == -1) return -1;
		int rightHeight = Height(node->right);
		if (rightHeight == -1) return -1;
		return abs(leftHeight - rightHeight) > 1 ? -1 : 1 + max(leftHeight, rightHeight);
	}
};

void main() {}