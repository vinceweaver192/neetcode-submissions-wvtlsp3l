class Solution {
public:
    int trap(vector<int>& height) {
        // Naive solution:
        // height=[0,2,0,3,1,0,1,3,2,1]
        //             ^
        //                             ^
        // min(max left, max right) - height[i]
        // Ex. height[i] = 2, min(0, 3) => 0 - 2 => -2 or 0
        // Ex. height[3] = 0, min(2, 3) => 2
        // 
        // Add results
        // * Round negatives to 0
        //
        if (height.empty()){
            return 0;
        }

        int result = 0;


        for (int i = 0; i < height.size(); i++){ // O(n)
            int l = -1; // peak height left
            int r = -1;
            cout << "curr i index: " << i << endl;
            cout << "curr height: " << height[i] << endl;
            for (int j = 0; j < height.size(); j++){ // O(n)
                if (j < i){
                    // left side
                    //int left = height[j];
                    l = max(l, height[j]);
                }
                else if (j > i){
                    // right side
                    r = max(r, height[j]);
                }
            }
            cout << "left max: " << l << ", right max: " << r << endl;
            int rain = min(l, r) - height[i];

            if (rain < 0){
                rain = 0;
            }
            cout << "curr rain: " << rain << endl;

            result += rain;
            cout << "current total: " << result << endl;
            cout << endl;
        }

        return result;
    }
};
