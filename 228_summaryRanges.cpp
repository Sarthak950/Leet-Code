#include <iostream>
#include<vector>
#include <string>

#include <bits/stdc++.h>


using namespace std ;


class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        vector<string> ans;
        if(nums.empty()) return ans;
        
        int n = nums.size();
        int i = 0;
        
        while(i < n){
            int start = i;
            while(i+1 < n && nums[i+1] == nums[i]+1) i++;
            if(i == start) ans.push_back(to_string(nums[i]));
            else ans.push_back(to_string(nums[start]) + "->" + to_string(nums[i]));
            i++;
        }
        return ans;


    }
};


int main(){

    vector<int> nums = {0,1,2,4,5,7,8,10,11,12,13,14,15,16,17};
    Solution s;
    vector<string> ans = s.summaryRanges(nums);

    for(int i=0; i<ans.size(); i++) cout << ans[i] << " "<<endl;


    return 0;
}
