class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // sliding window

        int maxLen = 0;

        int l = 0;
        //int r = 0; //s.size() - 1;

        unordered_map<char, int> map;

        for (int r = 0; r < s.size(); r++) {
            // check if current char exist in set
            char c = s[r];

            // loop while 
            // 2. while current char is in map
            while (map.count(c)) { //!= map.end()) {
                // erase from set first
                map.erase(s[l]);
                // increment left as we delete
                l++;
            }

            map[c] = r;

            // get the diff of left and right
            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};
