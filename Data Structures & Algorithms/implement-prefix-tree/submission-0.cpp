class PrefixTree {
public:
    unordered_map<char, PrefixTree*> children;
    bool endWord;

    PrefixTree() {
        this->endWord = false;
    }
    
    void insert(string word) {
        // create a new instance of a root
        PrefixTree * root = this;

        // iterate through every char
        for (char c : word) {
            // if DOESNT exist in children, add new node
            if (!root->children.count(c)) {
                // if count is false/null, then empty and can add
                root->children[c] = new PrefixTree();
            }
            // increment root
            root = root->children[c];
        }

        // make last word = true
        root->endWord = true;
    }
    
    bool search(string word) {
        // match ending char in word string and check if endWord is true
        PrefixTree * root = this;

        // iterate through word
        for (char c : word) {
            // check if char exist
            // 1. if char doesnt exist, return false
            if (!root->children.count(c)) {
                return false;
            }
            // iterate to next letter in root
            root = root->children[c];
        }

        // now at last letter, check if it is an end word, or return endWord
        return root->endWord;
    }
    
    bool startsWith(string prefix) {
        // loop through every char in prefix
        // 1. if string reaches end and everything matches, return true
        PrefixTree * root = this;

        for (char c : prefix) {
            if (!root->children.count(c)) {
                // if children dont exist for letter, return false
                return false;
            }
            // increment to next in Trie
            root = root->children[c];
        }

        return true;
    }
};


