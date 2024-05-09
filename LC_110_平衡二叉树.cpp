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


	//第二遍做，还是没做出来，这个题一个比较重要的地方是得用后序遍历。第一遍做的时候没体会出来为啥要用后序遍历，也没关注
	//现在第二遍再来做，感觉确实是只能用后序遍历，因为用前序求的话，在每一层内没法比较左右两颗子树的深度差。
	bool isBalanced1(TreeNode* root) {
		return getHeight(root) == -1 ? false : true;
	}
	int getHeight(TreeNode* root) {
		if (root == nullptr) return 0;
		int leftheight = getHeight(root->left);
		if (leftheight == -1) return -1;
		int rightheight = getHeight(root->right);
		if (rightheight == -1) return -1;
		if (abs(leftheight - rightheight) > 1)
			return -1;
		return 1 + max(leftheight, rightheight);
	}
};

void main() {}
