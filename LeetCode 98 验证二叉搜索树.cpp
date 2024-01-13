#include <iostream>
#include <stack>
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
};

void main() {}