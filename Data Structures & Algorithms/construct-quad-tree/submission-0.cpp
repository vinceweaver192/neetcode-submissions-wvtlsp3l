/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        // call helper and return its root
        return helper(grid, grid.size(), 0, 0);
    }

    Node* helper(vector<vector<int>>& grid, int size, int x, int y) {
        // base case
        // if the size == 1x1 grid, return itself
        if (size == 1) {
            // create new node
            // default all leaves to true
            Node* tmp = new Node(grid[x][y], true);
            return tmp;
        }

        // calc mid point split
        int mid = size / 2;

        // create recursive directional nodes
        Node* topleft = helper(grid, mid, x, y);
        Node* topright = helper(grid, mid, x, y + mid);
        Node* bottomleft = helper(grid, mid, x + mid, y);
        Node* bottomright = helper(grid, mid, x + mid, y + mid);

        // check if all values are equal, then return one node and set all sub nodes leaf to true
        // AND check that all values are leaves
        if (topleft->isLeaf && topright->isLeaf &&
            bottomleft->isLeaf && bottomright->isLeaf &&
            topleft->val == topright->val &&
            topright->val == bottomleft->val &&
            bottomleft->val == bottomright->val) 
        {
            Node* tmp = new Node(topleft->val, true);
            return tmp;
        } // if not, then set leaves to false
        else {
            // assign the values to tmp and set leaves to false
            Node* tmp = new Node(true, false, topleft, topright, bottomleft, bottomright);
            return tmp;
        }
        
    }
};