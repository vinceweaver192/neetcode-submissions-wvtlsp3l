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

        // loop from right to end of string2
        while (right < s2.length()) {
            // Add current character to the string2 map
            s2Count[s2[right]]++;

            // If window size exceeds s1 length, shrink it from the left
            if (right - left + 1 > s1.length()) { // + 1 is to be inclusive for current character
                // ensure the window size maintains AT MOST s1 length amount of characters to ensure a match is made
                // 1. if true, then decrement from the left the count of the left value
                s2Count[s2[left]]--;

                // 2. if the left value reachs a count of 0, then remove it from the s2map
                // - we want to make s2 map equal s1 map
                if (s2Count[s2[left]] == 0) {
                    // erase the 0 values
                    s2Count.erase(s2[left]);  // Remove from map if count is zero
                }
                left++;
            }

            // at any point if the 2 maps become equal, return true
            if (s1Count == s2Count) {
                return true;
            }
            // increment right ptr
            right++;
        }
        // if list completed and no match was found, return false
        return false;
    }
};

