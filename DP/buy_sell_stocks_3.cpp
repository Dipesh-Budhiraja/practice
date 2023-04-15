#include "header.h"

class Solution {
public:
    int solve(int i, int buy, int rem_txn, vector<int>& prices, vector<vector<vector<int> > > &dp) {
        if (i == prices.size()) {
            return 0;
        }
        if (rem_txn <= 0) {
            return 0;
        }
        if (dp[i][buy][rem_txn] != -1) {
            return dp[i][buy][rem_txn];
        }
        int profit = 0;
        if (buy == 1) { // buy karni ki permission hai
            // buy or skip
            profit = max( (-prices[i] + solve(i+1, 0, rem_txn, prices, dp)) , 
                            (solve(i+1, 1, rem_txn, prices, dp)) );
        } else { // buy ho rakha hai
            // sell or skip
            profit = max( (prices[i] + solve(i+1, 1, rem_txn - 1, prices, dp)) , 
                            (solve(i+1, 0, rem_txn, prices, dp)) );
        }
        return dp[i][buy][rem_txn] = profit;
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int> > >dp(prices.size(), vector<vector<int> >(2, vector<int>(3, -1)));
        return solve(0, 1, 2, prices, dp);
    }
};
