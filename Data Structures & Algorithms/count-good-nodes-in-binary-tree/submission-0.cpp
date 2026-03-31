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
        // keep track of the max in path
        // use dfs for easier traversals for each path
        int result = dfs(root, root->val);

        return result;
    }

    int dfs(TreeNode * root, int maxVal) {
        // base case
        if (root == NULL) {
            return 0;
        }

        // left right traversal

        // initialize result to 0
        int result = 0;

        // but if current val is >= maxVal, then update result to start at 1 so the current val is accounted for!
        if (root->val >= maxVal) {
            // change good to 1
            result = 1;
        }

        // update max
        maxVal = max(maxVal, root->val);

        // traverse
        result += dfs(root->left, maxVal);
        result += dfs(root->right, maxVal);

        return result;
    }
};
