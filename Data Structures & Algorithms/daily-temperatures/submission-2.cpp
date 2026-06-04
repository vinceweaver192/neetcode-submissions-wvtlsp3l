class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> st;

        const int n = temperatures.size();
        vector<int> res(n,0);

        for (int i = n-1; i >= 0; i--) {
            while (!st.empty() && temperatures[st.back()] <= temperatures[i]) {
                st.pop_back();
            }

            if (!st.empty()) {
                res[i] = st.back() - i;
            }
            st.push_back(i);
        }

        return res;
    }
};
