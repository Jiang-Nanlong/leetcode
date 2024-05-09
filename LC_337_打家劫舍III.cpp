#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

//还是打家劫舍的题，不过这回房子的排列顺序变成二叉树了，这是递归和动态规划结合的一道题，题目中的dp数组不再是给所有的节点统一分配，而是递归的每一层，也就是每一个节点都有一个自己的dp数组
//dp[0]表示不偷当前节点的最大值，dp[1]表示偷当前节点的最大值

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
	int rob(TreeNode* root) {
		vector<int> res = robRange(root);
		return max(res[0], res[1]);
	}

	vector<int> robRange(TreeNode* root) {
		if (root == nullptr) return { 0,0 };

		vector<int> leftdp = robRange(root->left);  //返回左子树的dp数组
		vector<int> rightdp = robRange(root->right);  //返回右子树的dp数组

		int val1 = max(leftdp[0], leftdp[1]) + max(rightdp[0], rightdp[1]);   //不偷当前节点的最大值
		int val2 = root->val + leftdp[0] + rightdp[0];   //偷当前节点的最大值
		return { val1,val2 };
	}


	//第二次做，树形dp第一题
	int rob1(TreeNode* root) { // 后序遍历
		vector<int> res = robHelper(root);
		return max(res[0], res[1]);
	}
	vector<int> robHelper(TreeNode* root) {
		if (root == nullptr)
			return vector<int>{0, 0};
		vector<int> left = robHelper(root->left);
		vector<int> right = robHelper(root->right);

		vector<int> dp(2);
		dp[0] = max(left[0], left[1]) + max(right[0], right[1]);
		dp[1] = root->val + left[0] + right[0];
		return dp;
	}


	TreeNode* buildTree(vector<string>& nums) {
		if (nums.empty()) return nullptr;

		TreeNode* root = new TreeNode(stoi(nums[0]));
		queue<TreeNode*> que;
		que.push(root);

		int i = 1;
		while (i < nums.size()) {
			TreeNode* node = que.front();
			que.pop();

			if (i < nums.size() && nums[i] != "null") {
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
};

int main() {
	Solution st;
	vector<string> nums{ "3","2","3","null","3","null","1" };
	TreeNode* root = st.buildTree(nums);
	cout << st.rob(root) << endl;
	return 0;
}