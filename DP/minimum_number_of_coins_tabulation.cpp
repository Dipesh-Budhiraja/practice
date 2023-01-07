
int minimumElements(vector<int> &nums, int x)
{
    vector<int> dp(x+1, INT_MAX);
    dp[0] = 0;
    int n = nums.size();
    
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            int index = i - nums[j];
            if (index >= 0) {
                if (dp[index] != INT_MAX) {
                    dp[i] = min(dp[i], 1 + dp[index]);
                }
                
            }
        }
    }

    if (dp[x] == INT_MAX) {
        return -1;
    }
    return dp[x];
}