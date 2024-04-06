#include <iostream>
#include <vector>
using namespace std;

//有一个升序数组，将改数组转化为一个高度平衡的二叉搜索树

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//其实这个题跟用前序和中序构造二叉树，后序和中序构造二叉树的题一样。传入参数时，使用闭区间或者左闭右开区间都行。
//而且构造的时候，节点都是取数组的中间位置，所以左右子树的高度平衡都是自然而然的事
class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return Helper(nums, 0, nums.size() - 1);
	}

	TreeNode* Helper(vector<int>& nums, int begin, int end) {
		if (end < begin) return nullptr;
		int mid = begin + (end - begin) / 2;
		TreeNode* temp = new TreeNode(nums[mid]);

		int leftbegin = begin;
		int leftend = mid - 1;

		int rightbegin = mid + 1;
		int rightend = end;

		temp->left = Helper(nums, leftbegin, leftend);
		temp->right = Helper(nums, rightbegin, rightend);

		return temp;
	}

	//第二次做
	TreeNode* sortedArrayToBST1(vector<int>& nums) {
		return sortedArrayToBSTHelper(nums, 0, nums.size());
	}

	TreeNode* sortedArrayToBSTHelper(vector<int>& nums, int begin, int end) {  //左闭右开区间
		if (begin == end)
			return nullptr;
		int size = end - begin;

		TreeNode* root = new TreeNode(nums[begin + size / 2]);
		root->right = sortedArrayToBSTHelper(nums, begin + size / 2 + 1, end);
		root->left = sortedArrayToBSTHelper(nums, begin, begin + size / 2);
		return root;
	}

	//稍微调整一下
	TreeNode* sortedArrayToBST2(vector<int>& nums) {
		return sortedArrayToBSTHelper(nums, 0, nums.size());
	}

	TreeNode* sortedArrayToBSTHelper(vector<int>& nums, int begin, int end) {
		if (begin == end)
			return nullptr;
		int mid = begin + (end - begin) / 2;

		TreeNode* root = new TreeNode(nums[mid]);
		root->right = sortedArrayToBSTHelper(nums, mid + 1, end);
		root->left = sortedArrayToBSTHelper(nums, begin, mid);
		return root;
	}
};

void main() {}
