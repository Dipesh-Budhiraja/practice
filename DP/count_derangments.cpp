#include "header.h"
// rec
#define MOD 1000000007

long long int countDerangements(int n) {
    // Write your code here.
    if (n == 1) {
        return 0;
    }
    
    if (n == 2) {
        return 1;
    }
    
    long long int ans = ( ((n-1)%MOD) * ( (countDerangements(n-2)%MOD) + 
                                (countDerangements(n-1)%MOD))%MOD);
    return ans;
}


// memo
#define MOD 1000000007
#include<vector>

long long int solveMem(int n, vector<long long int> &dp) {
    if (n == 1) {
        return 0;
    }
    
    if (n == 2) {
        return 1;
    }
    
    if (dp[n] != -1) {
        return dp[n];
    }
    
    dp[n] = ( ((n-1)%MOD) * ( (solveMem(n-2, dp)%MOD) + 
                                (solveMem(n-1, dp)%MOD))%MOD);
    return dp[n];
}

long long int countDerangements(int n) {
    vector<long long int> dp(n+1, -1);
    return solveMem(n, dp);
    
}

// tab
#define MOD 1000000007
#include<vector>
#define lli long long int


long long int solveTab(int n) {
    vector<lli> dp(n+1, 0);
    dp[1] = 0;
    dp[2] = 1;
    for(int i = 3; i<=n; i++) {
        lli first = dp[i-1]%MOD;
        lli second = dp[i-2]%MOD;
        lli sum = (first + second)%MOD;
        dp[i] = ((i-1)*sum)%MOD;
        
    }
    return dp[n];
}

long long int countDerangements(int n) {
    return solveTab(n);
    
}