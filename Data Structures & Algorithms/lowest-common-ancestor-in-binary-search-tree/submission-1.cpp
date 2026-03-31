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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // with BST, can search
        // Binary search both values at the same time
        // the first time a split is required, return result
        return dfs(root, p, q);
    }

    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        // base case
        if (root == NULL) {
            return NULL;
        }

        // bst search
        if ((root->val <= p->val && root->val >= q->val) ||
            (root->val >= p->val && root->val <= q->val)) {
            return root;
        }

        // traverse one direction
        if (root->val > p->val) {
            return dfs(root->left, p, q);
        }
        else {
            return dfs(root->right, p, q);
        }
    }
};
