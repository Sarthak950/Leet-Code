#include<iostream>
#include<vector>

using namespace std;


class Solution {
private:
    int dp[21][10001];
    
    int helper(vector<int>&rods,int diff,int i){
        
        if(i == rods.size()){
            if(diff == 0) return 0;
            return -1e9;
        }

        if(dp[i][diff + 5000] != -1) return dp[i][diff + 5000];
        
        // Take into left
        int takeIntoLeft = rods[i] + helper(rods,diff + rods[i],i+1);
        
        // Take into right
        int takeIntoRight = helper(rods,diff - rods[i],i+1);
        
        // Not take
        int notTake = helper(rods,diff,i+1);

       return dp[i][diff + 5000] = max(takeIntoLeft,max(takeIntoRight,notTake));
    }
public:

    int tallestBillboard(vector<int>& rods) {
        memset(dp,-1,sizeof(dp));

        return max(helper(rods,0,0),0);
    }
};
