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
    bool isValidBST(TreeNode* root) {
        return dfs(root, INT_MIN, INT_MAX);
    }

    bool dfs(TreeNode* root, int minbound, int maxbound) {
        if (root == NULL) {
            return true;
        }

        // check current node in comparison to boundaries
        if (root->val <= minbound || root->val >= maxbound) {
            return false;
        }

        // traverse
        // save result if false
        // if either side returns false, then ultimately return false
        return (dfs(root->left, minbound, root->val) && dfs(root->right, root->val, maxbound));
    }
};
