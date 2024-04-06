#include <iostream>
using namespace std;

//这题一看代码好简单，可是我又没想出来
//唉

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root->val > p->val && root->val > q->val)
			return lowestCommonAncestor(root->left, p, q);
		else if (root->val < p->val && root->val < q->val)
			return lowestCommonAncestor(root->right, p, q);
		else
			return root;
	}

	TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {
		while (root) {
			if (root->val > p->val && root->val > q->val)
				root = root->left;
			else if (root->val < p->val && root->val < q->val)
				root = root->right;
			else
				return root;
		}
		return nullptr;
	}

	//第二遍做还是没做出来，这个题的思路其实很简单，如果在遍历的过程中，当前节点的值第一次出现在p和q之间，那么当前节点就一定是最近公共祖先

	TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL) return NULL;

		if (root->val > p->val && root->val > q->val) {
			return lowestCommonAncestor(root->left, p, q);
		}
		else if (root->val < p->val && root->val < q->val) {
			return lowestCommonAncestor(root->right, p, q);
		}
		else
			return root;
	}

	TreeNode* lowestCommonAncestor3(TreeNode* root, TreeNode* p, TreeNode* q) {
		while (root) {
			if (root->val > p->val && root->val > q->val)
				root = root->left;
			else if (root->val < p->val && root->val < q->val)
				root = root->right;
			else
				return root;
		}
		return NULL;
	}
};

void main() {}
