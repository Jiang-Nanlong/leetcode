#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left, * right;
	TreeNode() :val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) :val(x), left(left), right(right) {}
};

class Solution {
public:
	int countNodes(TreeNode* root) {   //�������
		if (root == nullptr) return 0;
		queue<TreeNode*> que;
		int count = 0;
		que.push(root);
		while (!que.empty()) {
			int size = que.size();
			count += size;
			for (int i = 0; i < size; i++) {
				TreeNode* cur = que.front();
				que.pop();
				if (cur->left) que.push(cur->left);
				if (cur->right) que.push(cur->right);
			}
		}
		return count;

	}

	//�������õݹ�����
	//int getNodesNum(TreeNode* cur) {  //ȷ���ݹ麯���Ĳ����ͷ���ֵ
	//	if (cur == nullptr) return 0;   //ȷ����ֹ����
	//	//ȷ������ݹ��߼�>>>
	//	int leftNum = getNodesNum(cur->left);
	//	int rightNum = getNodesNum(cur->right);
	//	int treeNum = 1 + leftNum + rightNum;
	//	return treeNum;
	//	//ȷ������ݹ��߼�<<<
	//}
	//int countNodes(TreeNode* root) {
	//	return getNodesNum(root);
	//}
	//��Ϊ�±����֣������Ѿ��������ݹ���Ҫ����

	/*int countNodes(TreeNode* root) {
		if (root == nullptr) return 0;
		return 1 + countNodes(root->left) + countNodes(root->right);
	}*/

	//�±��Ǵ�������¼�ķ�������������Ƚ�����
	//���һ��������ȫ����������ô���Ľڵ����������������
	//1.����һ����������
	//2.����һ����ȫ������
	//����������������Ϳ���ֱ��ͨ�������ڵ�����������������������ͷֱ�������������������������������������������ͨ�������ڵ�����
	int countNodes1(TreeNode* root) {
		if (root == nullptr)
			return 0;
		TreeNode* left = root->left;
		TreeNode* right = root->right;
		int leftdepth = 0, rightdepth = 0;
		while (left) { //������whileѭ�������ж���ȫ�������ǲ���������������Ϊ�Ѿ�����ȫ�������ˣ�������ߵ������ͬ�Ļ�����ô����һ����������
			leftdepth++;
			left = left->left;
		}
		while (right) {
			rightdepth++;
			right = right->right;
		}

		if (rightdepth == leftdepth) {
			return (2 << leftdepth) - 1;
		}
		return 1 + countNodes(root->left) + countNodes(root->right);
	}
};

void main() {}