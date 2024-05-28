#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;


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
	//Ӧ���������������
	TreeNode* trimBST(TreeNode* root, int low, int high) {
		/*
		* //�������Լ�д�Ĵ��룬�����delete rootһֱ�������������Ϻö���Ҳ����Ӧ������⣬��֪��Ϊʲô
		* //���������±ߵĴ���Ƚϣ���˼·���������������ֻ�ǰ�Ҫɾ���ڵ�����ӻ��Һ��ӷ����ˣ���û�п������������Һ����Ƿ���Ϸ�Χ��
		* //�ͱ���˵[3,1,4,null,2] low=3,high=4.�������е��ڵ�1��ʱ���ֱ�ӷ���2�ˣ���ʱ��2�����1��λ�ã����ǳ��򲻻�����1��λ�������еڶ��飬
		* //���Ծ�������2�����Ǵ�ʱ��2Ҳ�ǲ�����Ҫ��ġ�
		* //�±ߵĴ��������λ�����ֵݹ��ˣ������ͽ����������⡣
		*
		if(root==nullptr) return nullptr;
		if(root->val<low){
			TreeNode*temp=root->right;
			//delete root;
			return temp;
		}else if(root->val>high){
			TreeNode* temp=root->left;
			//delete root;
			return temp;
		}

		root->left=trimBST(root->left,low,high);
		root->right=trimBST(root->right,low,high);
		return root;
		*/

		if (root == nullptr) return nullptr;
		if (root->val < low) {
			TreeNode* temp = trimBST(root->right, low, high);
			return temp;

		}
		else if (root->val > high) {
			TreeNode* temp = trimBST(root->left, low, high);
			return temp;
		}

		root->left = trimBST(root->left, low, high);
		root->right = trimBST(root->right, low, high);
		return root;
	}

	//������ҵ�һ������ʱ��Ȼ��д������࣬�Ҳ�
	//�ڶ�����������û��������
	TreeNode* trimBST1(TreeNode* root, int low, int high) {
		if (root == nullptr)
			return nullptr;
		if (root->val < low) {
			TreeNode* temp = trimBST1(root->right, low, high);  //��ǰ�ڵ�����������ܷ���������Ȼ���޼�������
			return temp;
		}
		else if (root->val > high) {
			TreeNode* temp = trimBST1(root->left, low, high);   //��ǰ�ڵ�����ӿ��ܷ��������������޼�������
			return temp;
		}
		root->left = trimBST1(root->left, low, high);
		root->right = trimBST1(root->right, low, high);
		return root;
	}

	// ��������������û��д����
	TreeNode* trimBST2(TreeNode* root, int low, int high) {
		if (root == nullptr)
			return nullptr;
		if (root->val < low) {
			TreeNode* left = trimBST(root->right, low, high);
			return left;
		}
		if (root->val > high) {
			TreeNode* right = trimBST(root->left, low, high);
			return right;
		}
		root->left = trimBST(root->left, low, high);
		root->right = trimBST(root->right, low, high);
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

	vector<string> levelOrder(TreeNode* root) {
		queue<TreeNode*> que;
		vector<string> res;
		if (root == nullptr)
			return res;
		else
			que.push(root);

		while (!que.empty()) {
			int size = que.size();
			for (int i = 0; i < size; i++) {
				TreeNode* cur = que.front();
				que.pop();
				res.push_back(to_string(cur->val));

				if (cur->left) que.push(cur->left);
				if (cur->right) que.push(cur->right);
			}
		}
		return res;
	}
};

int main() {
	Solution st;
	vector<string> num{ "3","0","4","null","2","null","null","1" };
	TreeNode* root = st.buildTree(num);
	root = st.trimBST2(root, 1, 3);
	vector<string> res = st.levelOrder(root);
	for (auto& c : res)
		cout << c << "  ";

	return 0;
}