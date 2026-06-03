class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // binary search:
        // - if num found or NOT found, l == r
        // - check if l == num, if yes then start there and continue iterating until diff = k or size n

        const int n = arr.size();

        // r can be equal to or next greater
        int r = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int l = r - 1; 
        // if r is already the beginning of the array, we need to check l before auto taking it

        //while (r - l + 1 < k && r - l + 1 != n) { // much more complex
        while (k > 0) { // this ensures we count the min picks, and if we go out of bounds we dont take
            // increment either l or r
            if (l < 0) {
                r++;
            }
            else if (r > n-1) {
                l--;
            }
            else if (abs(x - arr[l]) <= abs(x - arr[r])) {
                l--;
            }
            else {
                r++;
            }
            k--;
        }

        return vector<int>(arr.begin() + l + 1, arr.begin() + r);
    }
};