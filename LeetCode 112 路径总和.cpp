#include <iostream>
using namespace std;

//�ж�һ�������Ƿ����һ���Ӹ��ڵ㵽Ҷ�ӽ���·����·���Ͻڵ�ĺ͵���targetSum������У�����true�����û�У�����false��
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
	bool hasPathSum(TreeNode* root, int targetSum) {
		if (root == nullptr) return false;
		return Helper(root, targetSum, 0);
	}

	bool Helper(TreeNode* node, int targetSum, int sum) {
		sum += node->val;
		if (node->left == nullptr && node->right == nullptr) {
			if (sum == targetSum) return true;
		}
		if (node->left) {
			if (Helper(node->left, targetSum, sum)) return true;
		}
		if (node->right) {
			if (Helper(node->right, targetSum, sum)) return true;
		}
		return false;
	}

	//�ڶ�������������
	bool hasPathSum1(TreeNode* root, int targetSum) {
		if (root == nullptr)
			return false;
		return hasPathSumHelper(root, targetSum, 0);
	}
	bool hasPathSumHelper(TreeNode* root, int targetSum, int sum) {
		if (root == nullptr && sum == targetSum)  //����ط���Ӧ����root==nullptr����Ϊ����[1,2]��target=1���������ʱ����ֱ����1������������true��
			//�����������Ϊ�գ�1Ҳ����Ҷ�ӽ�㡣����Ҫ�޸��ж����������Ҷ�ӽ������ˣ�������������
			return true;

		if (root == nullptr && sum != targetSum)
			return false;

		bool leftflag =
			hasPathSumHelper(root->left, targetSum, sum + root->val);
		if (leftflag)
			return true;
		bool rightflag =
			hasPathSumHelper(root->right, targetSum, sum + root->val);
		if (rightflag)
			return true;
		return leftflag || rightflag;
	}

	//�����Ժ�
	bool hasPathSum2(TreeNode* root, int targetSum) {
		if (root == nullptr)
			return false;
		return hasPathSumHelper(root, targetSum, 0);
	}
	bool hasPathSumHelper(TreeNode* root, int targetSum, int sum) {
		if (root->left == nullptr && root->right == nullptr) {
			if ((sum + root->val) == targetSum)
				return true;
			else
				return false;
		}

		if (root->left)
			if (hasPathSumHelper(root->left, targetSum, sum + root->val))
				return true;

		if (root->right)
			if (hasPathSumHelper(root->right, targetSum, sum + root->val))
				return true;

		return false;  //����Ҳ����д��return leftflag || rightflag;����Ϊ���ǰ����true��ֱ�ӷ����ˣ���������������
	}
};

void main() {}