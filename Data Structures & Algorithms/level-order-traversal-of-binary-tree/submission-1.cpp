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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // bfs
        vector<vector<int>> result;
        queue<TreeNode*> q;

        if (root == NULL) {
            return result;
        }

        q.push(root);
        result.push_back({root->val});

        while (!q.empty()) {
            // get size of q
            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; i++) {
                // add left and right of current node to queue
                TreeNode* top = q.front();
                if (top->left != NULL) {
                    q.push(top->left);
                    level.push_back(top->left->val);
                }
                if (top->right != NULL) {
                    q.push(top->right);
                    level.push_back(top->right->val);
                }

                // remove top after each iteration
                q.pop();
            }

            if (!q.empty()) {
                result.push_back(level);
            }

        }

        return result;

    }
};
