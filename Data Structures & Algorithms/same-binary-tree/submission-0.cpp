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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool result = true;
        dfs(p, q, result);
        return result;
    }

    void dfs(TreeNode* p, TreeNode* q, bool& result) {
        // base case
        if (p == NULL && q == NULL) {
            return;
        }

        if ((p == NULL && q != NULL) || 
            (p != NULL && q == NULL) ||
            p->val != q->val) {
            result = false;
            return;
        }

        // traverse
        dfs(p->left, q->left, result);
        dfs(p->right, q->right, result);

    }
};
