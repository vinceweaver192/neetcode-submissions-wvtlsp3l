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
        // use a global var vector to store the
        // pre-order traversal of each node in root
        vector<string> result; // store each val in a string so the result
                               // can be stored into one string separated by commas
        
        // call helper function for dfs traversal
        serializeDFS(root, result);

        // return the joined list into a csv
        // *** This doesn't actually modify the vector itself,
        //    - it just uses the vector to return a string value.
        string ans = join(result,",");
        cout << "After Join: " << ans << endl;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // separate the string data back into a vector
        // use the split(data, ",") which returns an array
        // *** delim MUST be a char (single quotes) ***
        vector<string> values = split(data, ',');

        // use an index value to keep track of the current
        // node in the string
        int index = 0;

        // call helper function to deserialize using DFS
        // use the return value to return the root of the 
        // completed Tree
        return deserializeDFS(values, index);
    }

private:
    // create function for split, return a vector of string chars
    // delim MUST be a char to be used in getline(, , delim) properly
    vector<string> split(const string & vals, char delim) {
        // create a vector to hold and return the results
        vector<string> result;

        // create a string stream to read from the vals
        stringstream ss(vals);

        // create a string to read from each item
        string item;

        cout << "splitting: ";
        // loop through the string using getline()
        // getline syntax: getline(stringstream, val, delim)
        while (getline(ss, item, delim)) {
            // delim uses the delim to separete the string
            // into multiple items
            cout << item << " ";
            result.push_back(item);
        }
        cout << endl;
        return result;
    }

    // create function for join, return a string
    string join(const vector<string> &vals, const string &delim) {
        // use an output string stream
        ostringstream oss;

        cout << "joining: ";
        // loop through entire vector
        for (int idx = 0; idx < vals.size(); idx++) {
            if (idx != 0) { // dont add delim to first val
                // to add to an output string stream, use <<
                oss << delim;
            }
            //cout << val << " ";
            // add every val to the oss
            oss << vals[idx];
        }
        cout << endl;

        // convert the stream into a string and return it
        return oss.str();
    }
    
    // use the referenced values of what was passed in
    // to maintain the current global values
    TreeNode* deserializeDFS(vector<string>& vals, 
                            int &index) {
        // base case
        // check current index in vector
        if (vals[index] == "N") {
            // increment index
            index++;
            return nullptr;
        }

        // at this point, current node is valid
        // 1. create node
        // 2. set current nodes val to what is stored in array
        // *** need to convert string to int (stoi())
        TreeNode* node = new TreeNode(stoi(vals[index]));

        // now increment the index to go to next val
        index++;

        // Can now begin left/right traversals
        // 1. set the current nodes left/right ptrs to the 
        //    recursive call
        // 2. The structure of the string (pre-order traversals)
        //    will get handled since we are handling the array
        //    before we traverse, the NULLs are being handled 
        //    by the base case, and we are favoring left side 
        //    traversals first
        node->left = deserializeDFS(vals, index); // we are returning 
                                                  // a pointer
        node->right = deserializeDFS(vals, index);

        // return current node
        return node;
    }

    void serializeDFS(TreeNode* root, 
                      vector<string>& result) {
        // base case
        if (root == nullptr) {
            // if the current node is null, add an 'N'
            // to indicate this is a null node in the 
            // pre-order traversal
            result.push_back("N");
            return;
        }

        // otherwise, node here is not null, and the val can
        // be pushed back
        // TODO: need to convert value to a string first: to_string()
        result.push_back(to_string(root->val));

        // after pre-order operations have been done, can now 
        // begin left and right traversals
        serializeDFS(root->left, result);
        serializeDFS(root->right, result);

    }
};
