#include <bits/stdc++.h> 

int solve(vector<int> &nums, int x, vector<int> &dp) {
    if (x == 0) {
        return 0;
    }
    
    if (x < 0) {
        return INT_MAX;
    }
    
    if (dp[x] != -1) {
        return dp[x];
    }
    
    int n = nums.size();
    int mini = INT_MAX;
    for (int i = 0; i < n; i++) {
        int ans = solve(nums, x - nums[i], dp);
        if (ans != INT_MAX) {
            mini = min(mini, 1 + ans);
        }
    }
    
    return dp[x] = mini;
}

int minimumElements(vector<int> &nums, int x)
{
    vector<int> dp(x+1, -1);
    int ans = solve(nums, x, dp);
    if (ans == INT_MAX) {
        return -1;
    }
    return ans;
}