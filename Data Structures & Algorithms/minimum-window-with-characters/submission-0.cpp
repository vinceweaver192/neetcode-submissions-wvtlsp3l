class Solution {
public:
    string minWindow(string s, string t) {
        // handle edge case first if 't' is empty
        if (t.empty()) {
            return "";
        }

        // create two hash maps to keep track of:
        // 1. the character count of unique characters
        // 2. the current window of characters and their counts
        unordered_map<char,int> countT, window;

        // map all values in string 't' and their counts
        for (char c : t){
            countT[c]++;
        }

        // create two counters to keep track of:
        // 1. how much of 't's characters we "have"
        // 2. how much of 't's characters we still "need"
        int have = 0;
        int need = countT.size();

        // use a pair to store the resulting size of the window
        // the pair is to compactly store the start and end size of the
        // current window.
        // 
        // A result variable will be used to keep track of the 
        // record smallest length substring
        pair<int,int> res = {-1,-1};

        // keep track of actual result
        int resLen = INT_MAX; // set to INT_MAX to later check if its been met

        // initialize left pointer
        int l = 0;

        // begin iterating and keep track using right pointer
        for (int r = 0; r < s.size(); r++) {
            // get the current char size
            char c = s[r];

            // update window
            window[c]++;

            // check if 
            // 1. current c char is one of the necessary letters in 't'
            // 2. the counts for duplicates match with current window and countT
            if (countT.count(c) && window[c] == countT[c]) {
                // increment have var
                have++;
            }

            // while all conditions are met (have == need), then
            // continuously remove chars until condition is broken
            // to try to find a smaller substring
            while (have == need) {
                // check if the current window is smaller and still
                // meets all the same conditions, and if so, update resLen
                if ((r - l + 1) < resLen) { // Ex. s = 'ABC', l = 2, r = 4, r-l == 4-2 -> 2 (BC), the +1 adds the current letter A
                    resLen = r - l + 1; // update the difference
                    res = {l, r}; // update the result range
                }

                // shrink window from the left to remove excess chars and find the smallest char
                // the char from 's' will be the chars in order
                window[s[l]]--;

                // now check if the removed char left changes the condition of 'have' 
                // and 'need' and if it does, update the 'have'.
                // 1. check if the removed char is in countT 
                // 2. AND the count in window falls below what is needed in countT
                // result : decrement 'have'
                if (countT.count(s[l]) && window[s[l]] < countT[s[l]]) {
                    have--;
                }
                // after every iteration, increment left 'l'
                l++;
            }

        }
        // conditional return
        return resLen == INT_MAX ? "" : s.substr(res.first, resLen);
    }
};
