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
};

void main() {}