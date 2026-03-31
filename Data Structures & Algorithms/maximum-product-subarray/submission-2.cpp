class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // use dpMinProduct and dpMaxProduct to store min and max's along nums[]
        int dpMinProduct = 1;
        int dpMaxProduct = 1;

        // we need min to account for negative numbers
        // Ex. one negative turns the entire product neg
        //     but two negatives turn it back into a positive
        //     the minProduct can easily turn into the max product

        int res = nums[0]; // nums will always have atleast 1 val

        // iterate over all nums and skips 0s
        for (int num : nums) {
            // calc max and min
            int temp = dpMinProduct;
            dpMinProduct = min(min(num * dpMinProduct, num * dpMaxProduct), num);
            // replace new dpMin with old dpMin
            dpMaxProduct = max(max(num * temp, num * dpMaxProduct), num);

            res = max(dpMaxProduct, res);
        }

        return res;
    }
};
