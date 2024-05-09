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

class Solution {
public:
	//应该是用中序遍历，
	TreeNode* trimBST(TreeNode* root, int low, int high) {
		/*
		* //这是我自己写的代码，这里的delete root一直报错，看了评论上好多人也都反应这个问题，不知道为什么
		* //这个代码和下边的代码比较，在思路上最大的区别就是我只是把要删除节点的左孩子或右孩子返回了，并没有考虑他的左孩子右孩子是否符合范围。
		* //就比如说[3,1,4,null,2] low=3,high=4.程序运行到节点1的时候就直接返回2了，这时候2替代了1的位置，但是程序不会再在1的位置上运行第二遍，
		* //所以就跳过了2，但是此时的2也是不符合要求的。
		* //下边的代码在这个位置上又递归了，这样就解决了这个问题。
		*
		if(root==nullptr) return nullptr;
		if(root->val<low){
			TreeNode*temp=root->right;
			//delete root;
			return temp;
		}else if(root->val>high){
			TreeNode* temp=root->left;
			//delete root;
			return temp;
		}

		root->left=trimBST(root->left,low,high);
		root->right=trimBST(root->right,low,high);
		return root;
		*/

		if (root == nullptr) return nullptr;
		if (root->val < low) {
			TreeNode* temp = trimBST(root->right, low, high);
			return temp;

		}
		else if (root->val > high) {
			TreeNode* temp = trimBST(root->left, low, high);
			return temp;
		}

		root->left = trimBST(root->left, low, high);
		root->right = trimBST(root->right, low, high);
		return root;
	}

	//这个题我第一次做的时候竟然能写出个差不多，我擦
	//第二次做，还是没有做出来
	TreeNode* trimBST1(TreeNode* root, int low, int high) {
		if (root == nullptr)
			return nullptr;
		if (root->val < low) {
			TreeNode* temp = trimBST1(root->right, low, high);  //当前节点的右子树可能符合条件，然后修剪右子树
			return temp;
		}
		else if (root->val > high) {
			TreeNode* temp = trimBST1(root->left, low, high);   //当前节点的左孩子可能符合条件，继续修剪左子树
			return temp;
		}
		root->left = trimBST1(root->left, low, high);
		root->right = trimBST1(root->right, low, high);
		return root;
	}
};

void main() {}
