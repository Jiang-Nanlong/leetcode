#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

//���Ǵ�ҽ�����⣬������ط��ӵ�����˳���ɶ������ˣ����ǵݹ�Ͷ�̬�滮��ϵ�һ���⣬��Ŀ�е�dp���鲻���Ǹ����еĽڵ�ͳһ���䣬���ǵݹ��ÿһ�㣬Ҳ����ÿһ���ڵ㶼��һ���Լ���dp����
//dp[0]��ʾ��͵��ǰ�ڵ�����ֵ��dp[1]��ʾ͵��ǰ�ڵ�����ֵ

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
	int rob(TreeNode* root) {
		vector<int> res = robRange(root);
		return max(res[0], res[1]);
	}

	vector<int> robRange(TreeNode* root) {
		if (root == nullptr) return { 0,0 };

		vector<int> leftdp = robRange(root->left);  //������������dp����
		vector<int> rightdp = robRange(root->right);  //������������dp����

		int val1 = max(leftdp[0], leftdp[1]) + max(rightdp[0], rightdp[1]);   //��͵��ǰ�ڵ�����ֵ
		int val2 = root->val + leftdp[0] + rightdp[0];   //͵��ǰ�ڵ�����ֵ
		return { val1,val2 };
	}


	//�ڶ�����������dp��һ��
	int rob1(TreeNode* root) { // �������
		vector<int> res = robHelper(root);
		return max(res[0], res[1]);
	}
	vector<int> robHelper(TreeNode* root) {
		if (root == nullptr)
			return vector<int>{0, 0};
		vector<int> left = robHelper(root->left);
		vector<int> right = robHelper(root->right);

		vector<int> dp(2);
		dp[0] = max(left[0], left[1]) + max(right[0], right[1]);
		dp[1] = root->val + left[0] + right[0];
		return dp;
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

			if (i < nums.size() && nums[i] != "null") {
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
	vector<string> nums{ "3","2","3","null","3","null","1" };
	TreeNode* root = st.buildTree(nums);
	cout << st.rob(root) << endl;
	return 0;
}