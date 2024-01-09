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

void main() {}