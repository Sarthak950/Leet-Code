#include <bits\stdc++.h>

// Sort the array

int threeSumClosest(vector<int>& nums, int target) {
    // Sort the array
    sort(nums.begin(), nums.end());
    int closest = nums[0]+nums[1]+nums[2];
    // Iterate through the array
    for(int first = 0 ; first < nums.size()-2 ; ++first) {
        // Check for duplicates
        if(first > 0 && nums[first] == nums[first-1]) continue;
        // Initialize pointers to the first and last elements
        int second = first+1;
        int third = nums.size()-1;            
        while(second < third) {
            // Calculate the sum
            int curSum = nums[first]+nums[second]+nums[third];
            // If the sum is equal to the target, return it
            if(curSum == target) return curSum;
            // Update closest if necessary
            if(abs(target-curSum)<abs(target-closest)) {
                closest = curSum;
            }
            // Update pointers
            if(curSum > target) {
                --third;
                // Skip duplicates
                while(second < third && nums[third] == nums[third+1]) --third;
            } else {
                ++second;
                // Skip duplicates
                while(second < third && nums[second] == nums[second-1]) ++second;
            }
        }
    }
    return closest;
}