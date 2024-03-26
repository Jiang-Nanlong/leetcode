#include <iostream>
#include <queue>
#include <vector>
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
	vector<int> largestValues(TreeNode* root) {
		if (root == nullptr) return {};
		queue<TreeNode*> que;
		vector<int> res;
		que.push(root);
		while (!que.empty()) {
			int size = que.size();
			int maxVal = INT_MIN;        //这里maxVal的初始值不能是0，因为树中的数字可能是负数。
			for (int i = 0; i < size; i++) {
				TreeNode* cur = que.front();
				que.pop();
				maxVal = maxVal > cur->val ? maxVal : cur->val;
				if (cur->left) que.push(cur->left);
				if (cur->right) que.push(cur->right);
			}
			res.push_back(maxVal);
		}
		return res;
	}

	//第二次做
	vector<int> largestValues1(TreeNode* root) {
		if (root == nullptr)
			return {};
		queue<TreeNode*> que;
		que.push(root);
		vector<int> res;
		while (!que.empty()) {
			int size = que.size();
			int maxVal = INT_MIN;
			while (size--) {
				TreeNode* cur = que.front();
				que.pop();
				maxVal = max(maxVal, cur->val);
				if (cur->left)
					que.push(cur->left);
				if (cur->right)
					que.push(cur->right);
			}
			res.push_back(maxVal);
		}
		return res;
	}

};

void main() {}