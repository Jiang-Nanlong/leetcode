#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
right(right) {}
};

class Solution {
public:
    vector<int> nodes;
    TreeNode* balanceBST(TreeNode* root) {
        nodes.clear();
        inOrder(root);
        return buildTreeByInOrder(nodes, 0, nodes.size() - 1);
    }

    void inOrder(TreeNode* root) {
        if (root == nullptr)
            return;
        inOrder(root->left);
        nodes.push_back(root->val);
        inOrder(root->right);
    }

    TreeNode* buildTreeByInOrder(vector<int>& nodes, int begin, int end) {
        if (end >= begin) {
            int mid = begin + (end - begin) / 2;
            TreeNode* root = new TreeNode(nodes[mid]);
            root->left = buildTreeByInOrder(nodes, begin, mid - 1);
            root->right = buildTreeByInOrder(nodes, mid + 1, end);

            return root;
        }
        return nullptr;
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
    vector<string> nums{ "1","null","2","null","3","null","4","null","null" };
    TreeNode* root = st.buildTree(nums);
    TreeNode* res = st.balanceBST(root);
    vector<string> vec = st.levelOrder(res);
    for (string& s : vec)
        cout << s << "  ";
    cout << endl;
    return 0;
}