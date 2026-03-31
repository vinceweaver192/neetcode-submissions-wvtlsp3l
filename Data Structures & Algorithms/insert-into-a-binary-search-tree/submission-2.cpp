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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // check if the new val is less or greater than current node
        // dfs until last possible node
        // - ONLY add new node if null next left or right == NULL

        TreeNode * node = new TreeNode(val);

        if (root == NULL) {
            return node;
        }

        dfs(root, node);

        return root;
    }

    void dfs(TreeNode* root, TreeNode* node) {
        // base:
        if (root == NULL) {
            // insert then return
            return;
        }

        // traverse
        if (node->val < root->val) {
            dfs(root->left, node);
            if (root->left == NULL) {
                root->left = node;
            }
        }
        else {
            dfs(root->right, node);
            if (root->right == NULL) {
                root->right = node;
            }
        }
        
    }
};