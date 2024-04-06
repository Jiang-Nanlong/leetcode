#include <iostream>
#include <vector>
using namespace std;

//这个题重要的是从后序序列的最后一个节点获取当前子树的根节点，然后分割中序序列和后序序列。然后递归处理左子树和右子树。
/*
* 该题可分为六部：
* 1、若后序数组为0，则返回空
* 2、后序数组的最后一个元素为当前子树的根节点
* 3、寻找根节点在中序数组中的位置，作为切割点
* 4、切割中序数组
* 5、切割后序数组
* 6、递归处理左子树和右子树
*/

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
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if (postorder.size() == 0) return nullptr;
		int rootvale = postorder[postorder.size() - 1];
		TreeNode* root = new TreeNode(rootvale);
		if (postorder.size() == 1) return root;
		int index;
		for (index = 0; index < inorder.size(); index++)
			if (inorder[index] == rootvale)
				break;

		vector<int> leftinorder(inorder.begin(), inorder.begin() + index);
		vector<int> rightinorder(inorder.begin() + index + 1, inorder.end());

		int leftsize = leftinorder.size();
		vector<int> leftpostorder(postorder.begin(), postorder.begin() + leftsize);
		vector<int> rightpostorder(postorder.begin() + leftsize, postorder.end() - 1);

		root->left = buildTree(leftinorder, leftpostorder);
		root->right = buildTree(rightinorder, rightpostorder);

		return root;
	}

	//因为上述代码一直在分割数组，构造数组，所以很费时间，其实只要记住区间的两端就行，所以有下述代码。
	TreeNode* buildTree1(vector<int>& inorder, vector<int>& postorder) {
		if (postorder.size() == 0 || inorder.size() == 0) return nullptr;
		return Helper(inorder, 0, inorder.size(), postorder, 0, postorder.size());
	}

	TreeNode* Helper(vector<int>& inorder, int inorderBegin, int inorderEnd, vector<int>& postorder, int postorderBegin, int postorderEnd) {
		if (postorderBegin == postorderEnd) return nullptr;

		int rootvale = postorder[postorderEnd - 1];
		TreeNode* root = new TreeNode(rootvale);
		if (postorderEnd - postorderBegin == 1) return root;

		int index;
		for (index = inorderBegin; index < inorderEnd; index++)
			if (inorder[index] == rootvale)
				break;

		int leftinorderBegin = inorderBegin;
		int leftinorderEnd = index;

		int rightinorderBegin = index + 1;
		int rightinorderEnd = inorderEnd;

		int leftpostorderBegin = postorderBegin;
		int leftpostorderEnd = postorderBegin + index - inorderBegin;
		int rightpostorderBegin = postorderBegin + index - inorderBegin;
		int rightpostorderEnd = postorderEnd - 1;

		root->left = Helper(inorder, leftinorderBegin, leftinorderEnd, postorder, leftpostorderBegin, leftpostorderEnd);
		root->right = Helper(inorder, rightinorderBegin, rightinorderEnd, postorder, rightpostorderBegin, rightpostorderEnd);
		return root;

	}


	//第二次做
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if (inorder.size() == 0)
			return nullptr;

		int rootvalue = postorder[postorder.size() - 1];
		TreeNode* root = new TreeNode(rootvalue);

		int rootIndexOfInorder = 0;
		for (; rootIndexOfInorder < inorder.size(); rootIndexOfInorder++) {
			if (inorder[rootIndexOfInorder] == rootvalue)
				break;
		}

		vector<int> leftInorder(inorder.begin(),
			inorder.begin() + rootIndexOfInorder);
		vector<int> rightInorder(inorder.begin() + rootIndexOfInorder + 1,
			inorder.end());

		vector<int> leftPostorder(postorder.begin(),
			postorder.begin() + leftInorder.size());
		vector<int> rightPostorder(postorder.begin() + leftInorder.size(),
			postorder.end() - 1);

		root->left = buildTree(leftInorder, leftPostorder);
		root->right = buildTree(rightInorder, rightPostorder);
		return root;
	}


	//修改后，只传递两个数组的起点和终点
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		return buildTreeHelper(inorder, 0, inorder.size(), postorder, 0, postorder.size());
	}
	TreeNode* buildTreeHelper(vector<int>& inorder, int inorderbegin, int inorderend, vector<int>& postorder, int postorderbegin, int postorderend) {
		if (inorderbegin == inorderend) return nullptr;

		int rootvalue = postorder[postorderend - 1];
		TreeNode* root = new TreeNode(rootvalue);

		int rootIndexOfInorder = inorderbegin;
		for (; rootIndexOfInorder < inorderend; rootIndexOfInorder++) {
			if (inorder[rootIndexOfInorder] == rootvalue)
				break;
		}

		int leftInorderbegin = inorderbegin, leftInorderend = rootIndexOfInorder;
		int leftPostorderbegin = postorderbegin, leftPostorderend = rootIndexOfInorder - inorderbegin + postorderbegin;

		int rightInorderbegin = leftInorderend + 1, rightInorderend = inorderend;
		int rightPostorderbegin = leftPostorderend, rightPostorderend = postorderend - 1;

		root->left = buildTreeHelper(inorder, leftInorderbegin, leftInorderend, postorder, leftPostorderbegin, leftPostorderend);
		root->right = buildTreeHelper(inorder, rightInorderbegin, rightInorderend, postorder, rightPostorderbegin, rightPostorderend);
		return root;
	}
};

void main() {}
