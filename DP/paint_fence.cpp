#include "header.h"

// rec
#define MOD 1000000007

int numberOfWays(int n, int k) {
    if (n==1) {
        return k;
    }
    
    if (n==2) {
        return k*k;
    }
    
    int ans = (((numberOfWays(n-2, k)%MOD)*(k-1))%MOD + ((numberOfWays(n-1, k)%MOD)*(k-1))%MOD)%MOD;
    return ans;
}

// memo
#define MOD 1000000007

int add(int a, int b) {
    return (a%MOD + b%MOD)%MOD; 
}

int mul(int a, int b) {
    return (a%MOD * 1LL * b%MOD)%MOD; 
}

int solveMem(int n, int k, vector<int> &dp) {
    if (n==1) {
        return k;
    }
    
    if (n==2) {
        return k*k; // add(k, mul(k, k-1))
    }
    
    if (dp[n] != -1) {
        return dp[n];
    }
    
    dp[n] = add( mul(solveMem(n-2, k, dp), k-1) , mul(solveMem(n-1, k, dp), k-1) );
    return dp[n];
}

int numberOfWays(int n, int k) {
    vector<int> dp(n+1, -1);
    int ans = solveMem(n, k, dp);
    return ans;
}

// tab
int solveTab(int n, int k) {
    vector<int> dp(n+1, 0);
    dp[1] = k;
    dp[2] = k*k;
    
    for(int i=3; i<=n; i++) {
        int first = mul(dp[i-2], k-1);
        int second = mul(dp[i-1], k-1);
        dp[i] = add(first, second);
    }
    
    return dp[n];
}

int numberOfWays(int n, int k) {
    return solveTab(n, k);
}


// space optimisation
int solveTab(int n, int k) {
    int prev2 = k;
    int prev1 = k*k;
    
    for(int i=3; i<=n; i++) {
        int first = mul(prev2, k-1);
        int second = mul(prev1, k-1);
        int ans = add(first, second);
        prev2 = prev1;
        prev1 = ans;
    }
    
    return prev1;
}

int numberOfWays(int n, int k) {
    return solveTab(n, k);
}





