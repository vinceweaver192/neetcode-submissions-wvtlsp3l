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
    int diameterOfBinaryTree(TreeNode* root) {
        // when recursing, save the max at any point and return it
        int result = 0;
        dfs(root, result);
        return result;
    }

    // add & reference to maxVal to remember and store val back to original func call
    int dfs(TreeNode * root, int& maxVal) {
        // base:
        if (root == NULL) {
            return 0;
        }

        // calc max of left and max right
        // do nothing with maxVal here, just return
        int left = dfs(root->left, maxVal);
        int right = dfs(root->right, maxVal);

        // find the all time max and store it in param variable
        // this max will handle checking the combined max
        // ONLY do maxVal storing AFTER left and right have been calculated
        maxVal = max(maxVal, left + right);

        // return this nodes combined max SINGLE path
        return max(left, right) + 1; // return + 1 for current node
    }
};
