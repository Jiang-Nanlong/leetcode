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

	//第二次做，做错了
	bool hasPathSum1(TreeNode* root, int targetSum) {
		if (root == nullptr)
			return false;
		return hasPathSumHelper(root, targetSum, 0);
	}
	bool hasPathSumHelper(TreeNode* root, int targetSum, int sum) {
		if (root == nullptr && sum == targetSum)  //这个地方不应该是root==nullptr，因为对于[1,2]，target=1，这种情况时，会直接在1的右子树返回true，
			//而这个右子树为空，1也不是叶子结点。所以要修改判断条件，最后到叶子结点就行了，不用再往下了
			return true;

		if (root == nullptr && sum != targetSum)
			return false;

		bool leftflag =
			hasPathSumHelper(root->left, targetSum, sum + root->val);
		if (leftflag)
			return true;
		bool rightflag =
			hasPathSumHelper(root->right, targetSum, sum + root->val);
		if (rightflag)
			return true;
		return leftflag || rightflag;
	}

	//改完以后
	bool hasPathSum2(TreeNode* root, int targetSum) {
		if (root == nullptr)
			return false;
		return hasPathSumHelper(root, targetSum, 0);
	}
	bool hasPathSumHelper(TreeNode* root, int targetSum, int sum) {
		if (root->left == nullptr && root->right == nullptr) {
			if ((sum + root->val) == targetSum)
				return true;
			else
				return false;
		}

		if (root->left)
			if (hasPathSumHelper(root->left, targetSum, sum + root->val))
				return true;

		if (root->right)
			if (hasPathSumHelper(root->right, targetSum, sum + root->val))
				return true;

		return false;  //这里也不用写成return leftflag || rightflag;，因为如果前边有true就直接返回了，根本到不了这里
	}
};

void main() {}