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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool match = false;
        dfs(root, subRoot, match);
        return match;
    }

    void dfs(TreeNode* root, TreeNode* subRoot, bool& match) {
        // find start of subRoot, then find exact match
        // base case
        if (root == NULL) {
            return;
        }

        if (root->val == subRoot->val) {
            match = exactMatch(root, subRoot);
            if (match) {
                return;
            }
        }

        // traverse
        dfs(root->left, subRoot, match);
        dfs(root->right, subRoot, match);

        //return true;
    }

    bool exactMatch(TreeNode* root, TreeNode* subRoot) {
        // base case
        if (root == NULL && subRoot == NULL) {
            return true;
        }

        if ((root == NULL && subRoot != NULL) ||
            (root != NULL && subRoot == NULL) ||
            (root->val != subRoot->val)) {
            return false;
        }

        // traverse
        // if either returns false, then return false
        return (exactMatch(root->left, subRoot->left) && exactMatch(root->right, subRoot->right));
    }
};
