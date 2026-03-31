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
        int res = 0;
        dfs(root, res);
        return res;
    }

    int dfs(TreeNode* root, int& res) {
        // base case
        if (root == NULL) {
            return 0;
        }

        // traverse
        int left = dfs(root->left, res);
        int right = dfs(root->right, res);

        // get length of both left and right
        int m = left + right;

        res = max(res, m);

        return max(left + 1, right + 1); 
    }
};
