// Question: Stock Buy And Sell
// Problem Statement: You are given an array of prices where prices[i] is the price of a given stock on an ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

//leetcode:121 link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int buy=prices[0];
        int profit=0;
        for(int i=1;i<n;i++){
            profit=max(profit,prices[i]-buy);
            buy=min(buy,prices[i]);
        }
        return profit;
    }
};

// tc:O(n)
// sc:O(1)
