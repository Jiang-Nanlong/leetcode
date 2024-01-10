#include <iostream>
#include <queue>
#include <stack>
using namespace std;

//��LeetCode 101 һ������������Ƚϵ�����ͬλ�ã�Ҳ����ʹ��ջ�������ʵ�֣������Ƚϵ�����ͬλ��

struct TreeNode {
	int val;
	TreeNode* left, * right;
	TreeNode() :val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) :val(x), left(left), right(right) {}
};

class Solution {
public:
	bool isSameTress(TreeNode* p, TreeNode* q) {
		return Helper(p, q);
	}
private:
	bool Helper(TreeNode* n1, TreeNode* n2) {
		if (n1 == nullptr && n2 == nullptr) return true;
		if ((n1 == nullptr && n2 != nullptr) || (n1 != nullptr && n2 == nullptr)) return false;
		return (n1->val == n2->val) && Helper(n1->left, n2->left) && Helper(n1->right, n2->right);
	}

public:
	bool isSameTreeByQueue(TreeNode* p, TreeNode* q) {
		if (p == nullptr && q == nullptr) return true;
		if (p != nullptr && q != nullptr) {
			queue<TreeNode*> que;
			que.push(p);
			que.push(q);
			while (!que.empty()) {
				TreeNode* n1 = que.front();
				que.pop();
				TreeNode* n2 = que.front();
				que.pop();
				if (n1 == nullptr && n2 == nullptr) continue;
				if ((n1 == nullptr && n2 != nullptr) || (n1 != nullptr && n2 == nullptr) || (n1->val != n2->val)) return false;
				que.push(n1->left);
				que.push(n2->left);
				que.push(n1->right);
				que.push(n2->right);
			}
		}
		else
			return false;
		return true;
	}

	bool isSameTreeByStack(TreeNode* p, TreeNode* q) {
		if (p == nullptr && q == nullptr) return true;
		if (p != nullptr && q != nullptr) {
			stack<TreeNode*> stk;
			stk.push(p);
			stk.push(q);
			while (!stk.empty()) {
				TreeNode* n1 = stk.top();
				stk.pop();
				TreeNode* n2 = stk.top();
				stk.pop();
				if (n1 == nullptr && n2 == nullptr) continue;
				if ((n1 == nullptr && n2 != nullptr) || (n1 != nullptr && n2 == nullptr) || (n1->val != n2->val)) return false;
				stk.push(n1->left);
				stk.push(n2->left);
				stk.push(n1->right);
				stk.push(n2->right);
			}
		}
		else
			return false;
		return true;
	}
};

void main() {}