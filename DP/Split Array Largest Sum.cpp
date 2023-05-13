#include "header.h"

class Solution {
public:

    int solve(vector<int>& nums, int i, int k, vector<vector<int> > &dp) {
        if (k == 1) {
            int sum = 0;
            for (int index = i; index < nums.size(); index++) {
                sum += nums[index];
            }
            return dp[i][k] = sum;
        }

        if (dp[i][k] != -1) {
            return dp[i][k];
        }

        int res = INT_MAX;
        int cursum = 0;

        for (int j = i; j < nums.size() - k+1; j++) {
            cursum += nums[j];
            int maxSum = max(cursum, solve(nums, j+1, k-1, dp));
            res = min(res, maxSum);
            if (cursum > res) {
                break;
            }
        }
        
        return dp[i][k] = res; 
    }


    int splitArray(vector<int>& nums, int k) {
        vector<vector<int> > dp(nums.size() + 1, vector<int>(k+1, -1));
        return solve(nums, 0, k, dp);
    }
};