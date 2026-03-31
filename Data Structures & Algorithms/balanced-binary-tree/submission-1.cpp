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
        if (root == NULL) {
            return true;
        }
        bool result = true;
        dfs(root, result);
        return result;
    }

    int dfs(TreeNode* root, bool& result) {
        // base case
        if (root == NULL) {
            return 0; // 0 does nothing
        }

        // traverse and calc left and right heights
        int left = dfs(root->left, result) + 1;
        int right = dfs(root->right, result) + 1;

        if (abs(left - right) > 1) {
            result = false;
            return -1;
        }

        return max(left, right); // return the max height so far of either side
    }
};
