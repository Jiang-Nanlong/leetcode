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
};
void main() {}