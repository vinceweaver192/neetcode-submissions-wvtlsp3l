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

// Solution Approach:
// 1. serialize tree using pre-order traversal and store into string
//    - TODO:
//      o helper function to populate a vector with pre-order elements
//      o join() the string using output string stream oss => ostringstream
// 2. deserialize tree using pre-order traversal and traverse from a list
//    - TODO:
//      o helper function to create and populate nodes from a vector of string elements
//      o BEFORE creating tree, must split a string of data into a vector

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // create vector of strings to store results
        vector<string> result;

        // call dfs helper func
        serializeDFS(root, result);

        // join the vector together into a string
        return join(result, ',');
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // convert from string to a vector of string elements
        vector<string> results = split(data);

        // call dfs helper to handle creating Tree with results
        // - pass in starting index of list
        int index = 0;

        return deserializeDFS(results, index);
    }


private:

    // split the string into vector items
    vector<string> split(string data) {
        // create a string stream and initialize with string data
        stringstream ss(data);

        // create delimeter
        char delim = ',';

        // create string to store each item
        string item;

        // create results vector to store total elements
        vector<string> results;

        // use getline to iterate through stream
        // syntax: use a 'while' loop it iterate through getline()
        while (getline(ss, item, delim)) {
            results.push_back(item);
        }

        // return vector
        return results;
    }

    // create dfs for deserializing and creating the tree node from a vector of elements
    // - MUST make index a reference because of null base case index increments
    TreeNode* deserializeDFS(vector<string>& results, int& index) {
        // base case:
        if (results[index] == "N") {
            // increment index, return null ptr
            index++;
            return nullptr;
        }

        // create a new TreeNode *
        // - increment index AFTER grabbing current value in results
        TreeNode * root = new TreeNode(stoi(results[index]));

        // pre-order increment index
        index++;

        // traverse left and right
        root->left = deserializeDFS(results, index);
        root->right = deserializeDFS(results, index);

        // return the current node
        return root;
    }

    // create join function to convert from vector of strings to one string
    string join(vector<string>& results, char delim) {
        // create output stream
        ostringstream oss;

        // iterate and push to stream
        for (int i = 0; i < results.size(); i++) {
            oss << results[i];
            if (i != results.size()-1) {
                oss << delim;
            }
        }

        // return a string converted stream
        // syntax: stream.str() => returns the string output
        return oss.str();
    }

    // create serialize helper func
    // 1. dont return anything, just update the vector and store results
    void serializeDFS(TreeNode * root, vector<string> & results) {
        // base case
        if (root == nullptr) {
            results.push_back("N");
            return;
        }

        // pre-order store the current node val inside vector
        // - Convert val to string
        results.push_back(to_string(root->val));

        // traverse left then right
        serializeDFS(root->left, results);
        serializeDFS(root->right, results);

        // once here, break and return
        return;
    }
};
