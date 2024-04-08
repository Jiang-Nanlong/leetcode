#include <iostream>
#include <queue>
using namespace std;

//将两个二叉树重叠，对位节点的值加一起

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
	TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
		//if (root1 == nullptr && root2 == nullptr) return nullptr;   //开始我把终止条件写错了
		if (root1 == nullptr) return root2;
		if (root2 == nullptr) return root1;

		TreeNode* root = new TreeNode();
		if (root1) root->val += root1->val;
		if (root2) root->val += root2->val;

		root->left = mergeTrees(root1->left, root2->left);
		root->right = mergeTrees(root1->right, root2->right);
		return root;
	}

	//还可以再精简一下，直接在root1上进行修改
	TreeNode* mergeTrees1(TreeNode* root1, TreeNode* root2) {
		if (root1 == nullptr) return root2;
		if (root2 == nullptr) return root1;

		//走到这一步说明两棵树的该结点都不为空
		root1->val += root2->val;  //这一句的位置任意，现在是前序遍历，如果修改这句话的位置，后序遍历和中序遍历也都可以

		root1->left = mergeTrees(root1->left, root2->left);
		root1->right = mergeTrees(root1->right, root2->right);
		return root1;
	}

	TreeNode* mergeTrees2(TreeNode* root1, TreeNode* root2) {
		if (root1 == nullptr) return root2;
		if (root2 == nullptr) return root1;

		queue<TreeNode*> que;
		que.push(root1);
		que.push(root2);
		while (!que.empty()) {
			TreeNode* cur1 = que.front(); que.pop();
			TreeNode* cur2 = que.front(); que.pop();
			cur1->val += cur2->val;
			if (cur1->left != nullptr && cur2->left != nullptr) {
				que.push(cur1->left);
				que.push(cur2->left);
			}
			if (cur1->right != nullptr && cur2->right != nullptr) {
				que.push(cur1->right);
				que.push(cur2->right);
			}
			if (cur1->left == nullptr && cur2->left != nullptr) //当root1的左节点为空，root2的左节点不为空时
				cur1->left = cur2->left;
			if (cur1->right == nullptr && cur2->right != nullptr)  //当root1的右节点为空，root2右节点不为空时
				cur1->right = cur2->right;
			//到这的时候我一直在想如果root1的左节点或右节点不为空，而root2的左节点或右节点为空，那么该怎么办？
			//后来才发现，如果root2的左节点或右节点为空的话，根本不需要做什么就行，因为这是在root1上修改，这样不用修改就行了。
		}
		return root1;
	}

	//第二次做	
	TreeNode* mergeTrees3(TreeNode* root1, TreeNode* root2) {
		if (root1 == nullptr && root2 == nullptr)
			return nullptr;
		if (root1 == nullptr)
			return root2;
		else if (root2 == nullptr)
			return root1;

		root1->val += root2->val;
		root1->left = mergeTrees(root1->left, root2->left);
		root1->right = mergeTrees(root1->right, root2->right);
		return root1;
	}

	TreeNode* mergeTrees4(TreeNode* root1, TreeNode* root2) {
		if (root1 == nullptr)
			return root2;
		if (root2 == nullptr)
			return root1;
		queue<TreeNode*> que;
		que.push(root1);
		que.push(root2);
		while (!que.empty()) {
			TreeNode* tree1 = que.front();
			que.pop();
			TreeNode* tree2 = que.front();
			que.pop();

			tree1->val += tree2->val;

			if (tree1->left && tree2->left) {
				que.push(tree1->left);
				que.push(tree2->left);
			}
			if (tree1->right && tree2->right) {
				que.push(tree1->right);
				que.push(tree2->right);
			}
			if (tree1->left == nullptr && tree2->left != nullptr)
				tree1->left = tree2->left;

			if (tree1->right == nullptr && tree2->right != nullptr)
				tree1->right = tree2->right;
		}
		return root1;
	}
};

void main() {}
