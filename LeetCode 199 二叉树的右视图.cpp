#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//现在假设你站在整棵树的右边，输出往左看能看到的所有节点
struct TreeNode {
	int val;
	TreeNode* left, * right;
	TreeNode() :val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) :val(x), left(left), right(right) {}
};
class Solution {
public:
	vector<int> rightSideView(TreeNode* root) {    //其实就是层序遍历，在遍历的时候只有每一层最右边的节点才加入到结果集
		if (root == nullptr) return {};
		queue<TreeNode*> que;
		vector<int> res;
		que.push(root);
		while (!que.empty()) {
			int size = que.size();
			for (int i = 0; i < size; i++) {
				TreeNode* temp = que.front();
				que.pop();
				if (i == size - 1) res.push_back(temp->val);
				if (temp->left) que.push(temp->left);
				if (temp->right) que.push(temp->right);
			}
		}
		return res;
	}

	//第二次做
	vector<int> rightSideView1(TreeNode* root) {
		if (root == nullptr)
			return {};
		queue<TreeNode*> que;
		que.push(root);
		vector<int> res;
		while (!que.empty()) {
			int size = que.size();
			while (size--) {
				TreeNode* cur = que.front();
				que.pop();
				if (size == 0)
					res.push_back(cur->val);
				if (cur->left)
					que.push(cur->left);
				if (cur->right)
					que.push(cur->right);
			}
		}
		return res;
	}
};

void main() {}