class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // first, check if the endword is in wordList, if not then return 0
        // also check if wordList is empty
        // 
        // Syntax: for vectors, use find(begin(), end(), value) == end() { // if true then not found (end == end) }
        if (wordList.empty() || find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return 0;
        }

        // create adjacency list to store the mapping of a wild card word to all of its potential words
        unordered_map<string, vector<string>> adj; // key (wildcard h*t, *it, hi*) : val (hot, hat, pit, pat, him, his)

        // add beginWord to wordList to ensure it is part of the graph
        wordList.push_back(beginWord);

        // build the adjacency list of wild cards
        for (const string& word : wordList) { // const reference is for efficiency only, not necessary
            for (int c = 0; c < word.size(); c++) {// iterate through each letter 'c'
                // syntax for changing a letter/character in a string
                // - string.substr(startIndex, endIndex) + "*" + string.substr(startIndex) 
                //   - if two parameters are given, get the substring from beginning to end (end is inclusive)
                //   - if one parameter is given, get the substring at that point and beyond
                string wildcard = word.substr(0, c) + "*" + word.substr(c+1); // plus 1 is to get values after current inserted '*'

                // 1. map wildcard to adjacency list
                // 2. push_back the word into the value at that wildcard key
                adj[wildcard].push_back(word);
            }
        }

        // can now begin BFS (breadth first search (iterative))

        // create set for tracking visited word nodes
        // initialize set with beginWord
        unordered_set<string> visited{beginWord};

        // must initialize a queue for BFS and push starting word
        queue<string> q;
        q.push(beginWord);

        // initialize the result transformation val to 1 counting the beginWord
        int result = 1;

        // perform iterative BFS
        while (!q.empty()) {
            // get q size
            int size = q.size();

            // for every word in the current queue...
            for (int i = 0; i < size; i++) {
                // get the current word in queue
                string word = q.front();

                // remove top
                q.pop();

                // check if word is the end word
                if (word == endWord) {
                    return result;
                }

                // if not, then create the wildcard of the current word
                for (int c = 0; c < word.size(); c++) {
                    string wildcard = word.substr(0, c) + "*" + word.substr(c + 1); // c + 1 is necessary to skip the current char we just replaced

                    // now check all word in the adjacency list[] that are mapped to this wildcard
                    for (const string & w : adj[wildcard]) {
                        // check if the word 'w' has NOT been visited
                        if (visited.find(w) == visited.end()) { // syntax for finding in a set => set.find() == or != set.end()
                            // if true for ==, then set reached the end and word didnt exist
                            // Add word to visited
                            visited.insert(w);
                            // Add word to the queue
                            q.push(w);
                        }
                        // if word has been visited, do nothing
                    }
                }
            }
            // outside of all the for loops but still within the while-loop...
            // increment result
            // Reasoning:
            // - BFS traverses many subsequent nodes in the queue at one time but they are all lateral
            // - only after all lateral nodes have been popped and new level nodes have been pushed will 
            //   the result layer be incremented
            result++;
        }

        // if all searches have executed and nothing, then return 0 for not found
        return 0;
    }
};
