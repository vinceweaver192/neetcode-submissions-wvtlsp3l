class Solution {
public:
    bool isValid(string s) {
        // 1. Need to create a stack to store the symbols in the order
        //    that they are being opened in.
        //
        // 2. Need to store the pair values of the open and close to
        //    be able to identify which mapping goes where
        //      - Can use an unordered map for this
        stack<char> st;

        // make the keys the close symbols to make it easier to search the loop
        unordered_map<char, char> um = {
            {')','('},
            {']','['},
            {'}','{'}
        };

        if (s.empty()){
            return true;
        }

        // must iterate through entire string by characters
        for (char c : s){
            //cout << c << ' ';

            if (um.count(c)){
                // if close is found, compare matching val in map with top of stack
                // whenever we pop stack, always check if stack is empty prior
                if (!st.empty() && um[c] == st.top()){
                    // pop stack because only open is added, no need to add close
                    st.pop();
                }
                else {
                    // add incorrect val to stack or return false
                    return false;
                }
            }
            else {
                // Only add open val to stack
                st.push(c);
            }
        }
        //cout << "stack size: " << st.size() << endl;
        return st.empty();
    }
};
