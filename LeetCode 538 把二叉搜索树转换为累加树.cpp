#include <iostream>
using namespace std;

//这个题是要把每个节点的值换为大于或等于该结点的值的所有节点值的和。
//因为这是二叉搜索树，显然最大的数在右下角，所以大于等于该结点值的结点都在其右边，所以只要按着右中左的顺序就行。这正好是中序遍历的逆序。

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
	int pre = 0;
	TreeNode* convertBST(TreeNode* root) {
		if (root == nullptr) return nullptr;
		convertBST(root->right);
		root->val += pre;
		pre = root->val;
		convertBST(root->left);

		return root;
	}
};

void main() {}