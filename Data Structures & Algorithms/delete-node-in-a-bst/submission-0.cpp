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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        if (key > root->val) {
            // Search in the right subtree
            root->right = deleteNode(root->right, key);
        } else if (key < root->val) {
            // Search in the left subtree
            root->left = deleteNode(root->left, key);
        } else {
            // Node found
            if (!root->left && !root->right) {
                // Case 1: No children (leaf node)
                delete root;
                return nullptr;
            } else if (!root->left) {
                // Case 2: Only right child
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {
                // Case 2: Only left child
                TreeNode* temp = root->left;
                delete root;
                return temp;
            } else {
                // Case 3: Two children
                TreeNode* successor = root->right;
                while (successor->left) {
                    successor = successor->left;
                }
                // Replace current node's value with successor's value
                root->val = successor->val;
                // Delete successor node from right subtree
                root->right = deleteNode(root->right, successor->val);
            }
        }

        return root;
    }
};
