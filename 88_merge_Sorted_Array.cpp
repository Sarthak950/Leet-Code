#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //merge to non  decreasing arrays into nums1;
        int i = m-1;
        int j = n-1;
        int k = m+n-1;

        for(auto a: nums2)
            nums1.push_back(a);

        sort(nums1.begin(),nums1.end());

        //remove all the leading zeros
        while(nums1[0] == 0){
            nums1.erase(nums1.begin());
        }
    }

        //this one dump code with gcc but leetcode accepts this
        void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int k = m+n-1;
        while(i>=0 && j>=0){
            if(nums1[i] > nums2[j]){
                nums1[k] = nums1[i];
                i--; k--;
            }
            else{
                nums1[k] = nums2[j];
                j--; k--;
            }
        }
        while(j>=0){
            nums1[k] = nums2[j];
            j--; k--;
        }
    }
};

int main (int argc, char *argv[]) {
    vector<int> nums1 = {1,3,5,7,9,11, 0,0,0};
    vector<int> nums2 = {0,2,4,6,8,10,12};

    Solution sol;


    sol.merge2(nums1, nums1.size(), nums2, nums2.size());

    for( int i=0; i<nums1.size(); i++){
        cout<<nums1[i]<<" ";
    }

    return 0;
}
