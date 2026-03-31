class Solution {
public:
    int countSubstrings(string s) {
        // dfs and memo

        int n = s.size();

        int res = 0;

        // one for loops
        for (int i = 0; i < n; i++) {
            // start with odds

            int l = i;
            int r = i;

            while (l >= 0 && r < n) {
                if (s[l] == s[r]) {
                    res++;
                }
                else {
                    break;
                }
                l--;
                r++;
            }

            // now evens
            // - keep the res count, evens are unique and haven't been accounted for yet

            // reset l and r
            l = i;
            r = i + 1;

            while (l >= 0 && r < n) {
                if (s[r] == s[l]) {
                    res++;
                }
                else {
                    break;
                }
                l--;
                r++;
            }
        }
        return res;
    }
};
