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
	//非递归前序遍历，要把每一个节点的右节点先入栈，然后才是左节点入栈，只有这样，左子树中的所有节点才都在右节点的上边，出栈的时候就提前遍历了。
	//为了让出栈时是中左右，入栈的时候就得是中右左
	vector<int> preorderTraversal1(TreeNode* root) {  //非递归前序遍历
		if (root == nullptr) return{};
		stack<TreeNode*> stk;
		vector<int> res;
		stk.push(root);
		while (!stk.empty()) {
			TreeNode* cur = stk.top();
			stk.pop();
			res.push_back(cur->val);
			if (cur->right) stk.push(cur->right);
			if (cur->left) stk.push(cur->left);
		}
		return res;
	}

	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		pretravl(root, res);
		return res;
	}

private:
	void pretravl(TreeNode* cur, vector<int>& res) {
		if (cur == nullptr) return;
		res.push_back(cur->val);
		pretravl(cur->left, res);
		pretravl(cur->right, res);
	}
};

void main() {

}