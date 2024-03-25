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
	//�ǵݹ�ǰ�������Ҫ��ÿһ���ڵ���ҽڵ�����ջ��Ȼ�������ڵ���ջ��ֻ���������������е����нڵ�Ŷ����ҽڵ���ϱߣ���ջ��ʱ�����ǰ�����ˡ�
	//Ϊ���ó�ջʱ�������ң���ջ��ʱ��͵���������
	vector<int> preorderTraversal1(TreeNode* root) {  //�ǵݹ�ǰ�����
		if (root == nullptr) return{};
		stack<TreeNode*> stk;
		vector<int> res;
		stk.push(root);
		while (!stk.empty()) {
			TreeNode* cur = stk.top();
			stk.pop();
			res.push_back(cur->val);
			if (cur->right) stk.push(cur->right);
			if (cur->left) stk.push(cur->left);
		}
		return res;
	}

	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		pretravl(root, res);
		return res;
	}

private:
	void pretravl(TreeNode* cur, vector<int>& res) {
		if (cur == nullptr) return;
		res.push_back(cur->val);
		pretravl(cur->left, res);
		pretravl(cur->right, res);
	}
};

void main() {

}