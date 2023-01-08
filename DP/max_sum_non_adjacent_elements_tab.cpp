int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    
    for (int i = 1; i<n; i++) {
        
        int incl = (i >= 2) ? (dp[i-2] + nums[i]): nums[i];
        int excl = dp[i-1];
        
        dp[i] = max(incl, excl);
    }
    
    return dp[n-1];
}


int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    int prev2 = 0;
    int prev1 = nums[0];
    int ans = 0;
    
    for (int i = 1; i<n; i++) {
        
        int incl = prev2 + nums[i];
        int excl = prev1;
        
        ans = max(incl, excl);
        prev2 = prev1;
        prev1 = ans;
    }
    
    return prev1;
    
}