class Solution {
public:
    int mySqrt(int x) {

        // if x is 0, return 0
        if (x == 0)
            return x;

        // first is 1, last is x
        int first = 1, last = x;

        // while first is still less than or equal to last
        while (first <= last) {

            // mid is the average between first and last
            int mid = first + (last - first) / 2;

            // if mid * mid == x, return mid
            if (mid  == x / mid){
                return mid;

            // if mid is greater than x / mid, set last to mid - 1
            }else if (mid > x / mid) {
                last = mid - 1;

            // otherwise, set first to mid + 1 
            }else {
                first = mid + 1;

            }
        }

        // once first is no longer less than or equal to last, return last
        return last;

    }
};
