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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // bfs
        string result = "";

        queue<TreeNode*> q;

        q.push(root);

        while (!q.empty()) {
            // size
            int size = q.size();

            for (int i = 0; i < size; i++) {
                // only add current node
                TreeNode* tmp = q.front();

                q.pop();

                if (tmp != NULL) {
                    // need commas for values > 9
                    result += to_string(tmp->val) + ",";
                    q.push(tmp->left);
                    q.push(tmp->right);
                }
                else {
                    // null
                    result += "N,";
                }
            }
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // use getline to grab numbers that are greater than 9
        // use bfs
        stringstream ss(data);
        string val = "";
        char delim = ',';

        // getline progresses stringstream and updates it
        getline(ss, val, delim); // store the next node in string inside val

        // check if root val == "N"
        if (val == "N") {
            return NULL;
        }
        
        // convert val from getline string to int and update/remember root (return val)
        TreeNode* root = new TreeNode(stoi(val));

        queue<TreeNode*> q;
        q.push(root);

        // use getline for looping
        while (getline(ss, val, delim)) {
            // val will now start AFTER root val
            // 1. grab and pop the front of q
            TreeNode* tmp = q.front(); // starts at root
            q.pop(); // remove any element grabbed

            // 2. check val as left node and make sure value is not "N" char
            if (val != "N") {
                // update left and create new node for it
                tmp->left = new TreeNode(stoi(val));
                // tmp is a pointer, so it is mimicking root at first
                // still need to update queue
                q.push(tmp->left);
            }

            // same for right
            // need to grab next line with getline
            getline(ss, val, delim);

            if (val != "N") {
                // update left and create new node for it
                tmp->right = new TreeNode(stoi(val));
                // tmp is a pointer, so it is mimicking root at first
                // still need to update queue
                q.push(tmp->right);
            }
        }

        return root;
    }
};
