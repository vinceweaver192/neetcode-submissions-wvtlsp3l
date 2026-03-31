class Solution {
public:
    string minWindow(string s, string t) {
        // create 2 maps
        // 1. for checking string T (maps chars : int duplicates)
        // 2. for checking current window chars and duplicates:
        //    - will add every value to this map but remove chars once
        //      minimum conditions are met
        unordered_map<char,int> countT, window;

        // 1. keep track of the result length to store difference between
        //    right - left pointer index
        //    - set start size to INT_MIN to compare with at the end
        // 2. used to set the result pair<left, right> index
        int resLen = INT_MAX; // 1.
        pair<int,int> result = {-1,-1}; // 2.

        // iterate through every char in 't' and store in countT:
        for (char c : t) {
            countT[c]++;
        }

        // keep track of what we 'have', and what we 'need':
        // - have == int current size of CORRECT matched characters
        //   o will only 
        // - need == int total number of UNIQUE characters in T 
        //   o MUST check countT size for 'need'
        int have = 0;
        int need = countT.size(); // get size of unique chars

        // keep track of left, right index pointers:
        int l = 0;

        // now iterate through every char in string 's':
        for (int r = 0; r < s.size(); r++) {
            // auto add the first char to window:
            // - will remove excess chars later
            char c = s[r];
            window[c]++;

            // check if:
            // 1. current char 'c' is in countT
            // 2. if current window[c] matches countT[c] duplicates
            // Result: if true, update have++
            if (countT.count(c) && window[c] == countT[c]) {
                have++;
            }

            // loop and remove characters to get smallest substr
            // 1. loop until have < need
            while (have == need) {
                // check current leftmost index character and remove it from
                // the current window
                window[s[l]]--;

                // update the size of the resLen window
                // - since we are updating the left index, must take the difference of
                //   the right index - the updated left index
                resLen = r + 1 - l;
                result = {l, r};

                // check if:
                // 1. the removed char is in countT[s[l]]
                // 2. the current window[s[l]] < countT[s[l]]
                // Result: update have--;
                if (countT.count(s[l]) && window[s[l]] < countT[s[l]]) {
                    have--;
                }

                // update l++;
                l++;
            }
        }

        // return conditional
        return resLen == INT_MAX ? "" : s.substr(result.first, resLen);
    }
};
