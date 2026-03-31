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
    int goodNodes(TreeNode* root) {
        int count = 0;

        dfs(root, INT_MIN, count);

        return count;
    }

    void dfs(TreeNode* root, int maxVal, int& count) {
        // base case
        if (root == NULL) {
            return;
        }

        if (root->val >= maxVal) {
            maxVal = root->val;
            count++;
        }

        dfs(root->left, maxVal, count);
        dfs(root->right, maxVal, count);
    }
};
