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
private:
    TreeNode* removeTargets(TreeNode* node, int& target) {
        if (node == NULL) {
            return NULL;
        }

        node->left = removeTargets(node->left, target);
        node->right = removeTargets(node->right, target);

        if (node->val == target && !node->left && !node->right) {
            delete(node);
            return NULL;
        }

        return node;
    }

public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        // delete current node if
        // 1. it == target
        // 2. has no children
        return removeTargets(root, target);
    }
};