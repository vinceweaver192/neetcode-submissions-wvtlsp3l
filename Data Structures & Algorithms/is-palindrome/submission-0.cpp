class Solution {
public:
    bool isPalindrome(string s) {
        // creating a string variable makes the space complexity => O(n)
        string str = "";

        // use built-in alphnum
        for (int i = 0; i < s.length(); i++){
            if (isalnum(s[i])){
                str += tolower(s[i]);
            }
        }
        //cout << str.length() << endl;
        /*
        for (int j = 0; j < str.length(); j++){
            cout << str[j] << endl;
        }
        */

        // use the string() operand to create an instance of the created string var "str"
        // and use the reverse iterators to reverse the string
        // 
        // if str is equal to the reverse str, then the output is true
        return (str == string(str.rbegin(), str.rend()));
        
    }
};
