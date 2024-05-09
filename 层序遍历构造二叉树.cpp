#include <iostream>
#include <vector>
#include <queue>
#include <string>
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
	TreeNode* buildTree(vector<string>& nums) {
		if (nums.empty()) return nullptr;

		TreeNode* root = new TreeNode(stoi(nums[0]));
		queue<TreeNode*> que;
		que.push(root);

		int i = 1;
		while (i < nums.size()) {
			TreeNode* node = que.front();
			que.pop();

			if (nums[i] != "null") {
				node->left = new TreeNode(stoi(nums[i]));
				que.push(node->left);
			}
			i++;

			if (i < nums.size() && nums[i] != "null") {
				node->right = new TreeNode(stoi(nums[i]));
				que.push(node->right);
			}
			i++;
		}
		return root;
	}

	vector<string> levelOrder(TreeNode* root) {
		queue<TreeNode*> que;
		vector<string> res;
		if (root == nullptr)
			return res;
		else
			que.push(root);

		while (!que.empty()) {
			int size = que.size();
			for (int i = 0; i < size; i++) {
				TreeNode* cur = que.front();
				que.pop();
				res.push_back(to_string(cur->val));

				if (cur->left) que.push(cur->left);
				if (cur->right) que.push(cur->right);
			}
		}
		return res;
	}
};

int main() {
	Solution st;
	vector<string> nums{ "3","2","3","null","3","null","1" };
	TreeNode* root = st.buildTree(nums);
	auto res = st.levelOrder(root);
	for (auto& s : res)
		cout << s << "  ";
	return 0;
}