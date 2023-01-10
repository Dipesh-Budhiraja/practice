#include "header.h"

// memo
int solve(vector<int> &num, int tar, int n, vector<int> &dp) {
    if (tar < 0) {
        return 0;
    }
    if (tar == 0) {
        return 1;
    }
    
    if (dp[tar] != -1) {
        return dp[tar];
    }
    
    int ans = 0;
    for (int i = 0; i<n; i++) {
        ans += solve(num, tar - num[i], n, dp);
    }
    dp[tar] = ans;
    return dp[tar];
}

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<int> dp(tar+1, -1);
    int ans = solve(num, tar, n, dp);
    return ans;
}


// tab
int solveTab(vector<int> &num, int tar) {
    int n = num.size();
    vector<int> dp(tar+1, 0);
    dp[0] = 1;
    
    for (int i=1; i<=tar; i++) {
        for (int j=0; j<n; j++) {
            if(i - num[j] >= 0) {
                dp[i] += dp[i - num[j]] ;
            }
        }
    }
    return dp[tar];
}

int findWays(vector<int> &num, int tar)
{
    int ans = solveTab(num, tar);
    return ans;
}