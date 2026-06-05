class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string dir = "";

        path.push_back('/'); // ensure last string gets pushed to stack

        for (char &c : path) {
            if (c != '/') {
                dir.push_back(c);
            }
            else {
                // process dir
                if (dir == "..") {
                    if (!st.empty()) {
                        st.pop_back();
                    }
                }
                else if (!dir.empty() && dir != ".") {
                    st.push_back(dir);
                }
                // reset dir
                dir = "";
            }
        }

        // return result in a string
        string res = "";

        for (string& d : st) {
            res += '/' + d;
        }

        if (res.empty()) {
            return "/";
        }
        return res;
    }
};