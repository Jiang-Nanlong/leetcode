#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//要求找出二叉搜索树中的众数。众数可能有好几个
//最开始想到的就是先遍历一遍二叉搜索树，然后用unordered_map保存每一个节点值的出现次数，最后再排序，返回出现次数最多的几个数。这种方法是最容易想到的，但是没有利用到二叉搜索树这一特点。
//这里还是用中序遍历，如果pre指向的节点为空，说明是第一个节点，count=1；如果pre指向的节点和当前节点值一样，count++；如果pre指向的节点的值和当前的不一样，那么count=1.
//然后用maxcount记录最大的count，如果count==maxcount的话，节点的值就入队；如果maxcount更新的话，结果数组就清空，然后把当前节点加入进去。

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

	vector<int> findMode(TreeNode* root) {
		Helper(root);
		return res;
	}
	int maxcount = 0, count = 0;
	vector<int> res;
	TreeNode* pre = nullptr;
	void Helper(TreeNode* root) {
		if (root == nullptr) return;
		Helper(root->left);   //左

		if (pre == nullptr)   //中
			count = 1;
		else if (pre->val == root->val)
			count++;
		else  //pre->val和root->val不相同
			count = 1;

		if (count == maxcount)
			res.push_back(root->val);

		if (count > maxcount) {
			maxcount = count;
			res.clear();
			res.push_back(root->val);
		}

		pre = root;
		Helper(root->right); //右
	}

	//前边是用递归做的，递归能做的迭代也能做
	vector<int> findMode1(TreeNode* root) {
		stack<TreeNode*> stk;
		vector<int> res;
		TreeNode* cur = root;
		TreeNode* pre = nullptr;
		int count = 0, maxcount = 0;
		while (cur || !stk.empty()) {
			if (cur) {
				stk.push(cur);
				cur = cur->left;  //左
			}
			else {
				cur = stk.top();  //中
				stk.pop();
				if (pre == nullptr)
					count = 1;
				else if (pre->val == cur->val)
					count++;
				else
					count = 1;

				if (count == maxcount)
					res.push_back(cur->val);
				if (count > maxcount) {
					maxcount = count;
					res.clear();
					res.push_back(cur->val);
				}

				pre = cur;
				cur = cur->right;  //右

			}
		}
		return res;
	}
};

void main() {}