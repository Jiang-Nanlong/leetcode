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
};
void main() {}