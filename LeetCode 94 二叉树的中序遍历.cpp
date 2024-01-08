#include <iostream>
#include <vector>
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
	//�Ȱ�����ߵĽڵ�������ջ��Ȼ���ջ�������ջ�Ľڵ����������Ļ�������������������������ջ
	//vector<int> inorderTraversal(TreeNode* root) {    //�ǵݹ��������
	//	if (root == nullptr) return {};
	//	vector<int> res;
	//	stack<TreeNode*> stk;
	//	TreeNode* cur = root;
	//	while (cur != nullptr || !stk.empty()) {
	//		if (cur != nullptr) {
	//			stk.push(cur);
	//			cur = cur->left;
	//		}
	//		else {
	//			cur = stk.top();
	//			stk.pop();
	//			res.push_back(cur->val);
	//			cur = cur->right;
	//		}
	//	}
	//	return res;
	//}

	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		intravl(root, res);
		return res;
	}

private:
	void intravl(TreeNode* cur, vector<int>& res) {
		if (cur == nullptr) return;
		intravl(cur->left, res);
		res.push_back(cur->val);
		intravl(cur->right, res);
	}
};

void main() {

}