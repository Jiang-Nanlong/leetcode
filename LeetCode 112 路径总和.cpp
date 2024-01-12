#include <iostream>
using namespace std;

//判断一个树中是否存在一个从根节点到叶子结点的路径，路径上节点的和等于targetSum，如果有，返回true，如果没有，返回false。
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
	bool hasPathSum(TreeNode* root, int targetSum) {
		if (root == nullptr) return false;
		return Helper(root, targetSum, 0);
	}

	bool Helper(TreeNode* node, int targetSum, int sum) {
		sum += node->val;
		if (node->left == nullptr && node->right == nullptr) {
			if (sum == targetSum) return true;
		}
		if (node->left) {
			if (Helper(node->left, targetSum, sum)) return true;
		}
		if (node->right) {
			if (Helper(node->right, targetSum, sum)) return true;
		}
		return false;
	}
};

void main() {}