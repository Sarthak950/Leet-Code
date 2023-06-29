#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;



//elemet that come more than n/2 times
class Solution {
public:
    int majorityElement(vector<int>& nums) {
       
        unordered_map<int, int> map;

        for(auto i: nums){
            map[i]++;
        }

        for(auto i: map){
            if(i.second > nums.size()/2){
                return i.first;
            }
            
        }

        return 0;

        
    }
};
