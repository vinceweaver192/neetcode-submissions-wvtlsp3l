class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }

        // create 2 maps
        unordered_map<char, int> s1Count, s2Count;

        // Populate the frequency map for s1
        for (char c : s1) {
            s1Count[c]++;
        }

        // create 2 pointers, left and right both start at 0
        int left = 0, right = 0;

        // keep track of windowSize
        int winSize = 0;
        
        // loop from right to end of string2
        while (right < s2.length()) {
            // Add current character to the string2 map
            s2Count[s2[right]]++;

            // If window size exceeds s1 length, shrink it from the left
            if (right - left + 1 > s1.length()) { // + 1 is to be inclusive for current character
                s2Count[s2[left]]--;

                // check for zero count letters 
                // - we want to make s2 map equal s1 map
                if (s2Count[s2[left]] == 0) {
                    s2Count.erase(s2[left]);  // Remove from map if count is zero
                }
                left++;
                winSize--;
            }

            // at any point if the 2 maps become equal, return true
            if (s1Count == s2Count) {
                return true;
            }
            // increment right ptr
            right++;
            winSize++;
        }
        // if list completed and no match was found, return false
        return false;
    }
};

