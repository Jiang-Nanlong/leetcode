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
	bool isSubtree(TreeNode* root, TreeNode* subRoot) {
		if (root == nullptr) return false;
		return Helper(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
	}
private:
	bool Helper(TreeNode* p, TreeNode* q) {
		if (p == nullptr && q == nullptr) return true;
		if ((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr) || (p->val != q->val)) return false;
		return Helper(p->left, q->left) && Helper(p->right, q->right);
	}

public:
	//第二次做
	bool isSubtree1(TreeNode* root, TreeNode* subRoot) {
		if (root == nullptr) return false;
		return isSubtreeHelper(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);

	}
	bool isSubtreeHelper(TreeNode* root1, TreeNode* root2) {
		if (root1 == nullptr && root2 == nullptr) return true;
		else if (root1 == nullptr && root2 != nullptr) return false;
		else if (root1 != nullptr && root2 == nullptr) return false;
		else if (root1->val != root2->val) return false;

		return isSubtreeHelper(root1->left, root2->left) && isSubtreeHelper(root1->right, root2->right);
	}
};

void main() {

}