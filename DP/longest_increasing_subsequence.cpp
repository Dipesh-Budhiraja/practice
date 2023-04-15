#include "header.h"

class Solution {
public:

    int solve(vector<int>& nums, int i, int indexOfLastNumberTaken) {
        if (i == nums.size()) {
            return 0;
        }

        int curans = 0;
        int opt1 = 0;
        int opt2 = 0;
        if (indexOfLastNumberTaken == -1 || nums[indexOfLastNumberTaken] < nums[i]) {
            opt1 = 1 + solve(nums, i+1, i);
        }
        opt2 = solve(nums, i+1, indexOfLastNumberTaken);
        curans = max(opt1, opt2);

        return curans;
    }

    int solveMem(vector<int>& nums, int i, int indexOfLastNumberTaken, vector<vector<int> > &dp) {
        if (i == nums.size()) {
            return 0;
        }

        if (dp[i][indexOfLastNumberTaken + 1] != -1) {
            return dp[i][indexOfLastNumberTaken + 1];
        }
        
        int curans = 0;
        int opt1 = 0;
        int opt2 = 0;
        if (indexOfLastNumberTaken == -1 || nums[indexOfLastNumberTaken] < nums[i]) {
            opt1 = 1 + solveMem(nums, i+1, i, dp);
        }
        opt2 = solveMem(nums, i+1, indexOfLastNumberTaken, dp);
        curans = max(opt1, opt2);

        return  dp[i][indexOfLastNumberTaken+1] = curans;
    }

    int solveTab(vector<int> &nums) {
        int n = nums.size();
        vector<vector<int> > dp(n+1, vector<int>(n+1, 0));

        for (int cur = n-1; cur >= 0; cur--) {
            for(int pre = cur-1; pre >= -1; pre--) {
                int curans = 0;
                int opt1 = 0;
                int opt2 = 0;
                if (pre == -1 || nums[pre] < nums[cur]) {
                    opt1 = 1 + dp[cur+1][cur+1];
                }
                opt2 = dp[cur+1][pre+1];
                curans = max(opt1, opt2);

                dp[cur][pre+1] = curans;
            }
        }

        return dp[0][0];
    }

    int lengthOfLIS(vector<int>& nums) {
        // return solve(nums, 0, -1);


        // int m = nums.size();
        // vector<vector<int> > dp(m, vector<int>(m+1, -1));
        // return solveMem(nums, 0, -1, dp);

        return solveTab(nums);
    }
};


int solveOptimal(vector<int> &nums) {
    if (nums.size() == 0) {
        return 0;
    }

    vector<int> ans;
    ans.push_back(nums[0]);

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > ans.back()) {
            ans.push_back(nums[i]);
        } else {
            // just bade number ka index
            int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
            ans[index] = nums[i];
        }
    }
    return ans.size();
}

int lengthOfLIS(vector<int>& nums) {
    // return solve(nums, 0, -1);


    // int m = nums.size();
    // vector<vector<int> > dp(m, vector<int>(m+1, -1));
    // return solveMem(nums, 0, -1, dp);

    // return solveTab(nums);

    return solveOptimal(nums);
}