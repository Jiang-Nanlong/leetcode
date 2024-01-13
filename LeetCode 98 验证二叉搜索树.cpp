#include <iostream>
#include <stack>
using namespace std;

//验证一个树是不是二叉搜索树。下边这是用递归实现，感觉有点难理解。其实这个思路就是记录前一个节点的值，如果前一个节点比后一个节点的值还大，那肯定不是二叉搜索树
//其实还是利用的二叉搜索树的中序遍历是递增序列，这一特性。
// 另外还可以直接中序遍历一下，因为二叉搜索树的中序遍历结果是递增的。

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
	long long lastvalue = LONG_MIN;  //这里定义成longlong是因为测试用例里有一个INT_MIN，为了比它更小所以设成longlong。
	//这样写也不太好，如果二叉树里有一个节点的值是LONG_MIN，那么这里设置成LONG_MIN就又不行了，接下来直接返回false了。
	bool isValidBST(TreeNode* root) {
		if (root == nullptr) return true;

		bool left = isValidBST(root->left);
		if (root->val > lastvalue) lastvalue = root->val;
		else return false;

		bool right = isValidBST(root->right);
		return left && right;
	}

	//所以基于上一个longlong的问题，这里可以直接记录前一个节点的指针，然后比较两个指针指向的节点的值的大小
	TreeNode* pre = nullptr;
	bool isValidBST1(TreeNode* root) {
		if (root == nullptr) return true;
		bool left = isValidBST1(root->left);

		if (pre && root->val <= pre->val) return false;   //这里需要判断pre是不是为空，因为遍历第一个节点的时候pre是null
		pre = root;

		bool right = isValidBST1(root->right);
		return left && right;
	}

	//因为这是用中序遍历实现的，所以用迭代的中序遍历也可以实现。
	bool isValidBST2(TreeNode* root) {
		if (root == nullptr) return true;
		stack<TreeNode*>stk;
		TreeNode* cur = root;
		TreeNode* pre = nullptr;
		while (cur || !stk.empty()) {
			if (cur) {
				stk.push(cur);
				cur = cur->left;
			}
			else {
				cur = stk.top();
				stk.pop();
				if (pre && pre->val >= cur->val)
					return false;
				pre = cur;
				cur = cur->right;
			}
		}
		return true;
	}
};

void main() {}