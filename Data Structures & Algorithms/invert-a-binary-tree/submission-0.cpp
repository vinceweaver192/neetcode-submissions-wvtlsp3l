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
    TreeNode* invertTree(TreeNode* root) {
        return dfs(root);
    }

    TreeNode* dfs(TreeNode * root) {
        // base case
        if (root == NULL) {
            return NULL;
        }

        // make left => right and vice versa
        TreeNode * left = dfs(root->left);
        TreeNode * right = dfs(root->right);

        root->left = right;
        root->right = left;

        return root; // last return will be the initial root node
    }
};
