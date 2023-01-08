#include <bits/stdc++.h> 

int solve(vector<int> &nums, int i, vector<int> &dp) {
    if (i < 0) {
        return 0;
    }
    
    if (i == 0) {
        return nums[i];
    }
    
    if (dp[i] != -1) {
        return dp[i];
    }
    
    int incl = solve(nums, i-2, dp) + nums[i];
    int excl = solve(nums, i-1, dp);
    
    return dp[i] = max(incl, excl);
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n, -1);
    
    int ans = solve(nums, n-1, dp);
    
    return ans;
}