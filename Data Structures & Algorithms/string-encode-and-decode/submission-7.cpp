class Solution {
public:

    string encode(vector<string>& strs) {
        // encode the list into a single string
        // - for each string, do this in order:
        //   o append the size, followed by the delimeter '#', followed by the original string
        int size = 0;
        string res = "";

        for (const string& s : strs) {
            size = s.size();
            res += to_string(size) + "#" + s;
        }
        
        return res;
    }

    vector<string> decode(string s) {
        // decode the encoded string
        // - read in number until delim is reached "#"
        // - then store number as new size and read in the next string char by char
        //   o once finished, append entire string into result vector
        vector<string> result;

        string num = "";

        int i = 0;

        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            // convert num to int
            int n = stoi(s.substr(i, j - i));

            // skip the #
            i = j + 1;

            // set j to the start of the next number
            j = i + n;

            // get substr of string based on num n
            result.push_back(s.substr(i, n));

            // reset i to be the start of the next number currently stored at j
            i = j;
        }

        return result;
    }
};
