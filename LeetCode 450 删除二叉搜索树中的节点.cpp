#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//应该是分三种情况，第一种：删除的是叶子结点，那么直接删除就行。第二种，如果删除的是中间节点，而且这个节点只有一个分支，那么就用他的分支节点代替它的位置即可。
//第三种，如果删除的是中间节点，而且这个节点有两个分支，我记得王道书上说的是用左孩子或右孩子替代都可，然后还得调整要替代节点的孩子

class Solution {
public:

	/*
		TreeNode* pre = nullptr;

		TreeNode* deleteNode(TreeNode* root, int key) {
			if (root->val == key) {
				if (root->left == nullptr && root->right == nullptr) {  //root是叶子节点
					if (root->val < pre->val)
						pre->left = nullptr;
					else pre->right = nullptr;
				}
				else if (root->left == nullptr && root->right) {    //root是中间节点，但是只有一个孩子
					if (root->val < pre->val)
						pre->left = root->right;
					else
						pre->right = root->right;
				}
				else if (root->left && root->right == nullptr) {
					if (root->val < pre->val)
						pre->left = root->left;
					else
						pre->right = root->left;
				}
				else {  //root是中间节点，有两个孩子，

					if (pre->val > root->val) {
						pre->left = root->left;
						pre->left->right = root->right;
					}
					else {
						pre->right = root->left;
						pre->right->right = root->right;
					}
					TreeNode* temp = root->left->right;
					TreeNode* p = root->right;
					while (p->left) p = p->left;
					p->left = temp;
				}
				free(root);
				return;
			}

			pre = root;
			if (root->val > key) deleteNode(root->left, key);
			if (root->val < key) deleteNode(root->right, key);

			return root;
		}
	*/
	//上边是我最开始写的，我还是没处理好递归函数的返回值问题，在写返回值的时候不知道咋写了，其实应该在61和62行接收一下的。要是按我的写法的话，函数就不该有返回值的。
	//下边是我看了代码随想录的代码写的，他的程序处理前几种情况都是一样的，但是最后一种不一样，他是直接把待删除节点的左子树整个的添加到右子树的最左下，然后用右子树的根节点代替删除节点的位置
	//后来想了一下，好像没有返回值的确实不太行，因为要删除的可能是根节点。如果写成没有返回值的，只能是在deleteNode中调用这个函数，然后返回root，但是删除的节点可能就是root
	TreeNode* deleteNode(TreeNode* root, int key) {
		if (root == nullptr) return nullptr;  //居然还有找不到节点这种情况

		if (root->val == key) {
			if (root->left == nullptr && root->right == nullptr) {  //root是叶子节点
				delete root;
				return nullptr;
			}
			else if (root->left == nullptr && root->right) {    //root是中间节点，但是只有一个孩子
				TreeNode* temp = root->right;
				delete root;
				return temp;
			}
			else if (root->left && root->right == nullptr) {
				TreeNode* temp = root->left;
				delete root;
				return temp;
			}
			else {  //root是中间节点，有两个孩子，
				TreeNode* temp = root->right;
				while (temp->left)
					temp = temp->left;
				temp->left = root->left;
				TreeNode* cur = root;
				temp = root->right;
				delete cur;
				return temp;
			}
		}

		if (root->val > key) root->left = deleteNode(root->left, key);
		if (root->val < key) root->right = deleteNode(root->right, key);

		return root;
	}

	//第二次做，直接使用的迭代，没用递归
	TreeNode* deleteNode1(TreeNode* root, int key) {
		if (root == nullptr)
			return nullptr;
		TreeNode* preroot = new TreeNode(-1);  //加一个头结点，防止被删除的是根节点
		preroot->right = root;
		TreeNode* parent = preroot, * cur = root;
		while (cur) {
			if (cur->val > key) {
				parent = cur;
				cur = cur->left;
			}
			else if (cur->val < key) {
				parent = cur;
				cur = cur->right;
			}
			else if (cur->val == key) {
				TreeNode* temp = nullptr;
				if (cur->left == nullptr && cur->right) {
					temp = cur->right;
				}
				else if (cur->left && cur->right == nullptr) {
					temp = cur->left;
				}
				else if (cur->left && cur->right) {
					TreeNode* rightOfRoot = cur->right;
					while (rightOfRoot->left)
						rightOfRoot = rightOfRoot->left;
					rightOfRoot->left = cur->left;
					temp = cur->right;
				}

				if (cur->val > parent->val) parent->right = temp;
				else parent->left = temp;
				delete cur;
				cur = nullptr;
			}
		}
		return preroot->right;
	}

	//又看着答案写了一个递归的版本
	TreeNode* deleteNode2(TreeNode* root, int key) {
		if (root == nullptr) return nullptr;
		if (root->val == key) {
			if (root->left == nullptr && root->right == nullptr) {
				delete root;
				return nullptr;
			}
			else if (root->left == nullptr && root->right) {
				TreeNode* temp = root->right;
				delete root;
				return temp;
			}
			else if (root->left && root->right == nullptr) {
				TreeNode* temp = root->left;
				delete root;
				return temp;
			}
			else {
				TreeNode* cur = root->right;
				while (cur->left)
					cur = cur->left;
				cur->left = root->left;
				TreeNode* temp = root->right;
				delete root;
				return temp;
			}
		}
		if (root->val > key) root->left = deleteNode2(root->left, key);
		if (root->val < key) root->right = deleteNode2(root->right, key);
		return root;
	}
};

void main() {

}