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

//Ӧ���Ƿ������������һ�֣�ɾ������Ҷ�ӽ�㣬��ôֱ��ɾ�����С��ڶ��֣����ɾ�������м�ڵ㣬��������ڵ�ֻ��һ����֧����ô�������ķ�֧�ڵ��������λ�ü��ɡ�
//�����֣����ɾ�������м�ڵ㣬��������ڵ���������֧���Ҽǵ���������˵���������ӻ��Һ���������ɣ�Ȼ�󻹵õ���Ҫ����ڵ�ĺ���

class Solution {
public:

	/*
		TreeNode* pre = nullptr;

		TreeNode* deleteNode(TreeNode* root, int key) {
			if (root->val == key) {
				if (root->left == nullptr && root->right == nullptr) {  //root��Ҷ�ӽڵ�
					if (root->val < pre->val)
						pre->left = nullptr;
					else pre->right = nullptr;
				}
				else if (root->left == nullptr && root->right) {    //root���м�ڵ㣬����ֻ��һ������
					if (root->val < pre->val)
						pre->left = root->right;
					else
						pre->right = root->right;
				}
				else if (root->left && root->right == nullptr) {
					if (root->val < pre->val)
						pre->left = root->left;
					else
						pre->right = root->left;
				}
				else {  //root���м�ڵ㣬���������ӣ�

					if (pre->val > root->val) {
						pre->left = root->left;
						pre->left->right = root->right;
					}
					else {
						pre->right = root->left;
						pre->right->right = root->right;
					}
					TreeNode* temp = root->left->right;
					TreeNode* p = root->right;
					while (p->left) p = p->left;
					p->left = temp;
				}
				free(root);
				return;
			}

			pre = root;
			if (root->val > key) deleteNode(root->left, key);
			if (root->val < key) deleteNode(root->right, key);

			return root;
		}
	*/
	//�ϱ������ʼд�ģ��һ���û����õݹ麯���ķ���ֵ���⣬��д����ֵ��ʱ��֪��զд�ˣ���ʵӦ����61��62�н���һ�µġ�Ҫ�ǰ��ҵ�д���Ļ��������Ͳ����з���ֵ�ġ�
	//�±����ҿ��˴�������¼�Ĵ���д�ģ����ĳ�����ǰ�����������һ���ģ��������һ�ֲ�һ��������ֱ�ӰѴ�ɾ���ڵ����������������ӵ��������������£�Ȼ�����������ĸ��ڵ����ɾ���ڵ��λ��
	//��������һ�£�����û�з���ֵ��ȷʵ��̫�У���ΪҪɾ���Ŀ����Ǹ��ڵ㡣���д��û�з���ֵ�ģ�ֻ������deleteNode�е������������Ȼ�󷵻�root������ɾ���Ľڵ���ܾ���root
	TreeNode* deleteNode(TreeNode* root, int key) {
		if (root == nullptr) return nullptr;  //��Ȼ�����Ҳ����ڵ��������

		if (root->val == key) {
			if (root->left == nullptr && root->right == nullptr) {  //root��Ҷ�ӽڵ�
				delete root;
				return nullptr;
			}
			else if (root->left == nullptr && root->right) {    //root���м�ڵ㣬����ֻ��һ������
				TreeNode* temp = root->right;
				delete root;
				return temp;
			}
			else if (root->left && root->right == nullptr) {
				TreeNode* temp = root->left;
				delete root;
				return temp;
			}
			else {  //root���м�ڵ㣬���������ӣ�
				TreeNode* temp = root->right;
				while (temp->left)
					temp = temp->left;
				temp->left = root->left;
				TreeNode* cur = root;
				temp = root->right;
				delete cur;
				return temp;
			}
		}

		if (root->val > key) root->left = deleteNode(root->left, key);
		if (root->val < key) root->right = deleteNode(root->right, key);

		return root;
	}

	//�ڶ�������ֱ��ʹ�õĵ�����û�õݹ�
	TreeNode* deleteNode1(TreeNode* root, int key) {
		if (root == nullptr)
			return nullptr;
		TreeNode* preroot = new TreeNode(-1);  //��һ��ͷ��㣬��ֹ��ɾ�����Ǹ��ڵ�
		preroot->right = root;
		TreeNode* parent = preroot, * cur = root;
		while (cur) {
			if (cur->val > key) {
				parent = cur;
				cur = cur->left;
			}
			else if (cur->val < key) {
				parent = cur;
				cur = cur->right;
			}
			else if (cur->val == key) {
				TreeNode* temp = nullptr;
				if (cur->left == nullptr && cur->right) {
					temp = cur->right;
				}
				else if (cur->left && cur->right == nullptr) {
					temp = cur->left;
				}
				else if (cur->left && cur->right) {
					TreeNode* rightOfRoot = cur->right;
					while (rightOfRoot->left)
						rightOfRoot = rightOfRoot->left;
					rightOfRoot->left = cur->left;
					temp = cur->right;
				}

				if (cur->val > parent->val) parent->right = temp;
				else parent->left = temp;
				delete cur;
				cur = nullptr;
			}
		}
		return preroot->right;
	}

	//�ֿ��Ŵ�д��һ���ݹ�İ汾
	TreeNode* deleteNode2(TreeNode* root, int key) {
		if (root == nullptr) return nullptr;
		if (root->val == key) {
			if (root->left == nullptr && root->right == nullptr) {
				delete root;
				return nullptr;
			}
			else if (root->left == nullptr && root->right) {
				TreeNode* temp = root->right;
				delete root;
				return temp;
			}
			else if (root->left && root->right == nullptr) {
				TreeNode* temp = root->left;
				delete root;
				return temp;
			}
			else {
				TreeNode* cur = root->right;
				while (cur->left)
					cur = cur->left;
				cur->left = root->left;
				TreeNode* temp = root->right;
				delete root;
				return temp;
			}
		}
		if (root->val > key) root->left = deleteNode2(root->left, key);
		if (root->val < key) root->right = deleteNode2(root->right, key);
		return root;
	}
};

void main() {

}