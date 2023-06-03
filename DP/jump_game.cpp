#include "header.h"

class Solution {
public:

    int solve(vector<int>& nums, int i, int n, vector<int> &dp) {
        if (i >= n-1) {
            return true;
        }
        if (dp[i] != -1) {
            return dp[i];
        }

        int maxJump = nums[i];
        for (int j = i + 1; j <= i + maxJump && j < n; j++) {
            int curans = solve(nums, j, n, dp);
            if (curans == 1) {
                return dp[i] = 1;
            }
        }

        return dp[i] = 0;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        int ans = solve(nums, 0, n, dp);
        return ans;
    }
};