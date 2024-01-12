#include <iostream>
#include <vector>
using namespace std;

//�������Ҫ���ǴӺ������е����һ���ڵ��ȡ��ǰ�����ĸ��ڵ㣬Ȼ��ָ��������кͺ������С�Ȼ��ݹ鴦������������������
/*
* ����ɷ�Ϊ������
* 1������������Ϊ0���򷵻ؿ�
* 2��������������һ��Ԫ��Ϊ��ǰ�����ĸ��ڵ�
* 3��Ѱ�Ҹ��ڵ������������е�λ�ã���Ϊ�и��
* 4���и���������
* 5���и��������
* 6���ݹ鴦����������������
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

	//��Ϊ��������һֱ�ڷָ����飬�������飬���Ժܷ�ʱ�䣬��ʵֻҪ��ס��������˾��У��������������롣
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

};

void main() {}