// #include <iostream>
// #include<vector>
#include <bits/stdc++.h>

using namespace std;


class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {

            vector<int> ans;
            if(matrix.empty()) return ans;

            int m = matrix.size();
            int n = matrix[0].size();

            int left = 0, right = n-1, top = 0, bottom = m-1;

            while (left <= right && top <= bottom) {

                for( int i= left ; i<= right;i++) ans.push_back(matrix[top][i]);
                top++;
                for (int i=top; i<= bottom; i++) ans.push_back(matrix[i][right]);
                top--;
                // if(left < right && top < bottom){
                    for(int i=right-1; i> left; i--) ans.push_back(matrix[bottom][i]);
                    for(int i=bottom; i>top; i--) ans.push_back(matrix[i][left]);
                // }
                top++;
                left++;
                right--;
                bottom--;

            }
            return ans;
        }
};




int main( ){


    vector<vector<int>> matrix = {{1, 2, 3},
                                  {4, 5, 6},
                                  {7, 8, 9}};

    Solution s;
    vector<int> ans = s.spiralOrder(matrix);

    for(int i=0; i<ans.size(); i++) cout << ans[i] << " "<<endl;

    return 0;
}
