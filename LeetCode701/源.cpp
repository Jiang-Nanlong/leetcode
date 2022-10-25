#include<iostream>
using namespace std;

class Solution {
public:
	typedef struct TreeNode {
		int val;
		TreeNode* left, * right;
		TreeNode() : val(0), left(nullptr), right(nullptr) {}
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
		TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
	}TreeNode;

	TreeNode* insertIntoBST(TreeNode* root, int val) {
		/*TreeNode* p = root;
		while (p) {
			if (val > p->x) p = p->right;
			else p = p->left;
		}
		
		p = new TreeNode(val, nullptr, nullptr);

		return root;*/

		//该方法不行
		/*
		[61,46,66,43,null,null,null,39,null,null,null] 88
		[61,46,66,43,null,null,null,39]
		[61,46,66,43,null,null,88,39]
		*/
		/*TreeNode* p = root;
		int flag = 0;
		while (true) {
			if (val > p->val) {
				if (!p->right) {
					flag = 1;
					break;
				}
				else p = p->right;

			}
			else {
				if (!p->left) {
					flag = 2;
					break;
				}
				else p = p->left;
			}
		}

		flag == 1 ? p->right : p->left = new TreeNode(val);*/

		//这个可以
		/*if (!root) return new TreeNode(val);

		TreeNode* p = root;
		while (p) {
			if (val < p->val) {
				if (p->left == nullptr) {
					p->left = new TreeNode(val);
					break;
				}
				else {
					p = p->left;
				}
			}
			else {
				if (p->right == nullptr) {
					p->right = new TreeNode(val);
					break;
				}
				else {
					p = p->right;
				}
			}
		}
		*/
		//这个是第一次提交改过来的，也可以
		if (!root) return new TreeNode(val);
		TreeNode* p = root;
		//int flag = 0;
		while (true) {
			if (val > p->val) {
				if (p->right == nullptr) {
					//flag = 1;
					p->right = new TreeNode(val);
					break;
				}
				else p = p->right;

			}
			else {
				if (p->left == nullptr) {
					//flag = 2;
					p->left = new TreeNode(val);
					break;
				}
				else p = p->left;
			}
		}

		//flag == 1 ? p->right : p->left = new TreeNode(val);
		return root;
	}
};