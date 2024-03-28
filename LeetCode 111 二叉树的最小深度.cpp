#include <iostream>
#include <queue>
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
	int minDepth(TreeNode* root) {
		if (root == nullptr) return 0;
		queue<TreeNode*> que;
		int count = 0;
		que.push(root);
		while (!que.empty()) {
			int size = que.size();
			count++;
			for (int i = 0; i < size; i++) {
				TreeNode* cur = que.front();
				que.pop();
				if (cur->left == nullptr && cur->right == nullptr) return count;   //到达第一个叶子结点的时候就返回
				if (cur->left) que.push(cur->left);
				if (cur->right) que.push(cur->right);
			}
		}
		return count;
	}
};

class Solution {
public:
	int result;
	void getDepth(TreeNode* node, int depth) {   //前序遍历的方式
		if (node == nullptr) return;
		if (node->left == nullptr && node->right == nullptr) {		//中
			result = min(result, depth);
		}
		if (node->left) {   //左
			getDepth(node->left, depth + 1);
		}
		if (node->right) {	//右
			getDepth(node->right, depth + 1);
		}
	}

	int minDepth1(TreeNode* root) {
		if (root == nullptr) return 0;
		result = INT_MAX;
		getDepth(root, 1);
		return result;
	}

	int getDepth1(TreeNode* node) {        //后序遍历
		if (node == nullptr) return 0;
		int leftDepth = getDepth1(node->left);
		int rightDepth = getDepth1(node->right);

		if (node->left == nullptr && node->right != nullptr)
			return 1 + rightDepth;
		if (node->left != nullptr && node->right == nullptr)
			return 1 + leftDepth;
		int result = 1 + min(leftDepth, rightDepth);
		return result;
	}
	int minDepth2(TreeNode* root) {
		return getDepth1(root);
	}


	//第二次做
	int mindepth = INT_MAX;
	int minDepth2(TreeNode* root) {
		if (root == nullptr) return 0;
		backtrace1(root, 0);
		return mindepth;
	}
	void backtrace1(TreeNode* root, int depth) {
		if ((root->left == nullptr) && (root->right == nullptr)) {  //前序遍历，求的是深度，后序遍历求的是高度
			mindepth = min(mindepth, depth + 1);
			return;
		}
		if (root->left)
			backtrace1(root->left, depth + 1);
		if (root->right)
			backtrace1(root->right, depth + 1);
	}

	int minDepth3(TreeNode* root) {
		return getminDepth(root);
	}

	int getminDepth(TreeNode* root) {   //后序遍历
		if (root == nullptr) return 0;
		int leftDepth = getminDepth(root->left);
		int rightDepth = getminDepth(root->right);

		if (root->left == nullptr && root->right)
			return 1 + rightDepth;
		if (root->left && root->right == nullptr)
			return 1 + leftDepth;

		return 1 + min(leftDepth, rightDepth);
	}
};

void main() {}