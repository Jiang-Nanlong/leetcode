#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
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
	TreeNode* invertTree(TreeNode* root) {  //直接递归
		if (root == nullptr)
			return root;
		swap(root->left, root->right);
		invertTree(root->left);
		invertTree(root->right);

		return root;
	}


	//第二次做
	TreeNode* invertTree1(TreeNode* root) {
		backtrace(root);
		return root;
	}
	void backtrace(TreeNode* root) {
		if (root == nullptr) return;
		swap(root->left, root->right);  //中
		backtrace(root->left);  //左
		backtrace(root->right);  //右
	}

	//上边递归还是用来前序遍历，所以也可以用前序遍历的非递归写法
	TreeNode* invertTree2(TreeNode* root) {
		if (root == nullptr) return root;
		stack<TreeNode*>stk;
		stk.push(root);
		while (!stk.empty()) {
			TreeNode* cur = stk.top();
			stk.pop();
			swap(cur->left, cur->right);
			if (cur->right) stk.push(cur->right);
			if (cur->left) stk.push(cur->left);
		}
		return root;
	}


	//这个题我没想到还可以用层序遍历
	TreeNode* invertTree3(TreeNode* root) {
        if(root==nullptr) return root;
        queue<TreeNode*>que;
        que.push(root);
        while(!que.empty()){
            int size=que.size();
            while(size--){
                TreeNode*cur=que.front();
                que.pop();
                swap(cur->left,cur->right);
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
        }
        return root;
    }
};

void main() {}