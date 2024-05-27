#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
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

	// ��������
	bool isBalanced2(TreeNode* root) {
		return isBalancedHelper(root) == -1 ? false : true;
	}

	int isBalancedHelper(TreeNode* root) {
		if (root == nullptr)
			return 0;

		int leftHeight = isBalancedHelper(root->left);
		int rightHeight = isBalancedHelper(root->right);

		if (leftHeight == -1 || rightHeight == -1)
			return -1;
		if (abs(leftHeight - rightHeight) > 1)
			return -1;
		else
			return 1 + max(leftHeight, rightHeight);
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
	vector<string> nums{ "3","9","20","null","null","15","7" };
	TreeNode* root = st.buildTree(nums);
	cout << boolalpha << st.isBalanced2(root) << noboolalpha << endl;
	return 0;
}