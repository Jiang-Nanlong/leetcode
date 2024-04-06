#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
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
	//前序遍历的顺序是中左右，然后在函数体内调换一下左右节点的顺序，就成了中右左了。而后序遍历是左右中，所以只需要把中右左的顺序对调一下就行了左右中了。
	vector<int> postorderTraversal1(TreeNode* root) {     //非递归后序遍历
		if (root == nullptr) return {};
		vector<int>res;
		stack<TreeNode*> stk;
		stk.push(root);
		while (!stk.empty()) {
			TreeNode* cur = stk.top();
			stk.pop();
			res.push_back(cur->val);
			if (cur->left) stk.push(cur->left);
			if (cur->right) stk.push(cur->right);
		}
		reverse(res.begin(), res.end());
		return res;
	}

	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> res;
		posttravl(root, res);
		return res;
	}

private:
	void posttravl(TreeNode* cur, vector<int>& res) {
		if (cur == nullptr) return;
		posttravl(cur->left, res);
		posttravl(cur->right, res);
		res.push_back(cur->val);
	}
};

void main() {

}
