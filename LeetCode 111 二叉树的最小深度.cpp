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

void main() {}