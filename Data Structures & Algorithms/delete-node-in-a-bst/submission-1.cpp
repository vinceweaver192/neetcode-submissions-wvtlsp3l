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
    // Binary search for node

    // RULES:
    // recursively replace the key node with values from its next greatest value 
    // 1. (one to the right and then furthest left for smallest val that is greater)

    // Ensure only nodes with no children or 1 child (left or right) get deleted
    // 2. the key value will recursively be replaced by values stated in rule 1
    TreeNode* deleteNode(TreeNode* root, int key) {


        // base case
        if (root == NULL) {
            return NULL;
        }

        // binary search
        if (key < root->val) {
            // go left
            // and update this current root val on the way back up after shifts occured from finding the next key
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val) {
            // go right and do the same root node updates to remember changes from shifts after finding key
            root->right = deleteNode(root->right, key);
        }
        else {
            // node is found

            // Case 1: left node AND right node dont exist (leaf node)
            if (root->left == NULL && root->right == NULL) {
                // simply delete node and return null
                delete root;
                return NULL;
            } // Case 2: left node doesnt exist BUT right node does (return right node)
            else if (root->left == NULL) {
                // remember right node BEFORE delete
                TreeNode* tmp = root->right;
                delete root;
                return tmp;
            } // Case 3: opposite of case 2
            else if (root->right == NULL) {
                TreeNode* tmp = root->left;
                delete root;
                return tmp; // this get caught by the root->left/right from above and updated back into original root
            } // Case 4: left AND right nodes exist
            else {
                // store tmp node for pointing at right node (see rule 1 on top)
                TreeNode* tmp = root->right;

                // iterate to smallest node (furthest left)
                while (tmp->left != NULL) {
                    tmp = tmp->left;
                }

                // tmp now at smallest node, tmp->left IS NULL
                // store current root with tmp val
                root->val = tmp->val;

                // recursively call delete again BUT with new root val as key (recursively update swap, eventually delete to prevent memory leaks)
                root->right = deleteNode(tmp, root->val);
            }
        }
        return root;
    }
};
