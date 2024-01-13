#include <iostream>
#include <stack>
using namespace std;

//这是一棵二叉搜索树，所以两个节点的之间的差的绝对值的最小值一定是在两个相邻的节点之间。
//所以我们可以先通过中序遍历出所有的相邻节点，然后遍历找出差的最小值，但是这种方法太简单了，就不写了。
//还可以跟LeetCode 98题一样，使用一个pre指针指向前一个节点，然后记录当前节点和前一个节点的差，找到最小值。
//这题是中序遍历

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
	TreeNode* pre = nullptr;
	int result = INT_MAX;
	int getMinimumDifference(TreeNode* root) {
		Helper(root);
		return result;
	}

	void Helper(TreeNode* cur) {
		if (cur == nullptr) return;
		Helper(cur->left);
		if (pre) {
			result = min(result, abs(cur->val - pre->val));
		}
		pre = cur;
		Helper(cur->right);
	}

	//既然可以使用递归，那么就可以使用迭代
	int getMinimumDifference1(TreeNode* root) {
		stack<TreeNode*> stk;
		int result = INT_MAX;
		TreeNode* cur = root;
		TreeNode* pre = nullptr;
		while (cur || !stk.empty()) {
			if (cur) {
				stk.push(cur);
				cur = cur->left;
			}
			else {
				cur = stk.top();
				stk.pop();
				if (pre && result > abs(pre->val - cur->val))
					result = abs(pre->val - cur->val);
				pre = cur;
				cur = cur->right;
			}
		}
		return result;
	}
};

void main() {}