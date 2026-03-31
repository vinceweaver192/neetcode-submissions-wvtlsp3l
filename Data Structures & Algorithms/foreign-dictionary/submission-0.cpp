class Solution {
public:
    // DFS Approach with Adjacency List
    // * Need public vars to reference from DFS helper function

    // create an adjacency list (directed graph):
    // map each character to a unique set
    // of characters of each word
    unordered_map<char, unordered_set<char>> adj;

    // detect cycles when traversing through adjacency list
    // using depth first search post ordering
    unordered_map<char, bool> visited;

    // keep track of result lexicon
    string result;

    string foreignDictionary(vector<string>& words) {
        // for all words in array words, and all chars in each word
        // map the characters to adj and 
        for (string word : words){
            for (char c : word){
                // assign each character an entry in the adjacency list
                adj[c];
            }
        }

        // loop through all word pairs to create rules in
        // the lexicon (words[] is already sorted)
        for (int i = 0; i < words.size()-1; i++){
            // compare word1 chars with word2 chars
            string w1 = words[i];
            string w2 = words[i+1];

            // explicit edge case mentioned:
            // - if prefix comes after whole word (invalid)
            // - prefix is always smaller than whole word
            //   meaning, we can just compare size
            int minWord = min(w1.size(), w2.size());
            
            // if word1 == whole word (size bigger)
            // and word2 == prefix (size smaller)
            // AND
            // word1 (up to substr) exactly matches word2 (up to substr)
            // then both words have the same sub string
            // Ex. word1 == apes , word2 == ape , minWord = 3
            if (w1.size() > w2.size() && 
            w1.substr(0, minWord) == w2.substr(0, minWord)){
                return ""; // invalid
            }

            // if we get here, then words are valid
            // loop through every character of both words AND identify
            // the character differences between letters in the same position
            // of each word
            // only need to identify up to minWord size
            for (int j = 0; j < minWord; j++) {
                // if current letters differ, update adjacency list AND indegree
                if (w1[j] != w2[j]){
                    // Since word1 comes before word2 alphabetically:
                    // 1. map character from word1 to its corresponding set
                    // 2. insert the differing letter from word2 into the set
                    adj[w1[j]].insert(w2[j]);

                    // break after 1st difference since thats what determined
                    // the alien lexicon ordering
                    break;
                }
            }
        }

        // 1. Create and call DFS helper to traverse adj list 
        // 2. Loop for every key in adj
        // *** As long as no cycle exist, there can exist multiple 
        //     solutions, and in that case, any solution would suffice
        for (auto pair : adj) {
            if (dfs(pair.first)) {
                return "";
            }
        }

        // reverse the DFS printed order and return result
        reverse(result.begin(), result.end());
        return result;
    }

    bool dfs(char c){
        // Base Case
        // return value stored in visited[c]: true == (IS part of current path)
        //
        // 1. if char is found: 
        // - if char is already visited in visited, 
        //   we will return true (we have a cycle == invalid/no solution)
        // - if char is not visited, return false indicating that
        //   char has already been processed and can be skipped
        //
        // 2. if char is NOT found:
        // - if char is not in visited[c], then move forward with
        //   processing the char
        if (visited.find(c) != visited.end()){
            return visited[c];
        }

        // set visited[c] to true since it we are about to begin recursive traversal
        visited[c] = true;

        // begin iteration of next char in set of chars corresponding to
        // the current earliest lexicon char in the adjacency list 
        //
        // *** Each set containts unique letters that come after its key char ***
        for (char next : adj[c]){
            // recursively call each next letter in the set() assigned to adj[c]
            // and determine its ordering and rules and if a cycle exist
            if (dfs(next)){
                // if true, then cycle detected, echo true cycle statement
                return true;
            }
        }

        // Now mark current char in visited as 'false'
        // 1. False indicates that node has been fully processed, and no longer
        //    part of the current path
        // 2. False also indicates it is safe to revisit as long as a new rule
        //    applies to the current character
        visited[c] = false;

        // now current char is safe to add to the result string
        // since the dfs approach goes for depth, and this is current
        // position in the dfs function is after the traversal (post order),
        // we are actually starting at the last letter in the lexicon that
        // corresponds to the our adj list []
        // from alien to english, the order in result will be from z - a (needs
        // to be reversed before fully returning)
        result.push_back(c);

        // at this point, can return false since no cycle was detected during this
        // iteration for this character
        return false;
    }
};
