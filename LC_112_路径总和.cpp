#include <iostream>
#include <vector>
#include <string>
#include <queue>
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
		return hasPathSumHelper1(root, targetSum, 0);
	}
	bool hasPathSumHelper1(TreeNode* root, int targetSum, int sum) {
		if (root == nullptr && sum == targetSum)  //����ط���Ӧ����root==nullptr����Ϊ����[1,2]��target=1���������ʱ����ֱ����1������������true��
			//�����������Ϊ�գ�1Ҳ����Ҷ�ӽ�㡣����Ҫ�޸��ж����������Ҷ�ӽ������ˣ�������������
			return true;

		if (root == nullptr && sum != targetSum)
			return false;

		bool leftflag =
			hasPathSumHelper1(root->left, targetSum, sum + root->val);
		if (leftflag)
			return true;
		bool rightflag =
			hasPathSumHelper1(root->right, targetSum, sum + root->val);
		if (rightflag)
			return true;
		return leftflag || rightflag;
	}

	//�����Ժ�
	bool hasPathSum2(TreeNode* root, int targetSum) {
		if (root == nullptr)
			return false;
		return hasPathSumHelper2(root, targetSum, 0);
	}
	bool hasPathSumHelper2(TreeNode* root, int targetSum, int sum) {
		if (root->left == nullptr && root->right == nullptr) {
			if ((sum + root->val) == targetSum)
				return true;
			else
				return false;
		}

		if (root->left)
			if (hasPathSumHelper2(root->left, targetSum, sum + root->val))
				return true;

		if (root->right)
			if (hasPathSumHelper2(root->right, targetSum, sum + root->val))
				return true;

		return false;  //����Ҳ����д��return leftflag || rightflag;����Ϊ���ǰ����true��ֱ�ӷ����ˣ���������������
	}

	// ��������
	bool hasPathSum3(TreeNode* root, int targetSum) {
		if (root == nullptr)
			return false;
		return backtrace(root, 0, targetSum);
	}

	bool backtrace(TreeNode* root, int sum, int targetSum) {
		sum += root->val;
		if (root->left == nullptr && root->right == nullptr) {
			if (sum == targetSum)
				return true;
			else
				return false;
		}

		/*bool left = false, right = false;
		if (root->left)
			left = backtrace(root->left, sum, targetSum);
		if (root->right)
			right = backtrace(root->right, sum, targetSum);
		if (left || right)
			return true;*/
			// �����Ż�һ��
		if (root->left)
			if (backtrace(root->left, sum, targetSum))
				return true;
		if (root->right)
			if (backtrace(root->right, sum, targetSum))
				return true;
		return false;
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
	vector<string> num{ "5","4","8","11","null","13","4","7","2","null","null","null","1" };
	TreeNode* root = st.buildTree(num);
	cout << boolalpha << st.hasPathSum3(root, 22) << noboolalpha << endl;
	return 0;
}