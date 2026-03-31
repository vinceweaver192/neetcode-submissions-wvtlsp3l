// Sliding Window Solution:
// 1. iterate over every unique letter in string 's'
// 2. keep track of the maximum window length that each letter can create while maintaining the 'k' constraint

class Solution {
public:
    int characterReplacement(string s, int k) {
        
        // 1. create a set to store each unique letter in the string the occurences
        //    - initialize map with all chars in 's'
        unordered_set<char> set(s.begin(), s.end());

        // keep track of longest string
        int result = 0;

        // iterate over every letter in set
        // *** Can iterate over set similar to vectors ***
        for (char c : set) {
            // keep track of left pointer for each letter
            int l = 0;

            // keep track of this letters count
            int count = 0;

            // keep track of this letters window size
            int winSize = 0;

            // now iterate over string and find matches
            for (int i = 0; i < s.size(); i++) {
                // check if chars match
                if (s[i] == c){
                    count++;
                }
                // any case, update window size
                winSize++;

                // check if sizes of k constraint is met or not met
                // - will need to 
                //   1. iterate and remove from left side
                //   2. calculate (current window size - count duplicates) > k { must remove chars from left }
                //   3. update current window size and count if count is removed
                while ((winSize - count) > k) {
                    // 1.
                    if (s[l] == c) {
                        count--;
                    }
                    l++; 
                    winSize--;
                }
                // can now check for updated result
                result = max(result, winSize);
            }
        }
        return result;
    }
};
