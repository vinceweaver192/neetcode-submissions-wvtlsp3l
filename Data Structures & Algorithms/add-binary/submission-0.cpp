class Solution {
public:
    string addBinary(string a, string b) {
        int aCounter = a.size() - 1;
        int bCounter = b.size() - 1;
        int r = 0; // carry or remainder

        deque<char> result;

        while (aCounter >= 0 || bCounter >= 0) {
            int val = r; // start with the carry from previous addition

            if (aCounter >= 0) {
                val += (a[aCounter] - '0'); // convert char to int
                aCounter--;
            }

            if (bCounter >= 0) {
                val += (b[bCounter] - '0'); // convert char to int
                bCounter--;
            }

            // calculate new carry
            r = val / 2;

            // push the result bit to front
            result.push_front((val % 2) + '0');
        }

        // if there's still a carry, add it to the front
        if (r == 1) {
            result.push_front('1');
        }

        // convert deque to string
        return string(result.begin(), result.end());
    }
};
