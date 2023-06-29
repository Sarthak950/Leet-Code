#include <bits/stdc++.h>
#include <functional>
#include <iostream>
#include <ostream>
#include <unordered_set>
#include <vector>

using namespace std;

// class Solution {
//     public:
//         long long totalCost(vector<int>& costs, int k, int candidates) {
//             //declare a unordered_set with greater than property
//             // multiset<int, less<int>> first_k;
//             // multiset<int, less<int>> last_k;
//
//
//             multiset<int> first_k;
//             multiset<int> last_k;
//
//             // cout<< costs.size()<<" "<<candidates<< " "<< costs.size() -candidates<<endl;
//
//             for( int i=0;i<candidates;i++)  first_k.insert(costs[i]);
//
//             for(int i=costs.size() - candidates; i<costs.size();i++) last_k.insert(costs[i]);
//
//             long long sum = 0;
//
//
//             int f = k+1;
//             int l = costs.size() - candidates-1;
//
//             for (auto i : costs) {
//                 cout<<i<< " ";
//             }cout<<endl<<endl;
//
//             for( auto i : first_k) cout<<i<<" "; 
//             cout<<endl;
//             for (auto i  : last_k) cout<<i<<" ";
//             cout<<endl<<endl;
//
//             for(int i= 0;i< k;i++){
//
//                 if( *first_k.begin() <= *last_k.begin()){
//                     sum += *first_k.begin();
//                     first_k.erase(first_k.begin());
//                     first_k.insert(costs[++f]);
//                     cout<< "in first_k added "<< costs[f-1]<<endl;
//                 }else{
//                     sum += *last_k.begin();
//                     last_k.erase(last_k.begin());
//                     last_k.insert(costs[--l]);
//                     cout<< "in last_k added "<<costs[l+1]<<endl;
//                 }
//
//                 for (auto i : first_k) {
//                     cout<< i <<" ";
//                 }cout<<"  ";
//
//                 for (auto i  : last_k){
//                     cout<<i<< " ";
//                 }cout<<endl<<endl;
//
//             }
//
//
//             // for( auto i : first_k) cout<<i<<" ";
//             // cout<<endl<< first_k.size()<<endl;
//             // for (auto i  : last_k) cout<<i<<" ";
//             // cout<<endl<<last_k.size()<<endl;
//             //
//
//
//             return sum;
//         }
// };
//




// class Solution {
// public:
//     long long totalCost(vector<int>& costs, int k, int candidates) {
//         
//         priority_queue<int,vector<int>,greater<int>>pq1,pq2;
//         
//         int i=0,j=costs.size()-1,count=0;
//         
//         long long total=0;
//         
//         while(count<k){
//             
//             while(pq1.size()<candidates && i<=j)pq1.push(costs[i++]);
//             
//             while(pq2.size()<candidates && j>=i)pq2.push(costs[j--]);
//             
//             int a = INT_MAX;
//             int b = INT_MAX;
//
//             if( pq1.size()>0 ) a=pq1.top();
//             if( pq2.size()>0 ) b=pq2.top();
//             
//             if(a<=b){
//                 total+=a;
//                 pq1.pop();
//             }else{
//                 total+=b;
//                 pq2.pop();
//             }
//             count++;
//         }
//        return total;
//     }
// };



class Solution {
#define ll long long
    public:
        long long totalCost(vector<int>& cost, int k, int c) {
            
            ll ans=0LL; 
            int n=cost.size();

            for(auto i: cost) cout<<i<<" ";
            cout<<endl;
            
            priority_queue< pair<int,int>, vector< pair<int,int>>, greater < pair<int,int>> >pq;
            //this is simply a pair of int with greater than property
            
            int i=0,j=n-1;
            
            while(pq.size()<c && i<=j){ pq.push({cost[i++],0}); cout<<"pushed "<< cost[i-1]<< " " <<0<<endl;}
            
            while(pq.size()<2*c && i<=j){ pq.push({cost[j--],1}); cout<<"pushed "<< cost[j+1]<< " " <<1<<endl;}


            
            while(k--){
                // auto it=pq.top(); pq.pop();

                // int top=it.first;
                int flg = pq.top().second;
                
                ans += pq.top().first;
                pq.pop();
                
                if(i<=j){
                    if(flg) pq.push({cost[j--],1});
                    else pq.push({cost[i++],0});
                }
            }

            return ans;
        }
};


class Solution {
    #define ll long long
public:
    long long totalCost(vector<int>& cost, int k, int c) {
        ll ans=0LL; int n=cost.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int i=0,j=n-1;
        while(pq.size()<c && i<=j) pq.push({cost[i++],0});
        while(pq.size()<2*c && i<=j) pq.push({cost[j--],1});
        while(k--){
            auto it=pq.top(); pq.pop();
            int top=it.first,flg=it.second;
            ans+=top;
            if(i<=j){
                if(flg) pq.push({cost[j--],1});
                else pq.push({cost[i++],0});
            }
        }
        return ans;
    }
};


/*


   The given code appears to be a function named totalCost that takes three parameters: a vector cost, an integer k, and an integer c. The function calculates the total cost based on the values in the cost vector using a priority queue.

Here's a breakdown of how the code works:

Initialize the variables ans (initialized to 0) and n (the size of the cost vector).
Create a priority queue named pq using a pair of integers. The priority queue is implemented as a min-heap, meaning the smallest element will be at the top. The pair represents the cost value and a flag indicating whether the cost came from the beginning or the end of the cost vector.
Initialize two pointers, i (pointing to the start of the cost vector) and j (pointing to the end of the cost vector).
Add elements to the priority queue pq until its size reaches c or until both i and j have been processed. Each element pushed into the priority queue is a pair containing the cost value and a flag indicating it came from the beginning (0) or the end (1) of the cost vector.
Continue adding elements to pq until its size reaches 2*c or until both i and j have been processed. This step ensures that the priority queue contains elements from both ends of the cost vector.
Repeat the following k times:
Get the top element from the priority queue (pq.top()), which will be the minimum cost value.
Extract the cost value (it.first) and the flag (it.second) from the pair.
Add the cost value to the ans variable.
If there are remaining elements in the cost vector (i is less than or equal to j):
If the flag flg is 1, push the cost value from the end of the cost vector into the priority queue (pq.push({cost[j--], 1})).
Otherwise, push the cost value from the beginning of the cost vector into the priority queue (pq.push({cost[i++], 0})).
Return the final ans value, which represents the total cost.
Overall, the code calculates the total cost by selecting the minimum k elements from the cost vector, considering c elements from the beginning and c elements from the end. It uses a priority queue to efficiently extract the minimum cost values and maintains the ordering based on the flags to ensure the elements are selected from both ends of the cost vector.

*/


int main(){

    vector<int> costs = {31,25,72,79,74,65,84,91,18,59,27,9,81,33,17,58};
    int k = 11;
    int candidates = 5;

    Solution s;
    cout<< s.totalCost(costs, k, candidates); 

    return 0;
}
