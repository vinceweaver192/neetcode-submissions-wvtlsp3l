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
        vector<vector<int>> result;

        // bfs iterative with queue
        if (root == NULL) {
            return result;
        }

        queue<TreeNode*> q;

        // push root into q
        q.push(root);

        while (!q.empty()) {
            // iterate over every level of depth, use a vector to store
            vector<int> level;

            // store the current size
            int size = q.size();

            for (int i = 0; i < size; i++) {
                // add left and right node to level and to queue

                // get current top node
                TreeNode* top = q.front();

                // check for null node
                if (top != NULL) {
                    q.push(top->left);
                    q.push(top->right);

                    // add to level
                    level.push_back(top->val);
                }

                // remove top
                q.pop();
            }

            // now append level vector to results
            // check to make sure level isnt empty
            if (!level.empty()) {
                result.push_back(level);
            }
            
        }

        return result;
    }
};
