#include <iostream>
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
};

void main() {}