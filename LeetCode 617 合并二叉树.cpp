#include <iostream>
#include <queue>
using namespace std;

//�������������ص�����λ�ڵ��ֵ��һ��

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
		//if (root1 == nullptr && root2 == nullptr) return nullptr;   //��ʼ�Ұ���ֹ����д����
		if (root1 == nullptr) return root2;
		if (root2 == nullptr) return root1;

		TreeNode* root = new TreeNode();
		if (root1) root->val += root1->val;
		if (root2) root->val += root2->val;

		root->left = mergeTrees(root1->left, root2->left);
		root->right = mergeTrees(root1->right, root2->right);
		return root;
	}

	//�������پ���һ�£�ֱ����root1�Ͻ����޸�
	TreeNode* mergeTrees1(TreeNode* root1, TreeNode* root2) {
		if (root1 == nullptr) return root2;
		if (root2 == nullptr) return root1;

		//�ߵ���һ��˵���������ĸý�㶼��Ϊ��
		root1->val += root2->val;  //��һ���λ�����⣬������ǰ�����������޸���仰��λ�ã�����������������Ҳ������

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
			if (cur1->left == nullptr && cur2->left != nullptr) //��root1����ڵ�Ϊ�գ�root2����ڵ㲻Ϊ��ʱ
				cur1->left = cur2->left;
			if (cur1->right == nullptr && cur2->right != nullptr)  //��root1���ҽڵ�Ϊ�գ�root2�ҽڵ㲻Ϊ��ʱ
				cur1->right = cur2->right;
			//�����ʱ����һֱ�������root1����ڵ���ҽڵ㲻Ϊ�գ���root2����ڵ���ҽڵ�Ϊ�գ���ô����ô�죿
			//�����ŷ��֣����root2����ڵ���ҽڵ�Ϊ�յĻ�����������Ҫ��ʲô���У���Ϊ������root1���޸ģ����������޸ľ����ˡ�
		}
		return root1;
	}

	//�ڶ�����	
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