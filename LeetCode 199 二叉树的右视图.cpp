#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//���ڼ�����վ�����������ұߣ���������ܿ��������нڵ�
struct TreeNode {
	int val;
	TreeNode* left, * right;
	TreeNode() :val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) :val(x), left(left), right(right) {}
};
class Solution {
public:
	vector<int> rightSideView(TreeNode* root) {    //��ʵ���ǲ���������ڱ�����ʱ��ֻ��ÿһ�����ұߵĽڵ�ż��뵽�����
		if (root == nullptr) return {};
		queue<TreeNode*> que;
		vector<int> res;
		que.push(root);
		while (!que.empty()) {
			int size = que.size();
			for (int i = 0; i < size; i++) {
				TreeNode* temp = que.front();
				que.pop();
				if (i == size - 1) res.push_back(temp->val);
				if (temp->left) que.push(temp->left);
				if (temp->right) que.push(temp->right);
			}
		}
		return res;
	}
};

void main() {}