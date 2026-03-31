class Solution {
public:
// General Solution Notes:
// 1. Adjacency list (mapping each 3 letter city to a SORTED list of cities)
//    * WILL have to prioritize lexicographical ordering of cities
// 2. Run recursive DFS on the adjacency list and erase items that have already been visited
//    * WILL have to do backtracking to check for paths that have valid return paths

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // create adjacency list to enable DFS
        // - map all the source cities to all possible destinations
        unordered_map<string,vector<string>> adj;

        // initialize adj list with all possible sources
        for (auto pair : tickets) {
            adj[pair[0]];
        }

        // sort the tickets lexicographically
        sort(tickets.begin(), tickets.end());

        // now populate the adj list with destination values
        for (auto& pair : tickets) {
            adj[pair[0]].push_back(pair[1]);
        }

        // initialize the result string and append the first "JFK"
        vector<string> result = {"JFK"};

        // now perform DFS on adj list
        // Parameters:
        // 1. result[0] because it is the root of the adj list "JFK", and the next city will be recursively called
        // 2. result because it will be used for backtracking with needing to remove/add post-traversal to try every option
        // 3. adj list because all destinations that have been visited will need to be removed
        // 4. tickets.size() + 1 because that size is our base case for knowing when our result return vector is complete 
        //    * the + 1 is necessary since every travel route in tickets will be listed in the result and the + 1 includes the 
        //      initial "JFK" starting point
        dfs(result[0], result, adj, tickets.size() + 1);

        // return the itinerary
        return result;
    }

private:
    // create private DFS()
    // make helper function of type Boolean:
    // Reasoning for Boolean:
    // 1. use traversal return result to determine if backtracking is necessary or not
    bool dfs(string src, vector<string>& result, unordered_map<string,vector<string>>& adj, int n) {
        // base case
        // if the size of the itinerary result matches the target length 'n', then return true
        if (result.size() == n) {
            return true;
        }

        // base case for backtracking
        // - check if there are any outgoing flights for the current src
        // - Syntax: use adj.find(src) == end()
        if (adj.find(src) == adj.end()) {
            // no outgoing flight, return false
            return false;
        }

        // at this point, there are destination flights at this current src
        // 1. make a temp copy of all the destinations from adj[]
        // 2. iterate over all destinations 
        // 3. destinations that have been visited can be removed from adj
        // 4. call DFS recursive with new destination as the next src and if path returns true, then path is valid and return true
        // 5. post traversal, if after DFS call there is no return true, then proceed with backtracking
        //    - re-insert temp destination back into adj[] (complicated code but pay attention to syntax)
        //    - remove the last value added to the back of the result[] vector
        vector<string> temp = adj[src];

        for (int i = 0; i < temp.size(); i++) {
            // get the first destination
            string dest = temp[i];

            // remove the current destination from the vector inside the adj[]
            // * Be sure not to erase the entire value (destination list)
            // Reasoning:
            // 1. use the map.erase() to remove a very specific value within the adj list
            // 2. use map[key] to pull the entire vector
            // 3. use the vector.begin() + i 
            //    - vector.begin() returns an iterator but + i gets the exact value
            // - Syntax: adj[key].erase(adj[key].begin() + i)
            adj[src].erase(adj[src].begin() + i);

            // add dest to the result vector
            result.push_back(dest);

            // recursively call dfs and if true, then echo the return statement true
            if (dfs(dest, result, adj, n)) {
                return true;
            }

            // if here, then start backtracking process

            // re-insert dest back into adj
            // Syntax: for map syntax, can use map.erase() and map.insert()
            // - map[key].insert(vector.begin() + i, value_to_insert)
            adj[src].insert(adj[src].begin() + i, dest);

            // now remove the recently added src from result[]
            result.pop_back();
        }

        // at this point, if path was not found, then return false
        return false;
    }
};
