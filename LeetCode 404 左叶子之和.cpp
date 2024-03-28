#include <iostream>
#include <stack>
using namespace std;

//注意是左叶子之和，不是左子树之和
//使用递归的前序遍历

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
	int result;
	int sumOfLeftLeaves(TreeNode* root) {
		result = 0;
		pretraversal(root);
		return result;
	}
	void pretraversal(TreeNode* root) {
		if (root == nullptr) return;
		if (root->left && root->left->left == nullptr && root->left->right == nullptr) { //判断root->left是不是左叶子 
			result += root->left->val;
		}
		pretraversal(root->left);
		pretraversal(root->right);

	}

	//一下代码是精简后的结果
	int sumOfLeftLeaves1(TreeNode* root) {
		if (root == nullptr) return 0;
		int result = 0;
		if (root->left && root->left->left == nullptr && root->left->right == nullptr)   //判断是否为左叶子
			result = root->left->val;
		return result + sumOfLeftLeaves1(root->left) + sumOfLeftLeaves1(root->right);
	}

	//还可以使用迭代法，迭代法使用前中后序都可以
	int sumOfLeftLeaves2(TreeNode* root) {
		if (root == nullptr) return 0;
		stack<TreeNode*> stk;
		stk.push(root);
		int result = 0;
		while (!stk.empty()) {
			TreeNode* cur = stk.top();
			stk.pop();
			if (cur->left && cur->left->left == nullptr && cur->left->right == nullptr)
				result += cur->left->val;
			if (cur->right) stk.push(cur->right);
			if (cur->left) stk.push(cur->left);
		}
		return result;
	}

	//第二次做
	int sumOfLeftLeaves3(TreeNode* root) {
		int sum = 0;
		getSum(root, sum);
		return sum;
	}

	void getSum(TreeNode* root, int& sum) {
		if (root->left && root->left->left == nullptr && root->left->right == 0) {
			sum += root->left->val;
		}
		if (root->left)
			getSum(root->left, sum);
		if (root->right)
			getSum(root->right, sum);
	}

	//这是代码随想录的程序，用的后序遍历，从没想过可以这样写
	int sumOfLeftLeaves4(TreeNode* root) {
		if (root == nullptr)
			return 0;
		if (root->left == nullptr && root->right == nullptr)
			return 0;
		int leftvalue = sumOfLeftLeaves(root->left);
		if (root->left && root->left->left == nullptr && root->left->right == nullptr)  //左子树就是一个左叶子的情况
			leftvalue = root->left->val;
		int rightvalue = sumOfLeftLeaves(root->right);
		return leftvalue + rightvalue;
	}
};
void main() {}