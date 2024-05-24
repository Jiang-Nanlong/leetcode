#include <iostream>
#include <stack>
#include <queue>
using namespace std;

//�Ƚ�һ���������ǲ�����Գ�
//�������Ĺؼ��ǱȽ������Գ�λ���Ƿ����,�ȿ����õݹ�ʵ�֣�Ҳ������ջ�����ʵ�֡�
//��ʹ��ջ�����ʱ��ÿ�ζ��ǳ��ӻ��ջǰ�������бȽϣ���������ջ����ӵ�ʱ��Ҳ���������ԳƵ���ջ�������ڳ���ʱ��Ҳ�������ĳ������бȽ�

struct TreeNode {
	int val;
	TreeNode* left, * right;
	TreeNode() :val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) :val(x), left(left), right(right) {}
};

class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		return Helper(root, root);
	}
private:
	bool Helper(TreeNode* n1, TreeNode* n2) {   //�ݹ鴦��
		if (n1 == nullptr && n2 == nullptr) return true;
		if (n1 == nullptr || n2 == nullptr) return false;
		return (n1->val == n2->val) && Helper(n1->left, n2->right) && Helper(n1->right, n2->left);
	}

public:
	bool isSymmetricByQueue(TreeNode* root) {
		if (root == nullptr) return true;
		queue<TreeNode*> que;
		que.push(root->left);
		que.push(root->right);
		while (!que.empty()) {
			TreeNode* leftNode = que.front();
			que.pop();
			TreeNode* rightNode = que.front();
			que.pop();
			if (leftNode == nullptr && rightNode == nullptr) continue;
			if (leftNode == nullptr || rightNode == nullptr || leftNode->val != rightNode->val) return false;
			que.push(leftNode->left);
			que.push(rightNode->right);
			que.push(leftNode->right);
			que.push(rightNode->left);
		}
		return true;
	}

	bool isSymmetricByStack(TreeNode* root) {
		if (root == nullptr) return true;
		stack<TreeNode*> stk;
		stk.push(root->left);
		stk.push(root->right);
		while (!stk.empty()) {
			TreeNode* leftNode = stk.top();
			stk.pop();
			TreeNode* rightNode = stk.top();
			stk.pop();
			if (leftNode == nullptr && rightNode == nullptr) continue;
			if (leftNode == nullptr || rightNode == nullptr || leftNode->val != rightNode->val) return false;
			stk.push(leftNode->left);
			stk.push(rightNode->right);
			stk.push(leftNode->right);
			stk.push(rightNode->left);
		}
		return true;
	}


	//�ڶ�����
	bool isSymmetric1(TreeNode* root) { return isSymmetricHelper(root, root); }
	bool isSymmetricHelper(TreeNode* root1, TreeNode* root2) {
		if (root1 == nullptr && root2 == nullptr)
			return true;
		if (root1 == nullptr || root2 == nullptr)
			return false;
		bool flag = root1->val == root2->val;
		if (flag) {
			bool flag1 = isSymmetricHelper(root1->left, root2->right);
			bool flag2 = isSymmetricHelper(root1->right, root2->left);
			return flag1 && flag2;
		}
		else
			return false;
	}
	//isSymmetricHelper1û�м�֮ǰ���߼�
	bool isSymmetricHelper1(TreeNode* root1, TreeNode* root2) {
		if (root1 == nullptr && root2 == nullptr)
			return true;
		else if (root1 == nullptr && root2 != nullptr)
			return false;
		else if (root1 != nullptr && root2 == nullptr)
			return false;
		else if (root1->val != root2->val)
			return false;

		bool flag1 = isSymmetricHelper(root1->left, root2->right);
		bool flag2 = isSymmetricHelper(root1->right, root2->left);
		return flag1 && flag2;
	}

	// ����������
	bool isSymmetric2(TreeNode* root) {
		return backtrace(root->left, root->right);
	}

	bool backtrace(TreeNode* left, TreeNode* right) {
		if (left == nullptr && right == nullptr)
			return true;
		if ((!left && right) || (left && !right))
			return false;

		return left->val == right->val && backtrace(left->left, right->right) && backtrace(left->right, right->left);
	}
};

void main() {}