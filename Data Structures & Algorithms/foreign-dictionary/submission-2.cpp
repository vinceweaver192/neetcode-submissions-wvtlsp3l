// Approach:
// 1. populate adjacency list with all possible chars
// 2. Create lexicographical rules and append letters that come after current letter (adj[])
//    - check for constraint prefix => return ""
// 3. Once Adj[] is created, run dfs()
//    - goal: look for cycles 
//      o ex: visiting an already visited character
//    - After DFS() => return string in reverse order

class Solution {
public:
    unordered_map<char, unordered_set<char>> adj;
    unordered_map<char,bool> visited;

    // output is letters in order
    string result;

    string foreignDictionary(vector<string>& words) {
        // adj[]
        for (string word : words) {
            for (char c : word) {
                adj[c];
            }
        }

        // now create rules
        // iterate over all words
        for (int i = 0; i < words.size() - 1; i++) {
            // get current and next word
            string A = words[i];
            string B = words[i+1];

            // check prefix
            int preSize = min(A.size(), B.size());

            // check constraint for prefix
            if (A.substr(0,preSize) == B.substr(0,preSize) &&
                A.size() > B.size()) {
                return "";
            }

            // can now check for first different char
            for (int j = 0; j < preSize; j++) {
                if (A[j] != B[j]) {
                    // Adj
                    // for char A[j], add B[j] to set
                    adj[A[j]].insert(B[j]);

                    break;
                }
            }
        }

        // can now run dfs on adj to look for cycles

        // check every char in adj key and run dfs on char
        for (auto pair : adj) {
            if (dfs(pair.first) == true) {
                return "";
            }
        }

        reverse(result.begin(), result.end());

        return result;
    }

    // create dfs()
    // parameter: char
    // return bool
    bool dfs(char c) {
        // base case:
        // check visited
        if (visited.find(c) != visited.end()) {
            // found char
            return visited[c];
        }

        // if here, then we can traverse Adj

        // set visited to true for char
        visited[c] = true;

        // can now traverse
        // - traverse through every letter that comes after current c (within set of Adj)
        for (char letter : adj[c]) {
            if (dfs(letter) == true) {
                return true;
            }
        }

        // update result string
        result += c;

        // remove from callstack
        visited[c] = false;

        return visited[c];
    }
};
