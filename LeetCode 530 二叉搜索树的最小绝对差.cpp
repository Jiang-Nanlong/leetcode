#include <iostream>
#include <stack>
using namespace std;

//����һ�ö��������������������ڵ��֮��Ĳ�ľ���ֵ����Сֵһ�������������ڵĽڵ�֮�䡣
//�������ǿ�����ͨ��������������е����ڽڵ㣬Ȼ������ҳ������Сֵ���������ַ���̫���ˣ��Ͳ�д�ˡ�
//�����Ը�LeetCode 98��һ����ʹ��һ��preָ��ָ��ǰһ���ڵ㣬Ȼ���¼��ǰ�ڵ��ǰһ���ڵ�Ĳ�ҵ���Сֵ��
//�������������

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
	TreeNode* pre = nullptr;
	int result = INT_MAX;
	int getMinimumDifference(TreeNode* root) {
		Helper(root);
		return result;
	}

	void Helper(TreeNode* cur) {
		if (cur == nullptr) return;
		Helper(cur->left);
		if (pre) {
			result = min(result, abs(cur->val - pre->val));
		}
		pre = cur;
		Helper(cur->right);
	}

	//��Ȼ����ʹ�õݹ飬��ô�Ϳ���ʹ�õ���
	int getMinimumDifference1(TreeNode* root) {
		stack<TreeNode*> stk;
		int result = INT_MAX;
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
				if (pre && result > abs(pre->val - cur->val))
					result = abs(pre->val - cur->val);
				pre = cur;
				cur = cur->right;
			}
		}
		return result;
	}

	//�ڶ�������������������������������е���С���Բ�һ���ǳ���������������ڵ������ڵ���
	TreeNode* pre;
	int res = INT_MAX;
	int getMinimumDifference2(TreeNode* root) {
		if (root == nullptr) return res;

		int leftminres = getMinimumDifference2(root->left);
		if (pre) {
			res = min(res, abs(root->val - pre->val));
		}
		pre = root;
		int rightminres = getMinimumDifference2(root->right);
		return min(leftminres, min(res, rightminres));
	}
};

void main() {}