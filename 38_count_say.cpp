#include <string>

using namespace std;


class Solution {
  public:
    string countAndSay(int n) {
      // base case
      if(n==1)
        return "1";
      if(n==2)
        return "11";

      // take a string equals 11
      string str = "11";

      // now we need the value of nth term so we loop from 3 -> n
      for(int i=3; i<=n ; i++)
      {
        // temp will have the ans of the next iteration i.e value of the next ith data
        string temp = "";
        str = str+"&"; // add a delimeter at the end
        int cnt = 1; // counter 

        // now loop from 1st value to last value
        for(int j = 1; j<str.length(); j++)
        {
          // this condition should be satisfied, if not that means new number has started occurring
          if(str[j]!=str[j-1])
          {
            temp = temp + to_string(cnt); // add the counter to temp
            temp = temp + str[j-1]; // add the data of the counter
            cnt = 1; // reset the counter to 1
          }
          else
            cnt++; // just count the freq of that number
        }
  
        // after one complete traversal, make str equal to temp;
        str = temp;
      }

      return str;
    }
};


/* Here is the explanation for the code above:
   1. We have a string str = "11"
   2. Now we will loop from 3 to n
   3. To find the value of the ith term, we will need the (i-1)th term, so we need to loop from 3 to n, that is why the loop is from 3 to n
   4. We will have a temp string which will store the value of the ith term
   5. We will add a delimeter at the end of the string, because we will be counting the freq of the last element as well, so if we don't add a delimeter then the last element won't be counted
   6. Now we will loop from 1 to str.length()
   7. We will have a counter cnt = 1
   8. If the current element is not equal to the previous element, then we will add the counter and the previous element to the temp string and then reset the counter to 1
   9. If the current element is equal to the previous element, then we will just increment the counter
   10. After the loop, we will make the temp string equal to str
   11. We will return the str after the loop ends

Example:
1st term: "1"
2nd term: "11"
3rd term: "21"
4th term: "1211"
5th term: "111221"
6th term: "312211"
7th term: "13112221"
8th term: "1113213211"
9th term: "31131211131221"
10th term: "13211311123113112211" */
