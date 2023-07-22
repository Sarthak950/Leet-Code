#include <iostream>
#include <vector>

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
       
        int m = matrix.size();
        int n = matrix[0].size();
        bool row = false;
        bool col = false;
        
        // check if first column has zero
        for(int i=0; i<m; i++){
            if(matrix[i][0] == 0){
                col = true;
                break;
            }
        }
        
        // check if first row has zero
        for(int j=0; j<n; j++){
            if(matrix[0][j] == 0){
                row = true;
                break;
            }
        }
        
        // check for zeros in the rest of the array
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(matrix[i][j]==0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                } 
            }
        }
        
        // set the corresponding rows and columns to zero
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j] = 0;
                } 
            }
        }
        
        // see if the first row needs to be set to zero
        if(row){
            for(int j=0; j<n; j++){
                matrix[0][j] = 0;
            }
        }
        
        // see if the first column needs to be set to zero
        if(col){
            for(int i=0; i<m; i++){
                matrix[i][0] = 0;
            }
        }

    }
};
