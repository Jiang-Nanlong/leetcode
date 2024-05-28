#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

//����һ������ü򵥣���������û�����
//��

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root->val > p->val && root->val > q->val)
			return lowestCommonAncestor(root->left, p, q);
		else if (root->val < p->val && root->val < q->val)
			return lowestCommonAncestor(root->right, p, q);
		else
			return root;
	}

	TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {
		while (root) {
			if (root->val > p->val && root->val > q->val)
				root = root->left;
			else if (root->val < p->val && root->val < q->val)
				root = root->right;
			else
				return root;
		}
		return nullptr;
	}

	//�ڶ���������û��������������˼·��ʵ�ܼ򵥣�����ڱ����Ĺ����У���ǰ�ڵ��ֵ��һ�γ�����p��q֮�䣬��ô��ǰ�ڵ��һ���������������

	TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL) return NULL;

		if (root->val > p->val && root->val > q->val) {
			return lowestCommonAncestor(root->left, p, q);
		}
		else if (root->val < p->val && root->val < q->val) {
			return lowestCommonAncestor(root->right, p, q);
		}
		else
			return root;
	}

	TreeNode* lowestCommonAncestor3(TreeNode* root, TreeNode* p, TreeNode* q) {
		while (root) {
			if (root->val > p->val && root->val > q->val)
				root = root->left;
			else if (root->val < p->val && root->val < q->val)
				root = root->right;
			else
				return root;
		}
		return NULL;
	}

	//��������
	TreeNode* lowestCommonAncestor4(TreeNode* root, int p, int q) {
		if (root == NULL)
			return NULL;
		if (root->val > p && root->val > q)
			return lowestCommonAncestor4(root->left, p, q);
		else if (root->val < p && root->val < q)
			return lowestCommonAncestor4(root->right, p, q);
		else
			return root;
	}

	TreeNode* buildTree(vector<string>& nums) {
		if (nums.empty()) return nullptr;

		TreeNode* root = new TreeNode(stoi(nums[0]));
		queue<TreeNode*> que;
		que.push(root);

		int i = 1;
		while (i < nums.size()) {
			TreeNode* node = que.front();
			que.pop();

			if (nums[i] != "null") {
				node->left = new TreeNode(stoi(nums[i]));
				que.push(node->left);
			}
			i++;

			if (i < nums.size() && nums[i] != "null") {
				node->right = new TreeNode(stoi(nums[i]));
				que.push(node->right);
			}
			i++;
		}
		return root;
	}
};

int main() {
	Solution st;
	vector<string> num{ "6","2","8","0","4","7","9","null","null","3","5" };
	TreeNode* root = st.buildTree(num);
	TreeNode* parent = st.lowestCommonAncestor4(root, 2, 4);
	cout << parent->val << endl;
	return 0;
}