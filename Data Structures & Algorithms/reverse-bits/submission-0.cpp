class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // *** General Rules ***
        //
        // - 'n' is a 32bit unsigned integer (ex. 21 (base 10))
        // - as an usigned int 32, it can be easily represented in binary
        //   and allow for easy bit manipulation and bit shift operations.
        // - Solution 'return' statement will be another uint32_t value
        //   meaning it will be an integer value

        uint32_t result = 0;

        // loop 32 times for each binary bit value in 'n'
        for (int i = 0; i < 32; i++) {
            // Since leading 0s dont matter in bitwise comparisons, we are
            // going to do a right shift on 'n' by incrementing index i
            //
            // Ex. Iteration 1: 10101 >> 0 = 10101 == 21
            //     Iteration 2: 10101 >> 1 = 1010 == 10
            uint32_t shifted_bits = n >> i;

            // Bitwise Arithmetic Operation: (&)
            //
            // - Using a bit-manipulatable variable type like uint32_t, we 
            //   can perform bitwise operations.
            // - The goal here is to take advantage of the right bit shifts to
            //   keep track of all the right most bit (one bit at a time, 32 times)
            // - Compare a binary 1 with the shifted bits
            // 
            uint32_t bit = 0b0001 & shifted_bits;
            //cout << "shifted bits: " << shifted_bits << ' ' << endl;
            result = result + (bit << (31 - i));
            //cout << "bits: " << bit << ' ' << endl;
        }
        /*
        cout << ' ' << endl;
        std::cout << std::hex << std::showbase
              << "Value: " << n << "\n";
        */
        //cout << ' ' << endl;
        //cout << result << endl;
        return result;
    }
};
