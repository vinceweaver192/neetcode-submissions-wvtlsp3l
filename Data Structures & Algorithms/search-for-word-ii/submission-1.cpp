class TrieNode {
public:
    // use a map instead of direct left and right pointers bc:
    //
    // traditional tree structure:
    // - int currentVal, Node->next OR Node->left/right
    // - Purpose: for singly linked list or binary trees,
    //            we create a known amount of pointers.
    //
    // Trie Structure:
    // - unordered_map<currentVal, Node*> children
    // - Purpose: this serves as an n-ary tree
    unordered_map<char, TrieNode*> children;

    // declare if a current letter is the end of a word or not 
    bool isWord;

    // Default Constructor
    TrieNode() {
        isWord = false;
    }

    // create function to add a word to a trie
    void addWord(const string& word) {
        // start at the current TrieNode's root
        TrieNode* cur = this;

        // iterate through entire word
        for (char c : word) {
            // check if c is currently a child in the current
            // layer of the word
            // Ex. B<-B<-root->A->B are 2 separate lists splitting
            //     from a unique top layer,
            //     - however, the character could have been added
            //       from another word, but we want to check
            
            // check if char exist in keys already for this 
            // specific sequence (see example 2nd B's above)
            if (!cur->children.count(c)) {
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c]; // update cur to point at the next
                                    // letter that was just added (or already added)

        }
        // set the last letter of the word to true to indicate that
        // at this point, all the letters before it up to here make
        // up a valid word
        cur->isWord = true;
    }
};

class Solution {
public:
    // global variables
    // store the unique words found in a set of strings
    unordered_set<string> results;

    // create a 2D vector to keep track of all the visited
    // cells in the matrix
    vector<vector<bool>> visited;

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // create a new instance of Trie using the default
        // constructor
        TrieNode* root = new TrieNode();

        // 1. iterate through each word in words
        // 2. use the add() func from Trie to add all the
        //    words and split them into Tries
        for (string word : words) {
            // since root is a ptr, need to point to functions
            root->addWord(word);
        }

        // for simplicity, create vars to be able to loop through board
        int ROWS = board.size();
        int COLS = board[0].size();

        // initialize all values in the 2D visited[] array with false using assign()
        // - syntax: vector.assign(x, vector<type>(y, default_values))
        visited.assign(ROWS, vector<bool>(COLS, false));

        // now iterate over entire board and call DFS on each letter
        // - DFS will take care of visited and handle ordering and Trie
        for (int row = 0; row < ROWS; row++) {
            for (int col = 0; col < COLS; col++) {
                // call dfs and include in parameters:
                // 1. board, 2. x/y, 3. root node, 4. empty string
                // - empty string bc the word will be constructed
                //   as it appears in the DFS
                dfs(board, row, col, root, "");
            }
        }
        // results is a set of the unique words as strings
        // 1. convert the set into a vector of strings
        // 2. return the vector of strings
        //
        // Syntax: using the vector<string> casting, return
        //         an iterator of the set using results.begin()/.end()
        return vector<string>(results.begin(), results.end());
    }

private:
    // dfs wont return anything since it will only update the global
    // variables and recursively traverse the board in the parameters
    void dfs(vector<vector<char>>& board,
                    int row, int col, 
                    TrieNode* root,
                    string word) {
        
        // initialize sizes of board
        int ROWS = board.size();
        int COLS = board[0].size();

        // base case, return if...
        // 1. if row or col is out of bounds
        // 2. if node has been visited already
        // 3. if node letter doesnt exist in any word in Trie
        if (row < 0 || col < 0 || row >= ROWS || col >= COLS ||
        visited[row][col] == true ||
        !root->children.count(board[row][col])) { // use map.count(val) to search 
            return;
        }

        // at this point, node is valid
        // update visited
        visited[row][col] = true;

        // update root to point at current letter
        root = root->children[board[row][col]];

        // update word string and concatenate new letter
        word += board[row][col];

        // check if the current letter added to word is the end
        // of a word, if so, then insert it into the results set
        if (root->isWord) {
            // insert to global results set
            results.insert(word);
        }

        // traverse all four directions of matrix (top, down, left, right)
        dfs(board, row+1, col, root, word); // right
        dfs(board, row-1, col, root, word); // left
        dfs(board, row, col+1, root, word); // down
        dfs(board, row, col-1, root, word); // up

        // Backtracking:
        // post-traversal, once current letter has been visited,
        // it will be removed from the stack and the visited[]
        // array can be updated so the letter in the matrix can
        // be revisited to fulfill another unique word
        visited[row][col] = false;
    }
};
