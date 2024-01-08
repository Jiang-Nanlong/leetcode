#include <iostream>
#include <vector>
#include <stack>
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
	//先把最左边的节点依次入栈，然后出栈，如果出栈的节点有右子树的话，右子树继续按上述流程入栈
	//vector<int> inorderTraversal(TreeNode* root) {    //非递归中序遍历
	//	if (root == nullptr) return {};
	//	vector<int> res;
	//	stack<TreeNode*> stk;
	//	TreeNode* cur = root;
	//	while (cur != nullptr || !stk.empty()) {
	//		if (cur != nullptr) {
	//			stk.push(cur);
	//			cur = cur->left;
	//		}
	//		else {
	//			cur = stk.top();
	//			stk.pop();
	//			res.push_back(cur->val);
	//			cur = cur->right;
	//		}
	//	}
	//	return res;
	//}

	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		intravl(root, res);
		return res;
	}

private:
	void intravl(TreeNode* cur, vector<int>& res) {
		if (cur == nullptr) return;
		intravl(cur->left, res);
		res.push_back(cur->val);
		intravl(cur->right, res);
	}
};

void main() {

}