#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

// 从根节点到叶节点的数字，每个数都比孩子节点的位权大一个，比如从跟到叶节点的路径为 4->9->5，代表数字495

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int sum;
    int sumNumbers(TreeNode* root) {
        if (root == nullptr)
            return 0;
        sum = 0;

        backtrace(root, 0);
        return sum;
    }
    void backtrace(TreeNode* root, int count) {
        count = count * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            sum += count;
            return;
        }
        if (root->left)
            backtrace(root->left, count);
        if (root->right)
            backtrace(root->right, count);
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
    vector<string> nums{ "4","9","0","5","1"};
    TreeNode* root = st.buildTree(nums);
    int res = st.sumNumbers(root);
    cout << res << endl;
    return 0;
}