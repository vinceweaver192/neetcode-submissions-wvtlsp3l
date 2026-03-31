class WordDictionary {
public:
    // add global Trie variable
    // 1. be sure to make value in mapping a * pointer!!!
    unordered_map<char, WordDictionary*> children;

    // 2. we NEED to add endWord to be able to search effectively in search()
    bool endWord;

    WordDictionary() {
        // default endWord to false
        this->endWord = false;
    }
    
    void addWord(string word) {
        // grab the current root
        WordDictionary * root = this;

        // iterate over word
        for (char c : word) {
            // check if word doesnt already exist in Trie, then add
            if (!root->children.count(c)) {
                root->children[c] = new WordDictionary();
            }
            // traverse root to children
            root = root->children[c];
        }
        // endWord IS necessary
        // 1. at this point, assign the last letter of word to true
        root->endWord = true;
    }
    
    bool search(string word) {
        // matching:
        // 1. call DFS to perform recursive matching with '.' char
        // 2. use an index to verify all the letters in word (up to this point in the index) are valid characters
        WordDictionary * root = this;
        int index = 0;
        return dfs(root, word, index);
    }

private:
    // call dfs helper function
    bool dfs(WordDictionary * root, string word, int idx) {
        // no base case needed

        // iterate from starting idx to size of word
        for (int i = idx; i < word.size(); i++) {
            // 1. get current letter at index
            char c = word[i];

            // 2. check if letter is a '.'
            if (c == '.') {
                // char can be any char in Trie

                // traverse children in root
                for (auto pair : root->children) {
                    // child == pair.second
                    WordDictionary* child = pair.second;

                    // check if:
                    // 1. child doesnt equal nullptr
                    // 2. dfs of the next child returns true
                    //    - increment the starting idx by 1 since '.' letter is valid
                    if (child != nullptr && dfs(child, word, i + 1)) {
                        return true;
                    }
                }
                // if all current children dont have a path that leads to true, then return false
                return false;
            }
            else { // 3. letter is NOT a '.', perform exact char matching
                if (root->children.find(c) == root->children.end()) {
                    // if key 'c' doesnt exist in current children mapping, return false
                    return false;
                }
                // move to next letter
                root = root->children[c];
            }
        }
        // at this point, return if the end of a word has been reached
        // 1. return the current roots endword bool value
        //    - if the current is not the end word, then it will not match and return false
        //    - if IS an endword, then will return true
        return root->endWord;
    }
};
