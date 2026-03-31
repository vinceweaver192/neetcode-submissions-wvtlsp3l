class Solution {
public:
    void reverseString(vector<char>& s) {
        // even or odd
        int size = s.size();

        //if (size % 2) {
        // odd, numbers meet in middle
        for (int i = 0; i < size; i++) {
            if (i >= size/2) {
                break;
            }
            else {
                // swap
                swap(s[i], s[size - i - 1]);
            }
        }
        // }
        // else {
        //     // even, swap 
        // }
    }
};