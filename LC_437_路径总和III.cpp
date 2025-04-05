//
// Created by cml on 25-4-5.
//
#include <iostream>
#include <unordered_map>
#include <functional>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {
    }

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {
    }
};

class Solution {
public:
    int pathSum(TreeNode *root, int targetSum) {
        unordered_map<long long, int> umap;
        umap[0] = 1;
        long long presum = 0;
        int res = 0;
        function<void(TreeNode *)> dfs = [&](TreeNode *cur)-> void {
            if (!cur)
                return;

            presum += cur->val;
            res += umap[presum - (long long) targetSum];
            umap[presum]++;
            dfs(cur->left);
            dfs(cur->right);
            umap[presum]--;
            presum -= cur->val;
        };
        dfs(root);
        return res;
    }
};

int main() {
}
