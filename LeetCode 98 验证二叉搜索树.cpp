#include <iostream>
#include <stack>
#include <vector>
using namespace std;

//��֤һ�����ǲ��Ƕ������������±������õݹ�ʵ�֣��о��е�����⡣��ʵ���˼·���Ǽ�¼ǰһ���ڵ��ֵ�����ǰһ���ڵ�Ⱥ�һ���ڵ��ֵ�����ǿ϶����Ƕ���������
//��ʵ�������õĶ�������������������ǵ������У���һ���ԡ�
// ���⻹����ֱ���������һ�£���Ϊ�����������������������ǵ����ġ�

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
	long long lastvalue = LONG_MIN;  //���ﶨ���longlong����Ϊ������������һ��INT_MIN��Ϊ�˱�����С�������longlong��
	//����дҲ��̫�ã��������������һ���ڵ��ֵ��LONG_MIN����ô�������ó�LONG_MIN���ֲ����ˣ�������ֱ�ӷ���false�ˡ�
	bool isValidBST(TreeNode* root) {
		if (root == nullptr) return true;

		bool left = isValidBST(root->left);
		if (root->val > lastvalue) lastvalue = root->val;
		else return false;

		bool right = isValidBST(root->right);
		return left && right;
	}

	//���Ի�����һ��longlong�����⣬�������ֱ�Ӽ�¼ǰһ���ڵ��ָ�룬Ȼ��Ƚ�����ָ��ָ��Ľڵ��ֵ�Ĵ�С
	TreeNode* pre = nullptr;
	bool isValidBST1(TreeNode* root) {
		if (root == nullptr) return true;
		bool left = isValidBST1(root->left);

		if (pre && root->val <= pre->val) return false;   //������Ҫ�ж�pre�ǲ���Ϊ�գ���Ϊ������һ���ڵ��ʱ��pre��null
		pre = root;

		bool right = isValidBST1(root->right);
		return left && right;
	}

	//��Ϊ�������������ʵ�ֵģ������õ������������Ҳ����ʵ�֡�
	bool isValidBST2(TreeNode* root) {
		if (root == nullptr) return true;
		stack<TreeNode*>stk;
		TreeNode* cur = root;
		TreeNode* pre = nullptr;
		while (cur || !stk.empty()) {
			if (cur) {
				stk.push(cur);
				cur = cur->left;
			}
			else {
				cur = stk.top();
				stk.pop();
				if (pre && pre->val >= cur->val)
					return false;
				pre = cur;
				cur = cur->right;
			}
		}
		return true;
	}

	//�ڶ������������뵽������һ�����鱣���������������Ľṹ������������ǲ��ǵ���������
	bool isValidBST(TreeNode* root) {
		if (root->left == nullptr && root->right == nullptr) return true;
		vector<int> rootlist;
		inorder(root, rootlist);
		for (int i = 1; i < rootlist.size(); i++)
			if (rootlist[i] <= rootlist[i - 1]) return false;
		return true;
	}

	void inorder(TreeNode* root, vector<int>& res) {
		if (root == nullptr) return;
		inorder(root->left, res);
		res.push_back(root->val);
		inorder(root->right, res);
	}

	//����������ǰ�Ĵ��룬����ֻҪ������������ɣ���һ����������һ����������ĵ��ֵ���У�����һ���Ӱ����еĶ���������
	long long prevalue = LONG_MIN;
	bool isValidBST(TreeNode* root) {
		if (root == nullptr)
			return true;

		bool leftflag = isValidBST(root->left);
		if (root->val > prevalue) {
			prevalue = root->val;
		}
		else
			return false;
		bool rightflag = isValidBST(root->right);
		return leftflag && rightflag;
	}

	//���߻�����ֻ����ǰһ���ڵ��ָ��
	TreeNode* pre;
	bool isValidBST(TreeNode* root) {
		if (root == nullptr)
			return true;

		bool leftflag = isValidBST(root->left);
		if (pre && root->val <= pre->val) {
			return false;
		}
		else
			pre = root;
		bool rightflag = isValidBST(root->right);
		return leftflag && rightflag;
	}
};

void main() {}