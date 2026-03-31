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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> result;

        dfs(root, result);

        return result[k-1];
    }

    void dfs(TreeNode * root, vector<int>& result) {
        // base case
        if (root == NULL) {
            return;
        }

        // pre order traversal to get to smallest val
        dfs(root->left, result);

        // now check if k == 1, then return
        result.push_back(root->val);

        dfs(root->right, result);
    }
};
