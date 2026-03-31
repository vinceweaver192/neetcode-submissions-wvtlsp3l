/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> oldToNew;

    Node* cloneGraph(Node* node) {
        // call dfs on current node and recursively traverse through each neighbor

        // check to make sure neighbor node isnt in map already

        // MUST create new Node types
        //Node * copyNode = new Node();

        //oldToNew[node] = copyNode;

        //dfs(node, NULL);

        return dfs(node);
    }

    Node* dfs(Node * node) {
        // check for null or node FIRST
        if (node == NULL) {
            return NULL;
        }
        
        // base case, check map
        if (oldToNew.count(node)) {
            // if found, return it
            return oldToNew[node];
        }

        // create new node with val of node
        Node * newNode = new Node(node->val);

        // add node to map
        oldToNew[node] = newNode;

        // point new node to all of neighbors

        // iterate over all neighbors
        for (auto neighbor : node->neighbors) {
            newNode->neighbors.push_back(dfs(neighbor));
        }

        return newNode;
    }
};
