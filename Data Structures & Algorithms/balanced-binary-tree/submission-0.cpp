/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        // no more than size difference > 1 allowed
        bool result = true;
        dfs(root, result);
        return result;
    }

    int dfs(TreeNode * root, bool& result) {
        // base:
        if (root == NULL) {
            return 0;
        }

        int leftSize = dfs(root->left, result);
        int rightSize = dfs(root->right, result);

        if (abs(leftSize - rightSize) > 1) {
            result = false;
        }

        return max(leftSize, rightSize) + 1;
    }
};
