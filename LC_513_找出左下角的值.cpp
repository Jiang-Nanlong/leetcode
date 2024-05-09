#include <iostream>
#include <queue>
using namespace std;

//题目要求是找出二叉树左下角的值，即最后一排第一个值。很容易想到用层序遍历。
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
	int findBottomLeftValue(TreeNode* root) {
		queue<TreeNode*> que;
		que.push(root);
		int result = 0;
		while (!que.empty()) {
			int size = que.size();
			for (int i = 0; i < size; i++) {
				TreeNode* cur = que.front();
				que.pop();
				if (i == 0) result = cur->val;
				if (cur->left) que.push(cur->left);
				if (cur->right) que.push(cur->right);
			}
		}
		return result;
	}
};

//递归法也能做
class Solution1 {
public:
	int result;
	int maxDepth = INT_MIN;
	void traversal(TreeNode* node, int depth) {
		if (node->left == nullptr && node->right == nullptr) {
			if (depth > maxDepth) {
				maxDepth = depth;
				result = node->val;
			}
			return;
		}
		//开始的时候我想不明白是怎么保留最后一层叶子节点的最左边一个的。
		//后来发现，正是因为左右的遍历顺序，这么result保留的一定是第一个叶子结点。因为先左后右，先判断左子树是不是叶子，如果是就保留了
		//然后因为if(depth>maxDepth)，所以同一层的其余叶子就不会再考虑了。
		if (node->left) traversal(node->left, depth + 1);
		if (node->right) traversal(node->right, depth + 1);
	}

	int findBottomLeftValue(TreeNode* root) {
		traversal(root, 1);
		return result;
	}
	//这个题最简单的就是用层序遍历来做。用递归法的话不太好做，因为要找最后一层第一个节点的值，所以随便前中后序都行，只要左孩子比右孩子优先就行，这样在更新最大深度的同时，保存使得最大深度更新的节点的值就行。
	//这个题最简单的就是用层序遍历来做。用递归法的话不太好做，因为要找最后一层第一个节点的值，所以随便前中后序都行，只要左孩子比右孩子优先就行，这样在更新最大深度的同时，保存使得最大深度更新的节点的值就行。
};

void main() {}
