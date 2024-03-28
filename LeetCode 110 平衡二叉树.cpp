#include <iostream>
#include <algorithm>
using namespace std;

//�ж�һ�����ǲ���ƽ�������

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
	bool isBalanced(TreeNode* root) {
		return Height(root) == -1 ? false : true;
	}
	int Height(TreeNode* node) {  //ע��ݹ���Ҫ��
		if (node == nullptr) return 0;

		int leftHeight = Height(node->left);
		if (leftHeight == -1) return -1;
		int rightHeight = Height(node->right);
		if (rightHeight == -1) return -1;
		return abs(leftHeight - rightHeight) > 1 ? -1 : 1 + max(leftHeight, rightHeight);
	}


	//�ڶ�����������û�������������һ���Ƚ���Ҫ�ĵط��ǵ��ú����������һ������ʱ��û������ΪɶҪ�ú��������Ҳû��ע
	//���ڵڶ������������о�ȷʵ��ֻ���ú����������Ϊ��ǰ����Ļ�����ÿһ����û���Ƚ�����������������Ȳ
	bool isBalanced1(TreeNode* root) {
		return getHeight(root) == -1 ? false : true;
	}
	int getHeight(TreeNode* root) {
		if (root == nullptr) return 0;
		int leftheight = getHeight(root->left);
		if (leftheight == -1) return -1;
		int rightheight = getHeight(root->right);
		if (rightheight == -1) return -1;
		if (abs(leftheight - rightheight) > 1)
			return -1;
		return 1 + max(leftheight, rightheight);
	}
};

void main() {}