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
    int maxPathSum(TreeNode* root) {
        // initialize the result to store the 
        // max sum path
        int maxSum = root->val;

        // call recursive dfs
        dfs(root, maxSum);

        // return the result
        return maxSum;
    }

private:
    // use maxSum as global variable for storing overall max path 
    int dfs(TreeNode* root, int& maxSum) { // maintain updated max
        // base case
        if (root == nullptr){
            return 0;
        }

        // traverse left and right
        // 1. incase of negative children nodes, get max of (left, 0)
        int leftMax = max(dfs(root->left, maxSum), 0);
        int rightMax = max(dfs(root->right, maxSum), 0);

        // Calculate the max path sum WITH split:
        // Compare the current overall max with:
        // 1. the current leftmax and rightmax + the current node val
        maxSum = max(root->val + leftMax + rightMax, maxSum);

        // return has to return the max
        // at this current node (which will have its own left
        // and right nodes), return its value plus its left/right max
        // and that will be its max path val (no split)
        //
        // Return value will return the max left or right path, no split
        //
        // Split:
        // - means that the path will not go above that current node
        //   to any more parent nodes
        return root->val + max(leftMax, rightMax);
    }
};
