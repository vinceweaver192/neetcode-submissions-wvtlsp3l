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
    // preorder = [1,2,3,4] 
    // inorder  = [2,1,3,4]

    // create global indices
    // populate indices with inorder vector
    // map the val -> index in inorder vector
    unordered_map<int, int> indices;

    // use global variable for iterating
    int preIdx = 0;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // populate hashmap
        for (int i = 0; i < inorder.size(); i++) {
            indices[inorder[i]] = i;
        }

        // pass in:
        // preorder list, left boundary (0), right boundary (size of preorder)
        return dfs(preorder, 0, preorder.size()-1);
    }

    TreeNode* dfs(vector<int>& preorder, int l, int r) {
        // base case;
        // ONLY break base case when boundaries for left and right meet
        if (l > r) {
            return NULL;
        }

        // do EVERYTHING in preorder traversal time
        
        // create new node and assign value in preorder idx
        TreeNode * node = new TreeNode(preorder[preIdx]);

        // increment counter
        preIdx++;

        // update middle index boundary by finding the middle node in inorder hashmap
        int mid = indices[node->val];

        // traverse left and right and set node left and right
        node->left = dfs(preorder, l, mid - 1);
        node->right = dfs(preorder, mid + 1, r);

        // post order return to return all leaf nodes and last return is the root node
        return node;
    }
};
