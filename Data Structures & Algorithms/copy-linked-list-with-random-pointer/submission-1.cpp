/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    unordered_map<Node*, Node*> newNodes; // map original nodes to new nodes

    Node* createDeep(Node* node) {
        // base case
        if (node == NULL) {
            return node;
        }

        // create new node
        const int val = node->val;
        Node* newNode = new Node(val);

        // set the nodes into map
        newNodes[node] = newNode;

        // set its next to the recursive call
        newNode->next = createDeep(node->next);

        // set its random to this value of next nodes counterpart
        // all nodes will be created post traversal
        // check for null
        if (node->random != NULL) {
            Node* randNode = node->random;
            newNode->random = newNodes[randNode];
        }
        else {
            newNode->random = NULL; // might be handled already
        }

        // return current newNode
        return newNode;
    }

public:
    Node* copyRandomList(Node* head) {
        return createDeep(head);
    }
};
