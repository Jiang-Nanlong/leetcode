#include <iostream>
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
	TreeNode* insertIntoBST(TreeNode* root, int val) {  //�ݹ�
		if (root == nullptr) {
			TreeNode* temp = new TreeNode(val);
			return temp;
		}

		if (root->val > val) root->left = insertIntoBST(root->left, val);
		if (root->val < val) root->right = insertIntoBST(root->right, val);

		return root;
	}

	//�ݹ麯��Ҳ����û�з���ֵ������Ҫ��¼ǰһ���ڵ�
	TreeNode* parent;
	void Helper(TreeNode* cur, int val) {
		if (cur == nullptr) {
			cur = new TreeNode(val);
			if (parent->val > val) parent->left = cur;
			else parent->right = cur;
			return;
		}
		parent = cur;
		if (cur->val > val) Helper(cur->left, val);
		if (cur->val < val) Helper(cur->right, val);
		return;
	}
	TreeNode* insertIntoBST2(TreeNode* root, int val) {
		parent = nullptr;
		if (root == nullptr) {
			root = new TreeNode(val);
			return root;
		}
		Helper(root, val);
		return root;

	}

	//����
	TreeNode* insertIntoBST1(TreeNode* root, int val) {
		if (root == nullptr) {
			root = new TreeNode(val);
			return root;
		}
		TreeNode* parent = nullptr, * cur = root;

		while (cur) {
			parent = cur;
			if (cur->val > val)
				cur = cur->left;
			else if (cur->val < val)
				cur = cur->right;
			else break;
		}
		TreeNode* temp = new TreeNode(val);
		if (val < parent->val) parent->left = temp;
		else parent->right = temp;
		return root;
	}

	//�ڶ�����
	TreeNode* insertIntoBST3(TreeNode* root, int val) {
		TreeNode* insertNode = new TreeNode(val);

		if (root == nullptr) return insertNode;
		TreeNode* pre;
		TreeNode* cur = root;
		while (cur) {
			if (val > cur->val) {
				pre = cur;
				cur = cur->right;
			}
			else if (val < cur->val) {
				pre = cur;
				cur = cur->left;
			}
		}
		if (val < pre->val) {
			pre->left = insertNode;
		}
		else {
			pre->right = insertNode;
		}
		return root;
	}

	//������뻹��ͦ�ɵģ�������ֻд���˴�����void����ֵ�ĺ���
	TreeNode* insertIntoBST4(TreeNode* root, int val) {
		if (root == nullptr) {
			return new TreeNode(val);
		}
		if (root->val > val)
			root->left = insertIntoBST(root->left, val);
		if (root->val < val)
			root->right = insertIntoBST(root->right, val);
		return root;
	}
	//��ֻ��д�±����ֵݹ�
	TreeNode* insertIntoBST5(TreeNode* root, int val) {
		if (root == nullptr)
			return new TreeNode(val);
		insertIntoBSTHelper(root, val);
		return root;
	}

	TreeNode* parent = nullptr;
	void insertIntoBSTHelper(TreeNode* root, int val) {
		if (root == nullptr) {
			TreeNode* insertNode = new TreeNode(val);
			if (parent->val > val)
				parent->left = insertNode;
			else
				parent->right = insertNode;
			return;
		}
		parent = root;
		if (root->val > val)
			insertIntoBSTHelper(root->left, val);
		if (root->val < val)
			insertIntoBSTHelper(root->right, val);
	}
};

void main() {

}