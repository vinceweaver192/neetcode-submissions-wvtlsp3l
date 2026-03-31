class Solution {
public:
    bool isAnagram(string s, string t) {
        //cout << s.length() << endl;
        //cout << t << endl;

        // check the size for an exact matching first
        if (s.length() != t.length()){
            return false;
        }

        // create 2 unordered_maps to be able to track
        // the exact amount of characters using key:value pairs
        unordered_map<char,int> smap;
        unordered_map<char,int> tmap;

        // at this point, the strings are the same length
        for (int i = 0; i < s.length(); i++){
            // check that code runs properly up to this point
            //cout << s[i] << ' ';

            // append all characters to map
            // smap[key] = value
            smap[s[i]]++;
            tmap[t[i]]++;
        }

        // now check if maps are exactly equal
        return smap == tmap;
    }
};
