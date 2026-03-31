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
        // MUST READ AND UNDERSTAND QUESTION:
        // - path: sequence of nodes adjacent
        int result = INT_MIN;

        dfs(root, result);

        return result;
    }

    int dfs(TreeNode* root, int& result) {
        // base case
        if (root == NULL) {
            return 0; // do nothing
        }

        // traverse 
        // ignore negative values, breaks path
        // - max(left, 0) means we dont have to take left if left is negative sum
        int left = max(dfs(root->left, result), 0);
        int right = max(dfs(root->right, result), 0);

        // update max
        // calculate with split
        // if left or right (or both) are negative, then we can just take the root->val, or whichever is not negative
        // if root IS negative (ex. 1 + 2 + -1), then result will likely just hold a higher single val (ex. 2 for right side)
        result = max(result, left + right + root->val);

        // return MUST include the left or right max (keep track of NO split)
        return root->val + max(left, right);
    }
};
