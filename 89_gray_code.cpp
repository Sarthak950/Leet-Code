#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        
        //create a vec for the 2^n ans
        vector<int> ans(1<<n);

        //loop to 2^n
        for (int i=0; i<(1<<n); i++) 
            ans[i] = i^(i>>1);
        
        return ans;
    }
};


auto bin(long n){

    long i;
    cout << "0";
    bool flag = 0;
    for (i = 1 << 30; i > 0; i = i / 2){
        
        if((n & i) != 0){
            flag = 1;
            cout << "1";
        
        }
        else{
            if(flag == 1)
            cout << "0";
        }
    }
    cout<<"  ";
}


int main(){

    for(int i=0;i<100;i++){
        cout<<i <<" "<<(i>>1)<<" "<<(i^(i>>1))<<"  ";
        bin(i);
        bin(i>>1);
        bin(i^(i>>1));
        cout<<endl<<endl;
    }

    return 0;
}
