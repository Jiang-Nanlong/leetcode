#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() :val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) :val(x), left(left), right(right) {}
};

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		queue<TreeNode*> que;
		vector<vector<int>> res;
		if (root == nullptr)
			return res;
		else
			que.push(root);
		while (!que.empty()) {
			int size = que.size();
			vector<int> vec;
			for (int i = 0; i < size; i++) {
				TreeNode* cur = que.front();
				que.pop();
				vec.push_back(cur->val);
				if (cur->left) que.push(cur->left);
				if (cur->right) que.push(cur->right);
			}
			res.push_back(vec);
		}
		return res;
	}

	//第二次做
	vector<vector<int>> levelOrder1(TreeNode* root) {
		if (root == nullptr) return{};
		queue<TreeNode*> que;
		vector<vector<int>> res;
		que.push(root);
		while (!que.empty()) {
			int size = que.size();
			vector<int> temp;
			while (size--) {
				TreeNode* cur = que.front();
				que.pop();
				temp.push_back(cur->val);
				if (cur->left) que.push(cur->left);
				if (cur->right) que.push(cur->right);
			}
			res.push_back(temp);
		}
		return res;
	}
};

int main() {
	return 0;
}