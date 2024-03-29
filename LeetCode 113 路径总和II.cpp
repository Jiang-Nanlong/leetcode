#include <iostream>
#include <vector>
using namespace std;

//������112һ����ֻ������Ҫ�ռ�·��

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
				//return;   //���path�����õ�ʱ������Ͳ��ܴ�return����Ϊ��������ã��͵û��ݣ�ִ���굱ǰ��ĺ����͵õ�����ǰ��Ԫ�ء��������return���ͻ������һ��û���������һ��Ľڵ㣬ֻ������һ�㵯���������ͻ��ٵ���һ����
				// ���path��ֵ���ݣ���ô��û��return����ν��  
			}
		}
		if (node->left) {
			Helper(node->left, targetSum, sum, path, res);
		}
		if (node->right) {
			Helper(node->right, targetSum, sum, path, res);
		}
		path.pop_back();   //��ʵ��һ����û�ж�����ν����Ϊ����������vector<int> path����ǰһ�������֮ǰ�ĺ������ò���Ӱ�졣���path�����ô��Σ��͵��ϸ�����ˡ�
		//���⻹���԰�vector<vector<int>> res���ó�����������ٺ������Ρ�
	}


	//�ڶ�����
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
			path.pop_back();  //������pop_back()���ǵ�ǰ�ڵ�㵯����һ��������ڵĽڵ�
			//������Ϊ��ֹ������return�ˣ����һ��ֱ��return��������������һ�㵯����ǰ��ڵ㡣
		}
		if (root->right) {
			pathSumHelper(root->right, targetSum, sum, path, res);
			path.pop_back();
		}
	}

	//������ôдҲ�У���ֹ������û��return��ÿһ�㶼�Ǹտ�ʼ�������飬��󵯳���ǰ��ڵ㡣
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