#include <iostream>
#include <vector>
using namespace std;

//这个题和112一样，只不过是要收集路径

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
	vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
		vector<int> path;
		vector<vector<int>> res;
		if (root == nullptr) return res;
		Helper(root, targetSum, 0, path, res);
		return res;
	}
	void Helper(TreeNode* node, int targetSum, int sum, vector<int> path, vector<vector<int>>& res) {
		sum += node->val;
		path.push_back(node->val);
		if (node->left == nullptr && node->right == nullptr) {
			if (sum == targetSum) {
				res.push_back(path);
				//return;   //如果path是引用的时候，这里就不能带return，因为如果是引用，就得回溯，执行完当前层的函数就得弹出当前层元素。如果有了return，就会在最后一层没法弹出最后一层的节点，只能由上一层弹出，这样就会少弹出一个。
				// 如果path是值传递，那么有没有return无所谓。  
			}
		}
		if (node->left) {
			Helper(node->left, targetSum, sum, path, res);
		}
		if (node->right) {
			Helper(node->right, targetSum, sum, path, res);
		}
		path.pop_back();   //其实这一句有没有都无所谓。因为函数传参是vector<int> path，当前一步不会对之前的函数调用产生影响。如果path是引用传参，就得严格回溯了。
		//另外还可以把vector<vector<int>> res设置成类变量来减少函数传参。
	}


	//第二次做
	vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
		if (root == nullptr) return {};
		vector<int> path;
		vector<vector<int>> res;
		pathSumHelper(root, targetSum, 0, path, res);
		return res;
	}

	void pathSumHelper(TreeNode* root, int targetSum, int sum, vector<int>& path, vector<vector<int>>& res) {
		path.push_back(root->val);
		sum += root->val;
		if (root->left == nullptr && root->right == nullptr) {
			if (sum == targetSum) {
				res.push_back(path);
				return;
			}
		}
		if (root->left) {
			pathSumHelper(root->left, targetSum, sum, path, res);
			path.pop_back();  //这两个pop_back()都是当前节点层弹出下一层的数组内的节点
			//这是因为终止条件中return了，最后一层直接return，这样在它的上一层弹出当前层节点。
		}
		if (root->right) {
			pathSumHelper(root->right, targetSum, sum, path, res);
			path.pop_back();
		}
	}

	//或者这么写也行，终止条件中没有return，每一层都是刚开始加入数组，最后弹出当前层节点。
	void pathSumHelper(TreeNode* root, int targetSum, int sum, vector<int>& path, vector<vector<int>>& res) {
		path.push_back(root->val);
		sum += root->val;
		if (root->left == nullptr && root->right == nullptr) {
			if (sum == targetSum) {
				res.push_back(path);
			}
		}
		if (root->left) {
			pathSumHelper(root->left, targetSum, sum, path, res);
		}
		if (root->right) {
			pathSumHelper(root->right, targetSum, sum, path, res);
		}
		path.pop_back();

	}
};
void main() {}
