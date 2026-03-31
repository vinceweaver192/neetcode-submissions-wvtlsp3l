// Solution Explanation:
//
// dfs:
// - the purpose of dfs here and the order of traversal are very important
// - 1st traversal:
//   o this is meant to do a single recursive iteration (one num at a time) until the end is reached
//     - this allows each number to get handled individually first and enables the second traversal
// - 2nd traversal:
//   o at this point, we start at the last number in string
//   o we want to check the last two numbers, so we make sure the include the (i + 1 < n) in our
//     if statement to ensure we have atleast 2 values and if so, we update our result starting with
//     the original 1 value in map at index n
//
// dp:
// - the purpose of using an unordered map is to map the index of the string to the num of unique 
//   combinations
// - since we are doing dfs, we reach the last value before doing any calculation, so we set the 
//   limit of the map (size n) index equal to 1, meaning 1 full unique combination
//

class Solution {
public:
    unordered_map<int, int> dp;

    int numDecodings(string s) {
        int n = s.size();

        dp[n] = 1; // starting with back

        return dfs(s, 0);
    }

    int dfs(string s, int i) {
        // base case (dont ever process 0's)
        cout << "i = " << i << " for ";
        if (s[i] == '0') {
            cout << "Leading 0, base case hit" << endl;
            return 0;
        }

        // memo
        if (dp.count(i)) {
            cout << "already calculated dp[" << i << "] = " << dp[i] << endl;
            return dp[i];
        }

        // traverse all single nums
        int res = 0;
        cout << "one num traversal, " << s[i] << endl;
        res = dfs(s, i+1);
        cout << "post one num traversal, res = " << res << endl;

        // traverse all double nums < 27
        if (i + 1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i+1] < '7')) {
            cout << "two num traversal for " << s[i] << s[i+1] << endl;
            res += dfs(s, i+2);
            cout << "post two num traversal, res = " << res << endl;
        }
        
        dp[i] = res;
        return dp[i];
    }
};
