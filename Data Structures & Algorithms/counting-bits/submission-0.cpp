class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result;

        for (int i = 0; i <= n; i++) {
            result.push_back(counter(i));
        }

        return result;
    }

    int counter(int n) {
        int count = 0;

        for (int i = 0; i < 32; i++) {
            if ((n >> i) & 1 == 1) {
                count++;
            }
        }
        return count;
    }
};
