class Solution {
public:
    // bool checkInclusion(string s1, string s2) {
    //     if (s1.size() > s2.size()) {
    //         return false;
    //     }

    //     // create 2 hashmaps for storing the letters and counts
    //     unordered_map<char, int> s1map, s2map;

    //     // populate the maps with values from their respective strings
    //     for (int i = 0; i < s1.size(); i++) {
    //         // count up to values with the smallest string (s1)
    //         s1map[s1[i]]++;
    //         s2map[s2[i]]++;
    //     }

    //     // keep track of number of matches
    //     int matches = 0;
    //     for (auto& pair : s1map) {
    //         if (s2map[pair.first] == pair.second) {
    //             matches++;  // Count characters that match in frequency
    //         }
    //     }

    //     // keep track of left pointer
    //     int l = 0;

    //     // iterate through all of s2
    //     for (int r = s1.size(); r < s2.size(); r++) {
    //         // base case: check for a full match
    //         if (matches == s1map.size()) {
    //             return true;
    //         }

    //         // Add new char to the current populated s2 window
    //         char newChar = s2[r];
    //         s2map[newChar]++;

    //         // update matches based on new character added
    //         if (s1map[newChar] == s2map[newChar]) {
    //             // if counts match exactly the update matches
    //             matches++;
    //         }
    //         else if (s1map[newChar] + 1 == s2map[newChar]) {
    //             // count has exceeded and we need to decrement
    //             matches--;
    //         }

    //         // remove the old character from the window
    //         char oldChar = s2[l];
    //         s2map[oldChar]--;

    //         // update matches based on the removed character
    //         if (s1map[oldChar] == s2map[oldChar]) {
    //             matches++;
    //         }
    //         else if (s1map[oldChar] -1 == s2map[oldChar]) {
    //             matches--;
    //         }

    //         // increment the left window pointer
    //         l++;
    //     }
    //     // check if matches == s1map.size()
    //     return matches == s1map.size();
    // }
    bool checkInclusion(string s1, string s2) {
    if (s1.length() > s2.length()) return false;

    unordered_map<char, int> s1Count, s2Count;

    // Populate the frequency map for s1
    for (char c : s1) {
        s1Count[c]++;
    }

    int left = 0, right = 0;
    while (right < s2.length()) {
        s2Count[s2[right]]++;  // Add current character to the window

        // If window size exceeds s1 length, shrink it from the left
        if (right - left + 1 > s1.length()) {
            s2Count[s2[left]]--;
            if (s2Count[s2[left]] == 0) {
                s2Count.erase(s2[left]);  // Remove from map if count is zero
            }
            left++;
        }

        // Check if current window matches frequency of s1
        if (s1Count == s2Count) return true;

        right++;
    }

    return false;
}
};

