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
				if (cur->left == nullptr && cur->right == nullptr) return count;   //�����һ��Ҷ�ӽ���ʱ��ͷ���
				if (cur->left) que.push(cur->left);
				if (cur->right) que.push(cur->right);
			}
		}
		return count;
	}
};

class Solution {
public:
	int result;
	void getDepth(TreeNode* node, int depth) {   //ǰ������ķ�ʽ
		if (node == nullptr) return;
		if (node->left == nullptr && node->right == nullptr) {		//��
			result = min(result, depth);
		}
		if (node->left) {   //��
			getDepth(node->left, depth + 1);
		}
		if (node->right) {	//��
			getDepth(node->right, depth + 1);
		}
	}

	int minDepth1(TreeNode* root) {
		if (root == nullptr) return 0;
		result = INT_MAX;
		getDepth(root, 1);
		return result;
	}

	int getDepth1(TreeNode* node) {        //�������
		if (node == nullptr) return 0;
		int leftDepth = getDepth1(node->left);
		int rightDepth = getDepth1(node->right);

		if (node->left == nullptr && node->right != nullptr)
			return 1 + rightDepth;
		if (node->left != nullptr && node->right == nullptr)
			return 1 + leftDepth;
		int result = 1 + min(leftDepth, rightDepth);
		return result;
	}
	int minDepth2(TreeNode* root) {
		return getDepth1(root);
	}
};

void main() {}