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
    unordered_map<int, int> indices;

    // global counter for parsing preorder arr
    int idx = 0;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // calc the middle of inorder

        for (int i = 0; i < inorder.size(); i++) {
            indices[inorder[i]] = i; // map middle values to indices
        }

        return dfs(preorder, 0, inorder.size()-1);
    }

    TreeNode* dfs(vector<int>& preorder, int l, int r) {
        // base case, when l and r meet, this is for array traversal, populating both sides of tree
        if (l > r) {
            return NULL;
        }

        TreeNode* node = new TreeNode(preorder[idx]);
        idx++;

        // update mid with the map
        int mid = indices[node->val]; // mid == the map[val] = idx

        node->left = dfs(preorder, l, mid-1); // for left, populate with item left of middle, mid -1 to be inclusive
        node->right = dfs(preorder, mid+1, r);

        return node;
    }
};
