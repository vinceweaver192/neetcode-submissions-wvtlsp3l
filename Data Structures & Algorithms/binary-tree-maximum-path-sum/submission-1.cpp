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

// Solution Approach:
// 1. call DFS helper function and pass in root node and 

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        // create var to store result
        int maxSum = INT_MIN;

        // call dfs helper
        dfs(root, maxSum);

        // return
        return maxSum;
    }

private:
    // create dfs helper
    int dfs(TreeNode* root, int& maxSum) {
        // base case
        if (root == nullptr) {
            return 0;
        }

        // traverse left and right and return max
        int leftMax = max(dfs(root->left, maxSum), 0);
        int rightMax = max(dfs(root->right, maxSum), 0);

        // calculate max with root cross-over added
        // - compare and return the overall max between combined max, 0
        maxSum = max(maxSum, leftMax + rightMax + root->val);
        return root->val + max(leftMax, rightMax);
    }
};
