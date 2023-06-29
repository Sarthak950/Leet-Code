/*
You are given three integers x, y, and z.
You have x strings equal to "AA", y strings equal to "BB", and z strings equal to "AB". You want to choose some (possibly all or none) of these strings and concactenate them in some order to form a new string. This new string must not contain "AAA" or "BBB" as a substring
A substring is a contiguous non-empty sequence of characters within a string.

Input: x = 2, y = 5, z = 1
Output: 12
Explanation: We can concactenate the strings "BB", "AA", "BB", "AA", "BB", and "AB" in that order. Then, our new string is "BBAABBAABBAB". 
That string has length 12, and we can show that it is impossible to construct a string of longer length.

Input: x = 3, y = 2, z = 2
Output: 14
Explanation: We can concactenate the strings "AB", "AB", "AA", "BB", "AA", "BB", and "AA" in that order. Then, our new string is "ABABAABBAABBAA". 
That string has length 14, and we can show that it is impossible to construct a string of longer length.


*/

class Solution {
public:
    int longestString(int x, int y, int z) {

        int ans = 0;
        int a = 0;
        int b = 0;
        int c = 0;

        while (true){
            if (x > 0){
                a++;
                x--;
            }
            else if (y > 0){
                b++;
                y--;
            }
            else if (z > 0){
                c++;
                z--;
            }
            else{
                break;
            }

            if (a >= 2 && b >= 2){
                ans += 2;
                a -= 2;
                b -= 2;
            }
            else if (a >= 2 && c >= 1){
                ans += 2;
                a -= 2;
                c -= 1;
            }
            else if (b >= 2 && c >= 1){
                ans += 2;
                b -= 2;
                c -= 1;
            }
        }

        return ans;
        
    }
};