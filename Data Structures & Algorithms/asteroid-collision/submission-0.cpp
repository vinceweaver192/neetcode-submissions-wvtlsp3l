class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st; // store results after collisions in a stack

        for (int& a : asteroids) {
            // check for collisions
            while (!st.empty() && st.back() > 0 && a < 0) {
                // track collisions, if collisions are removed set them to 0
                const int diff = st.back() + a;

                if (diff < 0) {
                    st.pop_back();
                }
                else if (diff > 0) {
                    a = 0;
                }
                else {
                    // equal
                    st.pop_back();
                    a = 0;
                }
            }

            if (a != 0) {
                st.push_back(a);
            }
        }
        
        return st;
    }
};