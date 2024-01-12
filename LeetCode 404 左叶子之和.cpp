#include <iostream>
#include <stack>
using namespace std;

//ע������Ҷ��֮�ͣ�����������֮��
//ʹ�õݹ��ǰ�����

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
	int result;
	int sumOfLeftLeaves(TreeNode* root) {
		result = 0;
		pretraversal(root);
		return result;
	}
	void pretraversal(TreeNode* root) {
		if (root == nullptr) return;
		if (root->left && root->left->left == nullptr && root->left->right == nullptr) { //�ж�root->left�ǲ�����Ҷ�� 
			result += root->left->val;
		}
		pretraversal(root->left);
		pretraversal(root->right);

	}

	//һ�´����Ǿ����Ľ��
	int sumOfLeftLeaves1(TreeNode* root) {
		if (root == nullptr) return 0;
		int result = 0;
		if (root->left && root->left->left == nullptr && root->left->right == nullptr)   //�ж��Ƿ�Ϊ��Ҷ��
			result = root->left->val;
		return result + sumOfLeftLeaves1(root->left) + sumOfLeftLeaves1(root->right);
	}

	//������ʹ�õ�������������ʹ��ǰ�к��򶼿���
	int sumOfLeftLeaves2(TreeNode* root) {
		if (root == nullptr) return 0;
		stack<TreeNode*> stk;
		stk.push(root);
		int result = 0;
		while (!stk.empty()) {
			TreeNode* cur = stk.top();
			stk.pop();
			if (cur->left && cur->left->left == nullptr && cur->left->right == nullptr)
				result += cur->left->val;
			if (cur->right) stk.push(cur->right);
			if (cur->left) stk.push(cur->left);
		}
		return result;
	}
};
void main() {}