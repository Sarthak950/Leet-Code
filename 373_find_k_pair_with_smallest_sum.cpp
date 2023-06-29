#include <bits/stdc++.h>
#include <set>
#include <vector>

using namespace std;

// class Solution {
// public:
//     vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
//
//         multiset<vector<int>, less<int>> s;
//         vector<vector<int>> ans;
//
//         int i=0,j=0;
//         for(auto n1: nums1){
//             for(auto n2: nums2){
//                 vector<int> temp;
//                 temp.push_back(n1+n2);
//                 temp.push_back(i);         
//                 temp.push_back(j);
//                 s.insert(temp);
//             }
//         }
//        return ans; 
//     }
// };


class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) { // time complexity is O(m*nlogk), m = nums1 size, n = nums2 size
        priority_queue<pair<int,pair<int,int>>> pq;  // default: the greatest comes top
        for(int i=0;i<nums1.size();i++) {
            for(int j=0;j<nums2.size();j++) {
                int sum=nums1[i]+nums2[j];
                if (pq.size()<k) {
                    pq.push({sum,{nums1[i],nums2[j]}});
                }
                else if (sum<pq.top().first) {
                    pq.pop();
                    pq.push({sum,{nums1[i],nums2[j]}});
                } else {
                    break;  // save time! since we don't need to traverse the rest of vector 2
                }
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()) {
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
