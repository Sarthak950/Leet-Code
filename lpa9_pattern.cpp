#include <iostream>
#include <vector>



using namespace std;
int main(){
    vector<int> vec{1,5,-6,0,-9,0,6,8,-2,0,0,0,0,0,9,8,7,6,5,4,3,2,1,0,-1,-2,-3,-4,-5,-6,-7,-8,-9};

    int max = *max_element(vec.begin(),vec.end());
    int min = *min_element(vec.begin(),vec.end());

    int range = max - min + 1;

    // while(range--){
    //     for (auto i:vec){
    //         if (i == max){
    //             cout<<" * ";
    //             i--;
    //         }
    //         else cout<<"   ";
    //     }
    //     cout<<endl;
    //     max--;
    // }
    while(max > 0){
        for(auto i: vec){
            if(i >= max) cout<<" * ";
            else cout<<"   ";
        }
        max--;
        cout<<endl;
    }

    for (auto i:vec) if(i>=0) cout<<" "<<i<<" "; else cout<<""<<i<<" ";
    cout<<endl;
    while(min < 0){
        for(int i=0;i<vec.size();i++){
            if(vec[i]<0){ 
                vec[i]++;
                cout<<" * ";
            }else cout<<"   ";
        }
        cout<<endl;
        min++;
    }

    return 0;
}

