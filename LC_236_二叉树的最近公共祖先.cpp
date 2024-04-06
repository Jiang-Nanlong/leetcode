#include <iostream>
#include <vector>
using namespace std;

//这个题感觉有点难。要求找出两个点的最近公共祖先。开始想的是二叉树只支持从上往下找，怎么能从下往上呢。
//后来看了代码随想录的视频，才知道后序遍历可以从下往上。
//感觉代码随想录的这个思路，一下子想不到。
//在评论区看见一个思路，就是通过前序遍历，找到根节点到指定节点的路径，然后分别找出到p和q的路径，然后比较两个路径，就能找出最近的公共节点。

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == nullptr) return nullptr;
		if (root == p || root == q) return root;

		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);

		if (left && right) return root;
		else if (left && right == nullptr) return left;
		else if (left == nullptr && right) return right;
		else return nullptr;
	}


	//这里的flag是用来表示是否找到了指定节点，如果找到了就不用弹出path的末尾节点。
	TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {
		vector<TreeNode*> pathP, pathQ;
		bool flag = false;
		pretraversal(root, p, pathP, flag);
		flag = false;
		pretraversal(root, q, pathQ, flag);
		for (int i = 0, j = 0; i < pathP.size() && j < pathQ.size(); i++, j++) {
			if (pathP[i] != pathQ[j]) return pathP[i - 1];
		}
		if (pathP.size() < pathQ.size()) return pathP.back();
		else return pathQ.back();
	}

	void pretraversal(TreeNode* root, TreeNode* target, vector<TreeNode*>& path, bool& flag) {
		if (flag) return;
		if (root == nullptr) return;

		path.push_back(root);
		if (root == target) {
			flag = true;
			return;
		}

		pretraversal(root->left, target, path, flag);
		pretraversal(root->right, target, path, flag);
		if (flag) return;
		path.pop_back();       //这个地方的pop和LeetCode 257 二叉树的所有路径中的pop不太一样，我一直弄不清，后来手动算了一下才知道，257这个题到叶节点就结束了，return了，然后在叶节点的上一层弹出叶节点。
		//而这里是可以到叶节点的下一层，然后下一层为空就return，然后在叶节点本层就可以弹出叶节点。所以，257中要分开pop，而这里可以一起pop。
	}

	//第二遍做，还是没做出来，只想到了用后序遍历，还是没写出代码
	TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL)
			return NULL;
		if (root == p || root == q)
			return root;
		TreeNode* left = lowestCommonAncestor2(root->left, p, q);
		TreeNode* right = lowestCommonAncestor2(root->right, p, q);

		if (left && right)
			return root;
		else if (left == NULL && right)
			return right;
		else if (left && right == NULL)
			return left;
		else
			return NULL;
	}

	//又看了一下第一次做的时候用的前序遍历的方法，这个方法还挺巧
};

void main() {}
