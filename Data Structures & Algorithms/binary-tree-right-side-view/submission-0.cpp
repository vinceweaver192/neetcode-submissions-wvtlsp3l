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
        // simple solution concept:
        //
        // bfs:
        // for every level, only store the right most node
        // - can do this by iterating over every val in queue and storing the last val

        queue<TreeNode*> q;

        q.push(root);

        //TreeNode * node = NULL;

        vector<int> result;

        while (!q.empty()) {
            // reset the right node
            TreeNode* rightNode = NULL;

            // get q size
            int size = q.size();

            for (int i = 0; i < size; i++) {
                TreeNode * node = q.front();

                // pop node
                q.pop();

                // grab every node, ensuring right node will be last val (right most val)
                if (node != NULL) {
                    rightNode = node;

                    // iterate left first then right
                    q.push(node->left);
                    q.push(node->right);
                }

            }

            // ensure right node is NOT null
            if (rightNode != NULL) {
                result.push_back(rightNode->val);
            }
        }
        return result;
    }
};
