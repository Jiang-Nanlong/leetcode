#include <iostream>
#include <queue>
#include <algorithm>
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
	/*int maxDepth(TreeNode* root) {
		if (root == nullptr) return 0;
		queue<TreeNode*> que;
		int count = 0;
		que.push(root);
		while (!que.empty()) {
			int size = que.size();
			for (int i = 0; i < size; i++) {
				TreeNode* cur = que.front();
				que.pop();
				if (cur->left) que.push(cur->left);
				if (cur->right) que.push(cur->right);
			}
			count++;
		}
		return count;
	}*/

	int maxDepth(TreeNode* root) {   //�����Ҳ���������������������
		return dfs(root);
	}
private:
	int dfs(TreeNode* root) {
		if (root == nullptr) return 0;
		return max(dfs(root->left), dfs(root->right)) + 1;
	}
};

//������ʹ��ǰ����������������,�������˻��ݣ���һ�ⷨ��LeetCode 257 ������������·��һ��
class Solution1 {
public:
	int result;
	void getDepth(TreeNode* node, int depth) {
		result = depth > result ? depth : result;  //��
		if (node->left == nullptr && node->right == nullptr) return;
		if (node->left) {   //��
			depth++;
			getDepth(node->left, depth);
			depth--;
		}
		if (node->right) {   //��
			depth++;
			getDepth(node->right, depth);
			depth--;
		}
	}

	//�������뻹�����پ���һ�£����ػ���
	void getDepth1(TreeNode* node, int depth) {
		result = depth > result ? depth : result;
		if (node->left == nullptr && node->right == nullptr) return;
		if (node->left) getDepth1(node->left, depth + 1);
		if (node->right) getDepth1(node->right, depth + 1);
	}
	int maxDepth(TreeNode* root) {
		result = 0;
		if (root == nullptr) return 0;
		getDepth(root, 1);
		return result;
	}

	//�ڶ��������������
	int maxDepth(TreeNode* root) {
		if (root == nullptr) return 0;
		queue<TreeNode*>que;
		que.push(root);
		int depth = 0;
		while (!que.empty()) {
			int size = que.size();
			while (size--) {
				TreeNode* cur = que.front();
				que.pop();
				if (cur->left) que.push(cur->left);
				if (cur->right) que.push(cur->right);
			}
			depth++;
		}
		return depth;
	}

	//�ڶ��������ݹ�
	int maxdepth = 0;
	int maxDepth(TreeNode* root) {
		backtrace(root, 0);
		return maxdepth;
	}

private:
	void backtrace(TreeNode* root, int depth) {
		if (root == nullptr) {
			maxdepth = max(depth, maxdepth);
			return;
		}
		backtrace(root->left, depth + 1);
		backtrace(root->right, depth + 1);
	}
};

void main() {}