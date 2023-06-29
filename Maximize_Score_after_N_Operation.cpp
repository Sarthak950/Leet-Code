#include <bits/stdc++.h>

using namespace std;

// int maxScore(vector<int>& nums) {
//         
//         int length = nums.size() * 0.5;
//         int ans = 0;
//         int mask[nums.size()] = {0};
//
//         for(auto i: mask){
//              // i= 0;
//         }
//         
//
//         for( int i=0;i<=length;i++){
//         
//             int maxG  = 0;
//             int flag = 0;
//         
//             for(int j=i+1 ; j <=length+1;j++){
//                 if( ! mask[j] ){
//                     int nG = __gcd(nums[i], nums[j]);
//                     if (maxG < nG){
//                         maxG = nG;
//                         flag = j;
//                     }     
//                 }
//             }
//             mask[flag] = 1;
//
//             ans =  ans + ((i+1) * maxG);
//
//         }
//
//         return ans;
//
// }


int maxScore(vector<int>& nums) {
        
        int length = nums.size() / 2;
        int ans = 0;
        int mask[length *2];
        int c = 0;
        for(auto i: mask){
   		    c++;
        }
        for( int i=0;i<c;i++){
            mask[i]=0;
        }
        

        for( int i=0;i<=length;i++){
        
            int maxG  = 0;
            int flag = 0;
        
            for(int j=i+1 ; j <=length;j++){
                if( ! mask[j] ){
                    int nG = __gcd(nums[i], nums[j]);
                    if (maxG < nG){
                        maxG = nG;
                        flag = j;
                    }     
                }
            }
            mask[flag] = 1;

            ans =  ans + ((i+1) * maxG);

        }

        return ans;

}

int main(){

    vector<int> nums;
    nums.push_back(1);
     nums.push_back(2);
      nums.push_back(3);
       nums.push_back(4);
        nums.push_back(5);
         nums.push_back(6);
    cout<<maxScore(nums);
    return 0;
}
