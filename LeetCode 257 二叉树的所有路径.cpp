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
	void Helper(TreeNode* cur, vector<int>& path, vector<string>& res) {  //ʹ��ǰ����������������ǴӸ��ڵ㵽Ҷ�ӽڵ��·��
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
			path.pop_back();
		}
		if (cur->right) {
			Helper(cur->right, path, res);
			path.pop_back();
		}
	}

	//���ϴ�����Ծ�����±�������������string path����vector<int> & path���������ݹ��̾ͱ����������ˣ���Ϊ�����ǿ�����ֵ����������
	/*void Helper(TreeNode* cur, string path, vector<string>& res) {
		path += to_string(cur->val);
		if (cur->left == nullptr && cur->right == nullptr) {
			res.push_back(path);
			return;
		}
		if (cur->left) Helper(cur->left, path + "->", res);
		if (cur->right) Helper(cur->right, path + "->", res);
	}*/

	//��Ȼ��ͨ���ݹ��ǰ���������ô������ǰ�����Ҳ������
	//vector<string> binaryTreePaths(TreeNode* root) {
	//	vector<string> res;
	//	if (root == nullptr) return res;
	//	stack<TreeNode*> treeStk;
	//	stack<string> pathStk;
	//	treeStk.push(root);
	//	pathStk.push(to_string(root->val));
	//	while (!treeStk.empty()) {
	//		TreeNode* cur = treeStk.top(); treeStk.pop();	//����������
	//		string path = pathStk.top(); pathStk.pop();
	//		if (cur->left == nullptr && cur->right == nullptr) {
	//			res.push_back(path);
	//			continue;
	//		}
	//		if (cur->left) {  //��������˭��ǰ˭�ں�����ν����
	//			treeStk.push(cur->left);
	//			pathStk.push(path + "->" + to_string(cur->left->val));
	//		}
	//		if (cur->right) {   //��
	//			treeStk.push(cur->right);
	//			pathStk.push(path + "->" + to_string(cur->right->val));
	//		}
	//	}
	//	return res;
	//}

};

void main() {}