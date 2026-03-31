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
        // dfs post order, count backwards k times
        vector<int> results;
        dfs(root, results);
        return results[k-1];
    }

    void dfs(TreeNode* root, vector<int>& results) {
        if (root == NULL) {
            return;
        }

        // traverse to smallest
        dfs(root->left, results); // find smallest, hit null, then return first smallest (+1)

        results.push_back(root->val);

        dfs(root->right, results);
    }
};
