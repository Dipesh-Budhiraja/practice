#include "header.h"


// recursive + dp
class Solution {
public:
    int solve(int i, int buy, vector<int>& prices, vector<vector<int> > &dp) {
        if (i == prices.size()) {
            return 0;
        }

        if (dp[i][buy] != -1) {
            return dp[i][buy];
        }

        int profit = 0;

        if (buy == 1) { // buy karni ki permission hai
            // buy or skip
            profit = max( (-prices[i] + solve(i+1, 0, prices, dp)) , (solve(i+1, 1, prices, dp)) );
        } else { // buy ho rakha hai
            // sell or skip
            profit = max( (prices[i] + solve(i+1, 1, prices, dp)) , (solve(i+1, 0, prices, dp)) );
        }

        return dp[i][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int> >dp(prices.size(), vector<int>(2, -1));
        return solve(0, 1, prices, dp);
    }
};

// one pass
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        int curmin = prices[0];
        int cursum = 0;
        for (int i = 1; i < n; i++) {
            if (prices[i] < prices[i-1]) {
                curmin = prices[i];
                cout << "adding cursum: " << cursum << " at i: " << i << endl;
                ans += cursum;
                cursum = 0;
            } else {
                cursum = prices[i] - curmin;
            }
        }
        if (n == 1 || n == 0) {
            return 0;
        }
        if (prices[n-1] >= prices[n-2]) {
            cout << "adding at last, curmin: " << curmin << endl;
            ans += prices[n-1] - curmin;
        }
        return ans;
    }
};


// better one pass
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
       
        for (int i = 1; i < n; i++) {
            if (prices[i] > prices[i-1]) {
                ans += prices[i] - prices[i-1];
            }
        }
        return ans;
    }
};

