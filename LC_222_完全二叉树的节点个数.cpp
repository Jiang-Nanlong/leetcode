#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left, * right;
	TreeNode() :val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) :val(x), left(left), right(right) {}
};

class Solution {
public:
	int countNodes(TreeNode* root) {   //层序遍历
		if (root == nullptr) return 0;
		queue<TreeNode*> que;
		int count = 0;
		que.push(root);
		while (!que.empty()) {
			int size = que.size();
			count += size;
			for (int i = 0; i < size; i++) {
				TreeNode* cur = que.front();
				que.pop();
				if (cur->left) que.push(cur->left);
				if (cur->right) que.push(cur->right);
			}
		}
		return count;

	}

	//还可以用递归来做
	//int getNodesNum(TreeNode* cur) {  //确定递归函数的参数和返回值
	//	if (cur == nullptr) return 0;   //确定终止条件
	//	//确定单层递归逻辑>>>
	//	int leftNum = getNodesNum(cur->left);
	//	int rightNum = getNodesNum(cur->right);
	//	int treeNum = 1 + leftNum + rightNum;
	//	return treeNum;
	//	//确定单层递归逻辑<<<
	//}
	//int countNodes(TreeNode* root) {
	//	return getNodesNum(root);
	//}
	//简化为下边这种，但是已经看不出递归三要素了

	/*int countNodes(TreeNode* root) {
		if (root == nullptr) return 0;
		return 1 + countNodes(root->left) + countNodes(root->right);
	}*/

	//下边是代码随想录的方法，这个方法比较巧妙
	//如果一个树是完全二叉树，那么他的节点数会有两种情况：
	//1.这是一棵满二叉树
	//2.这是一个完全二叉树
	//如果是满二叉树，就可以直接通过深度求节点数，如果不是满二叉树，就分别遍历他的左子树和右子树，如果子树是满二叉树就通过深度求节点数。
	int countNodes1(TreeNode* root) {
		if (root == nullptr)
			return 0;
		TreeNode* left = root->left;
		TreeNode* right = root->right;
		int leftdepth = 0, rightdepth = 0;
		while (left) { //这两个while循环用来判断完全二叉树是不是满二叉树，因为已经是完全二叉树了，如果两边的深度相同的话，那么就是一棵满二叉树
			leftdepth++;
			left = left->left;
		}
		while (right) {
			rightdepth++;
			right = right->right;
		}

		if (rightdepth == leftdepth) {
			return (2 << leftdepth) - 1;
		}
		return 1 + countNodes(root->left) + countNodes(root->right);
	}
};

void main() {}
