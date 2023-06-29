#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;


class Solution {
    public:
    
    int myAtoi(string str) {
    
        int i = 0;
        int sign = 1;
        int result = 0;
        
        while (str[i] == ' ') {
            i++;
        }
        
        if (str[i] == '-' || str[i] == '+') {
            sign = 1 - 2 * (str[i++] == '-');
        }
        
        while (str[i] >= '0' && str[i] <= '9') {
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && str[i] - '0' > 7)) {
                if (sign == 1) {
                    return INT_MAX;
                } else {
                    return INT_MIN;
                }
            }
            
            result = result * 10 + (str[i++] - '0');
        }
        
        return result * sign;

    }

};

int main (int argc, char *argv[]) {
    Solution sol;

    string str = "   -123  ";

    cout<< sol.myAtoi(str);

    return 0;
}
