#include "header.h"

class Solution{
	public:
	
	int solve(int n, vector<int> &dp) {
	    if (n < 0) {
	        return INT_MAX;
	    }
	    if (n == 0) {
	        return 0;
	    }
	    
	    if (dp[n] != -1) {
	        return dp[n];
	    }
	    
	    int ans = INT_MAX;
	    for (int i = 1; i*i <= n; i++) {
	        int curans = solve(n - i*i, dp);
	        if (curans != INT_MAX) {
	            ans = min(curans + 1, ans);
	        }
	    }
	    
	    return dp[n] = ans;
	}
	int MinSquares(int n)
	{
	    vector<int> dp(n+1, -1);
	    return solve(n, dp);
	}
};

class Solution{
	public:
	
	int solveTab(int n) {
	    vector<int> dp(n+1, INT_MAX);
	    dp[0] = 0;
	    
	    for(int i = 1; i<=n; i++) {
	        for (int j = 1; j*j <= i; j++) {
	            int curans = INT_MAX;
	            if (i - j*j >= 0) {
	                curans = dp[i - j*j];
	            }
	            if (curans != INT_MAX) {
	                dp[i] = min(curans + 1, dp[i]);
	            }
	        }
	    }
	    
	    return dp[n];
	}
	
	int MinSquares(int n)
	{
	    return solveTab(n);
	}
};