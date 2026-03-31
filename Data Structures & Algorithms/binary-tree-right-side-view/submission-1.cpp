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
    vector<int> rightSideView(TreeNode* root) {
        // calc max depth level
        vector<int> results;

        //results.push_back(root->val);

        int height = 1;

        dfs(root, results, height);

        return results;
    }

    int dfs(TreeNode* root, vector<int>& results, int height) {
        // base case
        if (root == NULL) {
            return 0;
        }

        if (results.size() < height) {
            results.push_back(root->val);
        }


        // traverse right side first
        int right = dfs(root->right, results, height + 1);
        int left = dfs(root->left, results, height + 1);

        return max(right, left);
    }
};
