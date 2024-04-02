#include <iostream>
using namespace std;

//这个题是要把每个节点的值换为大于或等于该结点的值的所有节点值的和。
//因为这是二叉搜索树，显然最大的数在右下角，所以大于等于该结点值的结点都在其右边，所以只要按着右中左的顺序就行。这正好是中序遍历的逆序。

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
	int pre = 0;
	TreeNode* convertBST(TreeNode* root) {
		if (root == nullptr) return nullptr;
		convertBST(root->right);
		root->val += pre;
		pre = root->val;
		convertBST(root->left);

		return root;
	}

	//第二次做
    int sum = 0;
    TreeNode* convertBST1(TreeNode* root) {
        //先遍历一遍二叉树，获得节点值的和，最后中序遍历依次用sum递减前一个节点的值
        //或者也可以用一个值保存前一个节点的值，然后在当前层遍历中减去前一个节点的值

        if (root == nullptr) return nullptr;

        sum = getSum(root);
        cout << sum;
        convertBSTHelper(root);
        return root;
    }

    int getSum(TreeNode* root) {
        if (root == nullptr) return 0;
        int leftSum = getSum(root->left);
        int rightSum = getSum(root->right);
        return root->val + leftSum + rightSum;
    }

    void convertBSTHelper(TreeNode* root) {
        if (root == nullptr) return;
        convertBSTHelper(root->left);
        int value = root->val;
        root->val = sum;
        sum -= value;
        convertBSTHelper(root->right);
    }

    //看了答案才发现可以用右中左的遍历顺序，sum表示当前节点的前一个节点的值，也就是当前节点右边的所有节点值的和
    int sum = 0;
    TreeNode* convertBST2(TreeNode* root) {
        if (root == nullptr) return nullptr;
        convertBST2(root->right);
        root->val += sum;
        sum = root->val;
        convertBST2(root->left);
        return root;
    }
};

void main() {}