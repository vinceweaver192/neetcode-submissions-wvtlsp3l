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
    unordered_map<TreeNode*, int> cache;

    int rob(TreeNode* root) {
        // brute force dfs start, use cache to optimize to O(n)
        //cache[NULL] = 0;

        return dfs(root);
    }

    int dfs(TreeNode* node) {
        if (node == NULL) {
            return 0;
        }

        // if node has already been visited, dont calculate
        if (cache.count(node)) {
            return cache[node];
        }

        int res = node->val;

        if (node->left) {
            res += dfs(node->left->left) + dfs(node->left->right);
        }
        if (node->right) {
            res += dfs(node->right->right) + dfs(node->right->left);
        }

        cache[node] = max(res, dfs(node->left) + dfs(node->right));
        
        return cache[node];
    }
};