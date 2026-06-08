/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
private:
    //unordered_map<int,int> cache; // 
    vector<int> cache;
    MountainArray* mt;

    int checkCache(int idx) {
        if (cache[idx] == -1) {
            // miss so add to cache
            cache[idx] = mt->get(idx); 
        }
        return cache[idx];
    }

    int findPeak(MountainArray& mt, int l, int r) {
        while (l <= r) {
            const int mid = (r - l) / 2 + l;

            if (checkCache(mid) > checkCache(mid-1) && checkCache(mid) > checkCache(mid+1)) {
                return mid;
            }
            else if (checkCache(mid-1) < checkCache(mid)) {
                // go right
                l = mid + 1;
            }
            else {
                // go left
                r = mid - 1;
            }
        }
        return l;
    }

public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        // find peak
        // find min (check left side first then right side)
        int n = mountainArr.length();

        int l = 0;
        int r = n-1;

        cache.resize(n, -1);
        mt = &mountainArr;

        int peak = findPeak(mountainArr, l, r); // idx

        // check left of mountain
        r = peak;
        while (l <= r) {
            const int mid = (r - l) / 2 + l;

            if (checkCache(mid) == target) {
                return mid;
            }
            else if (checkCache(mid) > target) {
                // go left
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        // check right of mountain
        l = peak;
        r = n-1;
        while (l <= r) {
            const int mid = (r - l) / 2 + l;

            if (checkCache(mid) == target) {
                return mid;
            }
            else if (checkCache(mid) < target) {
                // go left
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return -1;
    }
};