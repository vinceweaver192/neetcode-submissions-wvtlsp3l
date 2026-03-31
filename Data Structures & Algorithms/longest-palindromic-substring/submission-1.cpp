class Solution {
public:
    string longestPalindrome(string s) {
        // traverse a for loop across the string and expand outward from left and right

        int n = s.size();

        // res vars
        int reslen = 0;
        int residx = 0;

        // odd (start at same num)
        for (int i = 0; i < n; i++) {
            // always reset vars
            int l = i;
            int r = i;
            
            // check in bounds
            while (l >= 0 && r < n) {
                // perform check
                if (s[l] == s[r]) {
                    if (r - l + 1 > reslen) {
                        reslen = r - l + 1;
                        residx = l;
                    }

                    l--;
                    r++;
                }
                else {
                    break;
                }
            }
        }

        // even (start at different)
        for (int i = 0; i < n; i++) {
            int l = i;
            int r = i+1; // offset by one

            // check bounds
            while (l >= 0 && r < n) {
                // perform check
                if (s[l] == s[r]) {
                    if (r - l + 1 > reslen) {
                        reslen = r - l + 1;
                        residx = l;
                    }

                    l--;
                    r++;
                }
                else {
                    break;
                }
            }
        }
        // use string.substr(start, # chars after)
        return s.substr(residx, reslen);
    }
};
