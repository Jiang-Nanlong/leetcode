#include <iostream>
#include <queue>
using namespace std;

//返回二叉树的每一层的平均值

struct TreeNode {
	int val;
	TreeNode* left, * right;
	TreeNode() :val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) :val(x), left(left), right(right) {}
};

class Solution {
public:
	vector<double> averageOfLevels(TreeNode* root) {
		if (root == nullptr) return {};
		queue<TreeNode*> que;
		vector<double> res;
		que.push(root);
		while (!que.empty()) {
			int size = que.size();
			double sum = 0;
			for (int i = 0; i < size; i++) {
				TreeNode* temp = que.front();
				que.pop();
				sum += temp->val;
				if (temp->left) que.push(temp->left);
				if (temp->right) que.push(temp->right);
			}
			res.push_back(sum / size);
		}
		return res;
	}

	//第二次做
	vector<double> averageOfLevels1(TreeNode* root) {
		if (root == nullptr)
			return {};
		queue<TreeNode*> que;
		que.push(root);
		vector<double> res;
		while (!que.empty()) {
			int size = que.size();
			int count = size;
			double sum = 0;
			while (size--) {
				TreeNode* cur = que.front();
				que.pop();
				sum += cur->val;
				if (cur->left)
					que.push(cur->left);
				if (cur->right)
					que.push(cur->right);
			}
			sum /= count;
			res.push_back(sum);
		}
		return res;
	}
};

void main() {}
