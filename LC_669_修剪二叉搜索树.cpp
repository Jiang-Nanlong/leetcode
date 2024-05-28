#include <iostream>
#include <vector>
#include <string>
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

	// 第三次做，依旧没有写出来
	TreeNode* trimBST2(TreeNode* root, int low, int high) {
		if (root == nullptr)
			return nullptr;
		if (root->val < low) {
			TreeNode* left = trimBST(root->right, low, high);
			return left;
		}
		if (root->val > high) {
			TreeNode* right = trimBST(root->left, low, high);
			return right;
		}
		root->left = trimBST(root->left, low, high);
		root->right = trimBST(root->right, low, high);
		return root;
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

			if (nums[i] != "null") {
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

	vector<string> levelOrder(TreeNode* root) {
		queue<TreeNode*> que;
		vector<string> res;
		if (root == nullptr)
			return res;
		else
			que.push(root);

		while (!que.empty()) {
			int size = que.size();
			for (int i = 0; i < size; i++) {
				TreeNode* cur = que.front();
				que.pop();
				res.push_back(to_string(cur->val));

				if (cur->left) que.push(cur->left);
				if (cur->right) que.push(cur->right);
			}
		}
		return res;
	}
};

int main() {
	Solution st;
	vector<string> num{ "3","0","4","null","2","null","null","1" };
	TreeNode* root = st.buildTree(num);
	root = st.trimBST2(root, 1, 3);
	vector<string> res = st.levelOrder(root);
	for (auto& c : res)
		cout << c << "  ";

	return 0;
}