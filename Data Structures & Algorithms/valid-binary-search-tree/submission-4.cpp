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
        // Basis of Solution:
        // - Create left and right boundaries during tree traversal
        // - ex, -inf < 1 < 2

        // create starting boundaries
        return dfs(root, INT_MIN, INT_MAX);
    }

    bool dfs(TreeNode * node, int leftBound, int rightBound){
        // base case, our true condition
        if (node == NULL) {
            return true;
        }

        // check current node, our false condition
        if (node->val >= rightBound || node->val <= leftBound) {
            return false;
        }

        // return our results from our traversal
        return (dfs(node->left, leftBound, node->val) && dfs(node->right, node->val, rightBound));
    }
};
