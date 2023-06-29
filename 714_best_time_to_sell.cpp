#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buy = INT_MIN;
        int sell = 0;

        for (int price : prices){
            buy  = max(buy, sell - price);
            sell = max(sell, buy + price - fee);
        }

        return sell;

    }
};


//[1,3,2,8,4,9]
//here is the sample array let do a dry run 

//buy = -1
//sell = 0

//price = 1
//buy = max(-1, 0-1) = -1
//sell = max(0, -1+1-2) = 0

//price = 3
//buy = max(-1, 0-3) = -1
//sell = max(0, -1+3-2) = 0

//price = 2
//buy = max(-1, 0-2) = -1
//sell = max(0, -1+2-2) = 0

//price = 8
//buy = max(-1, 0-8) = -1
//sell = max(0, -1+8-2) = 5

//price = 4
//buy = max(-1, 5-4) = 1
//sell = max(5, 1+4-2) = 5

//price = 9
//buy = max(1, 5-9) = 1
//sell = max(5, 1+9-2) = 8

//return sell = 8

/* Here is the explanation for the code above:
1. We can keep track of two variables, which represents the max profit we can make if we own some stock and if we don't own any stock, respectively. We can start at 0, because we don't have any stock in the beginning, and we can represent the fact that it's not possible to make any profit if we have no stock. We can also represent the fact that it's not possible to make a loss greater than 0 if we have no stock, since we can always just not buy the stock.

2. Now, we can iterate through the array of prices and update our variables accordingly. If we own some stock, we can either choose to keep it or sell it, depending on which one gives us a higher profit. If we don't own any stock, we can either choose to keep not owning any stock or buy one, depending on which one gives us a higher profit. Note that we don't have to worry about the case where we sell a stock and buy it back on the same day, because the problem states that we can only buy and sell once per day.

3. Finally, we just have to return the maximum profit we can make if we don't own any stock, since selling is always better than keeping the stock at the end. */
