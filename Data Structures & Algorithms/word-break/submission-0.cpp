class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // TODO:
        // - use vector for bottom-up dp
        // - iterate backwards to ensure entire word and avoid overlaps
        //   o make the dp[size+1] = true (dp[size+1] = 0 len, which means 
        //     it will already be complete)
        vector<bool> dp(s.size() + 1, false); // init all to false

        // update start point to true since 0 = true already
        // start point => size of s, so 0 == s.size()
        dp[s.size()] = true;

        // iterate backwards from s
        for (int i = s.size(); i >= 0; i--) {
            // iterate over every word
            for (const string& word : wordDict) {
                // compare word
                // 1. check if word + i <= s.size()
                // 2. check if word matches substr
                if (word == s.substr(i, word.size()) && word.size() + i <= s.size()) {
                    // will get the first word
                    dp[i] = dp[i + word.size()]; // words that aren't complete will not equal true
                    // Complete Words:
                    // - are words that reach 0 ONLY! 
                }

                // check early find
                if (dp[0] == true) {
                    return dp[0];
                }
            }
        }

        return dp[0];
    }
};
