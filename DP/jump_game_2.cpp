#include "header.h"

class Solution {
public:
    int solve(vector<int>& nums, int i, int n, vector<int> &dp) {
        if (i >= n-1) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        int maxJump = nums[i];
        int leastJumps = INT_MAX-1;
        for (int j = i + 1; j <= i + maxJump && j < n; j++) {
            int curans = 1 + solve(nums, j, n, dp);
            leastJumps = min(leastJumps, curans);
        }
        return dp[i] = leastJumps;
    }

    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        int ans = solve(nums, 0, n, dp);
        return ans;
    }
};