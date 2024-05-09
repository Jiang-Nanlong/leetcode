#include <iostream>
#include <queue>
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
	/*int maxDepth(TreeNode* root) {
		if (root == nullptr) return 0;
		queue<TreeNode*> que;
		int count = 0;
		que.push(root);
		while (!que.empty()) {
			int size = que.size();
			for (int i = 0; i < size; i++) {
				TreeNode* cur = que.front();
				que.pop();
				if (cur->left) que.push(cur->left);
				if (cur->right) que.push(cur->right);
			}
			count++;
		}
		return count;
	}*/

	int maxDepth(TreeNode* root) {   //这个题也可以用深度优先搜索来做
		return dfs(root);
	}
private:
	int dfs(TreeNode* root) {
		if (root == nullptr) return 0;
		return max(dfs(root->left), dfs(root->right)) + 1;
	}
};

//还可以使用前序遍历来求树的深度,还是用了回溯，这一解法与LeetCode 257 二叉树的所有路径一样
class Solution1 {
public:
	int result;
	void getDepth(TreeNode* node, int depth) {
		result = depth > result ? depth : result;  //中
		if (node->left == nullptr && node->right == nullptr) return;
		if (node->left) {   //左
			depth++;
			getDepth(node->left, depth);
			depth--;
		}
		if (node->right) {   //右
			depth++;
			getDepth(node->right, depth);
			depth--;
		}
	}

	//上述代码还可以再精简一下，隐藏回溯
	void getDepth1(TreeNode* node, int depth) {
		result = depth > result ? depth : result;
		if (node->left == nullptr && node->right == nullptr) return;
		if (node->left) getDepth1(node->left, depth + 1);
		if (node->right) getDepth1(node->right, depth + 1);
	}
	int maxDepth(TreeNode* root) {
		result = 0;
		if (root == nullptr) return 0;
		getDepth(root, 1);
		return result;
	}

	//第二次做，层序遍历
	int maxDepth(TreeNode* root) {
		if (root == nullptr) return 0;
		queue<TreeNode*>que;
		que.push(root);
		int depth = 0;
		while (!que.empty()) {
			int size = que.size();
			while (size--) {
				TreeNode* cur = que.front();
				que.pop();
				if (cur->left) que.push(cur->left);
				if (cur->right) que.push(cur->right);
			}
			depth++;
		}
		return depth;
	}

	//第二次做，递归
	int maxdepth = 0;
	int maxDepth(TreeNode* root) {
		backtrace1(root, 0);
		return maxdepth;
	}

private:
	void backtrace1(TreeNode* root, int depth) {  //前序遍历
		if (root == nullptr) {
			maxdepth = max(depth, maxdepth);
			return;
		}
		backtrace1(root->left, depth + 1);
		backtrace1(root->right, depth + 1);
	}

public:
	int maxDepth(TreeNode* root) {
		return backtrace2(root);
	}

private:
	int backtrace2(TreeNode* root) {   //后序遍历
		if (root == nullptr) return 0;

		int leftdepth = backtrace2(root->left);
		int rightdepth = backtrace2(root->right);
		return 1 + max(leftdepth, rightdepth);
	}
};

void main() {}
