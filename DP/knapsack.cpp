#include "header.h"

// memo
int solve(vector<int> weight, vector<int> value, int n, int maxWeight, vector<vector<int> > &dp) {
    if (n < 0 || maxWeight <= 0) {
        return 0;
    }
    
    if (dp[n][maxWeight] != -1) {
        return dp[n][maxWeight];
    }
    
    int taken = 0;
    if(maxWeight >= weight[n]) {
        taken = solve(weight, value, n-1, maxWeight - weight[n], dp) + value[n];
    } 
    int notTaken = solve(weight, value, n-1, maxWeight, dp);
    
    dp[n][maxWeight] = max(taken, notTaken);
    return dp[n][maxWeight];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    vector<vector<int> > dp(n, vector<int> (maxWeight+1, -1));
	return solve(weight, value, n-1, maxWeight, dp);
}


// memo2 - adjusted base case love babbar
int solve(vector<int> weight, vector<int> value, int index, int maxWeight, vector<vector<int> > &dp) {
    if (index == 0) {
        if (weight[index] <= maxWeight) {
            return value[index];
        }
        return 0;
    }
    
    if (dp[index][maxWeight] != -1) {
        return dp[index][maxWeight];
    }
    
    int taken = 0;
    if(maxWeight >= weight[index]) {
        taken = solve(weight, value, index-1, maxWeight - weight[index], dp) + value[index];
    } 
    int notTaken = solve(weight, value, index-1, maxWeight, dp);
    
    dp[index][maxWeight] = max(taken, notTaken);
    return dp[index][maxWeight];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    vector<vector<int> > dp(n, vector<int> (maxWeight+1, -1));
	return solve(weight, value, n-1, maxWeight, dp);
}


// tabulation
int solveTab(vector<int> weight, vector<int> value, int n, int maxWeight) {
    vector<vector<int> > dp(n, vector<int> (maxWeight+1, 0));
    
    for (int i=0; i <= maxWeight; i++) {
        if (weight[0] <= i) {
            dp[0][i] = value[0];
        } else {
            dp[0][i] = 0;
        }
    }
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= maxWeight; j++) {
            int taken = 0;
            if (j >= weight[i]) {
                taken = dp[i-1][j-weight[i]] + value[i];
            }
            int notTaken = dp[i-1][j];
            dp[i][j] = max(taken, notTaken);
        }
    }
    
    return dp[n-1][maxWeight];
    
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	return solveTab(weight, value, n, maxWeight);
}



// tabulation + space optimised
int solveTab(vector<int> weight, vector<int> value, int n, int maxWeight) {
    vector<int> dp(maxWeight+1, 0);
    
    for (int i=0; i <= maxWeight; i++) {
        if (weight[0] <= i) {
            dp[i] = value[0];
        } else {
            dp[i] = 0;
        }
    }
    
    for (int i = 1; i < n; i++) {
        vector<int> temp(maxWeight+1, 0);
        for (int j = 0; j <= maxWeight; j++) {
            int taken = 0;
            if (j >= weight[i]) {
                taken = dp[j-weight[i]] + value[i];
            }
            int notTaken = dp[j];
            temp[j] = max(taken, notTaken);
        }
        
        for (int j = 0; j <= maxWeight; j++) {
            dp[j] = temp[j];
        }
    }
    
    return dp[maxWeight];
    
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	return solveTab(weight, value, n, maxWeight);
}