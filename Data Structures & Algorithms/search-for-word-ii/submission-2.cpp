// create trie class
class TrieNode {
public:
    // create children nodes
    unordered_map<char, TrieNode*> children;

    // create is endWord
    bool endWord;

    // default constructor => every letter is false
    TrieNode() {
        this->endWord = false;
    }

    // method for adding an entire word to the Trie
    void addWord(const string & word) {
        // grab this nodes children
        TrieNode * curr = this;

        // iterate through each letter in word
        for (char c : word) {
            // check if char 'c' exist already in children at this point
            if (curr->children.find(c) == curr->children.end()) {
                // if c doesnt exist
                // 1. add c to mapping of current letter
                // 2. create a new TrieNode for the letter
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }

        // at the very end, set the word to true
        curr->endWord = true;
    }
};

class Solution {
public:
    // add a global results and global visited

    // can find the same word, so only store uniques
    // 1. use a set
    unordered_set<string> results; // store all the found words

    vector<vector<bool>> visited; // remember all visited nodes for call stack


    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // now create a root node instance
        TrieNode * root = new TrieNode();

        // store all words in TrieNode
        // 1. iterate through all words and call addWord()
        for (string word : words) {
            root->addWord(word); // curr = this : puts all the words added into THIS root
        }

        // now call DFS for every [row][col] index in board
        int ROWS = board.size();
        int COLS = board[0].size();

        // initialize visitied to be all false
        // 1. use the 'vector.assign()' syntax for initializing a vector
        visited.assign(ROWS, vector<bool>(COLS, false));

        for (int row = 0; row < ROWS; row++) {
            for (int col = 0; col < COLS; col++) {
                // Parameters:
                // 1. root to hold the words that have been added to the Trie
                // 2. board to check boundaries of get chars
                // 3. row, col to get current letter index from board
                // 4. empty string to possibly construct a new word
                dfs(root, board, row, col, "");
            }
        }

        // return the iterator of set to get vector 
        return vector<string>(results.begin(), results.end());
    }

    // now call DFS private helper function
private:
    // TODO:
    // 1. update the results set with the unique words that are being found in the board
    // 2. check if an index has been visited already in the call stack, and update call stack
    //    - set visited to false at the end to enable backtracking
    void dfs(TrieNode * root, vector<vector<char>>& board, int row, int col, string word) {
        // base case
        // 1. check if row or col are out of bounds
        // 2. check if char has been visited already
        // 3. check if char is NOT in the Trie
        //    - use map.count() to see if any children exist
        if (row < 0 || row >= board.size() ||
            col < 0 || col >= board[0].size() ||
            visited[row][col] ||
            !root->children.count(board[row][col])) {
            
            // return and do nothing
            return ;
        }

        // at this point, char is in bounds, char hasnt been visited, and char is in the Trie of valid words

        // 1. update visited
        visited[row][col] = true;

        // 2. point root to new current char in board
        root = root->children[board[row][col]];

        // 3. update word with new char
        word += board[row][col];

        // 4. insert word into results:
        if (root->endWord) {
            // insert to results set
            results.insert(word);
        }

        // dfs traversal over all 4 directions (up, down, left, right)
        dfs(root, board, row + 1, col, word); // down
        dfs(root, board, row - 1, col, word); // up
        dfs(root, board, row, col + 1, word); // right
        dfs(root, board, row, col - 1, word); // left

        // enable backtracking: set visited back to false for current char in board
        visited[row][col] = false;

        // return;
        return ;
    }
};
