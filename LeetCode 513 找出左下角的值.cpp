#include <iostream>
#include <queue>
using namespace std;

//��ĿҪ�����ҳ����������½ǵ�ֵ�������һ�ŵ�һ��ֵ���������뵽�ò��������
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
	int findBottomLeftValue(TreeNode* root) {
		queue<TreeNode*> que;
		que.push(root);
		int result = 0;
		while (!que.empty()) {
			int size = que.size();
			for (int i = 0; i < size; i++) {
				TreeNode* cur = que.front();
				que.pop();
				if (i == 0) result = cur->val;
				if (cur->left) que.push(cur->left);
				if (cur->right) que.push(cur->right);
			}
		}
		return result;
	}
};

//�ݹ鷨Ҳ����
class Solution1 {
public:
	int result;
	int maxDepth = INT_MIN;
	void traversal(TreeNode* node, int depth) {
		if (node->left == nullptr && node->right == nullptr) {
			if (depth > maxDepth) {
				maxDepth = depth;
				result = node->val;
			}
			return;
		}
		//��ʼ��ʱ�����벻��������ô�������һ��Ҷ�ӽڵ�������һ���ġ�
		//�������֣�������Ϊ���ҵı���˳����ôresult������һ���ǵ�һ��Ҷ�ӽ�㡣��Ϊ������ң����ж��������ǲ���Ҷ�ӣ�����Ǿͱ�����
		//Ȼ����Ϊif(depth>maxDepth)������ͬһ�������Ҷ�ӾͲ����ٿ����ˡ�
		if (node->left) traversal(node->left, depth + 1);
		if (node->right) traversal(node->right, depth + 1);
	}

	int findBottomLeftValue(TreeNode* root) {
		traversal(root, 1);
		return result;
	}
	//�������򵥵ľ����ò�������������õݹ鷨�Ļ���̫��������ΪҪ�����һ���һ���ڵ��ֵ���������ǰ�к����У�ֻҪ���ӱ��Һ������Ⱦ��У������ڸ��������ȵ�ͬʱ������ʹ�������ȸ��µĽڵ��ֵ���С�
	//�������򵥵ľ����ò�������������õݹ鷨�Ļ���̫��������ΪҪ�����һ���һ���ڵ��ֵ���������ǰ�к����У�ֻҪ���ӱ��Һ������Ⱦ��У������ڸ��������ȵ�ͬʱ������ʹ�������ȸ��µĽڵ��ֵ���С�
};

void main() {}