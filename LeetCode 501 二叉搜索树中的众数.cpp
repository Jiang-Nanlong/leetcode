#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//Ҫ���ҳ������������е����������������кü���
//�ʼ�뵽�ľ����ȱ���һ�������������Ȼ����unordered_map����ÿһ���ڵ�ֵ�ĳ��ִ�������������򣬷��س��ִ������ļ����������ַ������������뵽�ģ�����û�����õ�������������һ�ص㡣
//���ﻹ����������������preָ��Ľڵ�Ϊ�գ�˵���ǵ�һ���ڵ㣬count=1�����preָ��Ľڵ�͵�ǰ�ڵ�ֵһ����count++�����preָ��Ľڵ��ֵ�͵�ǰ�Ĳ�һ������ôcount=1.
//Ȼ����maxcount��¼����count�����count==maxcount�Ļ����ڵ��ֵ����ӣ����maxcount���µĻ�������������գ�Ȼ��ѵ�ǰ�ڵ�����ȥ��

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

	vector<int> findMode(TreeNode* root) {
		Helper(root);
		return res;
	}
	int maxcount = 0, count = 0;
	vector<int> res;
	TreeNode* pre = nullptr;
	void Helper(TreeNode* root) {
		if (root == nullptr) return;
		Helper(root->left);   //��

		if (pre == nullptr)   //��
			count = 1;
		else if (pre->val == root->val)
			count++;
		else  //pre->val��root->val����ͬ
			count = 1;

		if (count == maxcount)
			res.push_back(root->val);

		if (count > maxcount) {
			maxcount = count;
			res.clear();
			res.push_back(root->val);
		}

		pre = root;
		Helper(root->right); //��
	}

	//ǰ�����õݹ����ģ��ݹ������ĵ���Ҳ����
	vector<int> findMode1(TreeNode* root) {
		stack<TreeNode*> stk;
		vector<int> res;
		TreeNode* cur = root;
		TreeNode* pre = nullptr;
		int count = 0, maxcount = 0;
		while (cur || !stk.empty()) {
			if (cur) {
				stk.push(cur);
				cur = cur->left;  //��
			}
			else {
				cur = stk.top();  //��
				stk.pop();
				if (pre == nullptr)
					count = 1;
				else if (pre->val == cur->val)
					count++;
				else
					count = 1;

				if (count == maxcount)
					res.push_back(cur->val);
				if (count > maxcount) {
					maxcount = count;
					res.clear();
					res.push_back(cur->val);
				}

				pre = cur;
				cur = cur->right;  //��

			}
		}
		return res;
	}
};

void main() {}