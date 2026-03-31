class Solution {
public:

    string encode(vector<string>& strs) {
        // store the results into a string
        string result;

        // iterate over string
        for (string s : strs) {
            // append TWO unique chars:
            // 1. append a numerical size to represent the length of the actual string
            // 2. append a unique char identifier "#" to search to begin decoding
            result += to_string(s.size()) + "#" + s;
            //cout << result << endl;
        }
        return result;
    }

    vector<string> decode(string s) {
        // slow pointer
        int i = 0;

        // create result vector to store the parsed result
        vector<string> results;
        
        // iterate slow pointer to length of string s
        while (i < s.size()) {
            // create fast pointer
            int j = i;

            // iterate until delim char is reached "#"
            while (s[j] != '#') {
                j++;
            }

            // extract the numerical signifier to get the proper length of the string
            // 1. since the actual string is added AFTER the delim, then everything before is the number identifer for length
            int length = stoi(s.substr(i, j - i));

            // TODO:
            // 1. update 'i' to where the string starts, after the delim "#"
            i = j + 1;

            // 2. move j to skip the new string from length + all the prev strings from i
            j = length + i;

            // 3. add string substring to results
            results.push_back(s.substr(i, length));
            //cout << results[-1] << endl;
            // 4. move i to skip the newly added string: length
            i = j;
        }

        // return arr[]
        return results;
    }
};
