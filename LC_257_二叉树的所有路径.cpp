#include <iostream>
#include <vector>
#include <string>
#include <stack>
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
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> result;
		vector<int> path;
		if (root == nullptr) return result;
		Helper(root, path, result);
		return result;
	}

private:
	void Helper(TreeNode* cur, vector<int>& path, vector<string>& res) {  //使用前序遍历，这样才能是从根节点到叶子节点的路径
		path.push_back(cur->val);
		if (cur->left == nullptr && cur->right == nullptr) {
			string Paths;
			for (int i = 0; i < path.size() - 1; i++) {
				Paths += path[i];
				Paths += "->";
			}
			Paths += to_string(path[path.size() - 1]);
			res.push_back(Paths);
			return;
		}
		if (cur->left) {
			Helper(cur->left, path, res);
			path.pop_back(); //因为刚进函数就把当前层节点入栈，所以最后的叶子结点也会入栈，然后在叶子结点的上一层弹出叶子节点，所以每个分支上都得弹出一次
		}
		if (cur->right) {
			Helper(cur->right, path, res);
			path.pop_back();
		}
	}

	//以上代码可以精简成下边这样，可以用string path代替vector<int> & path，这样回溯过程就被隐藏起来了，因为这里是拷贝赋值而不是引用
	/*void Helper(TreeNode* cur, string path, vector<string>& res) {
		path += to_string(cur->val);
		if (cur->left == nullptr && cur->right == nullptr) {
			res.push_back(path);
			return;
		}
		if (cur->left) Helper(cur->left, path + "->", res);
		if (cur->right) Helper(cur->right, path + "->", res);
	}*/

	//既然是通过递归的前序遍历，那么迭代的前序遍历也能做到
	//vector<string> binaryTreePaths(TreeNode* root) {
	//	vector<string> res;
	//	if (root == nullptr) return res;
	//	stack<TreeNode*> treeStk;
	//	stack<string> pathStk;
	//	treeStk.push(root);
	//	pathStk.push(to_string(root->val));
	//	while (!treeStk.empty()) {
	//		TreeNode* cur = treeStk.top(); treeStk.pop();	//这两步是中
	//		string path = pathStk.top(); pathStk.pop();
	//		if (cur->left == nullptr && cur->right == nullptr) {
	//			res.push_back(path);
	//			continue;
	//		}
	//		if (cur->left) {  //这两步，谁在前谁在后都无所谓，左
	//			treeStk.push(cur->left);
	//			pathStk.push(path + "->" + to_string(cur->left->val));
	//		}
	//		if (cur->right) {   //右
	//			treeStk.push(cur->right);
	//			pathStk.push(path + "->" + to_string(cur->right->val));
	//		}
	//	}
	//	return res;
	//}

	//第二遍做
	vector<string> binaryTreePaths1(TreeNode* root) {
		vector<string> res;
		vector<int> path;
		binaryTreePathsHelper(root, path, res);
		return res;

	}
	void binaryTreePathsHelper(TreeNode* root, vector<int>& path, vector<string>& res) {
		if (root->left == nullptr && root->right == nullptr) {
			int size = path.size();
			string s;
			for (int i = 0; i < size; i++) {
				s += to_string(path[i]);
				s += "->";
			}
			s += to_string(root->val);
			res.push_back(s);
			return;
		}
		path.push_back(root->val);
		if (root->left)
			binaryTreePathsHelper(root->left, path, res);

		if (root->right)
			binaryTreePathsHelper(root->right, path, res);
		path.pop_back();  //因为最后一个节点不加入数组，所以每一层只需要弹出每一层新加入的节点就行
	}

};

void main() {}
