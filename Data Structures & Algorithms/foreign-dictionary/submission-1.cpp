class Solution {
public:
    // create adjacency list as a global variable
    // 1. char key for each letter
    // 2. set value to a set of all letters that come after the key letter 
    //    - (order doesnt matter unless specified in another rule)
    unordered_map<char,unordered_set<char>> adj;

    // create a map to handle each character and decide if it has been
    // visited in DFS in current call stack
    unordered_map<char,bool> visited;

    // store resulting lexicon string order
    string result;

    string foreignDictionary(vector<string>& words) {
        // loop through all words in words[] and all letters in each word
        // and store them as a potential key in adj[] list
        for (string word : words) {
            for (char c : word) {
                adj[c];
            }
        }

        // now loop through all words using indices
        for (int i = 0; i < words.size()-1; i++) { // size-1 bc we are using the current word and the +1 word
            string w1 = words[i];
            string w2 = words[i+1];

            // calculate the prefix
            int minWord = min(w1.size(), w2.size());

            // edge case, check prefix and order
            if (w1.size() > w2.size() &&
            w1.substr(0,minWord) == w2.substr(0,minWord)){
                return "";
            }

            // at this point, words are good
            // loop through all characters for a difference
            for (int j = 0; j < minWord; j++) {
                if (w1[j] != w2[j]) {
                    // 1. find first difference
                    // 2. add to adj list
                    // 3. break
                    adj[w1[j]].insert(w2[j]); // w1 comes before w2

                    break;
                }
            }
        }

        // check for a cycle using DFS
        // call DFS on every key in adj[]
        for (auto pair : adj) {
            // dfs only takes keys as parameters
            if (dfs(pair.first) == true) { // true == cycle exist
                return "";
            }
        }

        // at this point, result should be populated correctly
        // since DFS, the result string is in reverse order
        // syntax: for strings, 
        // - just call reverse(.begin(), .end())
        reverse(result.begin(), result.end());
        return result;
    }

private:

    // dfs helper return bool
    bool dfs(char c) {
        // base case:
        // 1. check if char has been in visited stack already
        // *** use map.find(key) != map.end() ***
        // Purpose:
        // - .find() avoids key:value insertion and avoids error
        //   if key doesn't exist
        if (visited.find(c) != visited.end()) {
            // return what is stored in visited,
            // 1. true means cycle exist
            // 2. false means 'c' has already been processed 
            //    and can be skipped
            return visited[c];
        }

        // at this point, c is good and can be processed
        // set visited to true to remember it is in call stack
        visited[c] = true;

        // now traverse the unique letters in the set corresponding 
        // to the current char 'c' in the adj[] list
        for (char next : adj[c]) {
            // check if dfs returned true for a cycle and echo
            if (dfs(next) == true) {
                return true;
            }
        }

        // exiting call stack
        visited[c] = false;

        // update result and return
        result += c;

        return false;
    }
};
