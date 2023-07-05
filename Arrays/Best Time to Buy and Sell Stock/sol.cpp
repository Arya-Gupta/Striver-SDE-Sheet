/*
Time Complexity - Iterating through the array takes O(N) time.
 
Space Complexity - Since we do not store anything, space taken is O(1).

Explanation - https://takeuforward.org/data-structure/stock-buy-and-sell/
*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), minPrice = INT_MAX, maxProfit = 0;
        for(int i = 0; i < n; i++){
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }
        return maxProfit;
    }
};