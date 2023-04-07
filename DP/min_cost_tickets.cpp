#include "header.h"

int solve(int n, vector<int> &days, vector<int> &cost, int index, vector<int> &dp) {
    if (index >= n) {
        return 0;
    }
    
    if (dp[index] != -1) {
        return dp[index];
    }
    
    int ans = INT_MAX;
    
    // 1 day 
    int day1 = solve(n, days, cost, index+1, dp) + cost[0];
    ans = min(ans, day1);
    
    int indexFor7days = index;
    while(indexFor7days < n && (days[indexFor7days] - days[index] < 7)) {
        indexFor7days++;
    }
    int day7 = solve(n, days, cost, indexFor7days, dp) + cost[1];
    ans = min(ans, day7);
    
    int indexFor30days = index;
    while(indexFor30days < n && (days[indexFor30days] - days[index] < 30)) {
        indexFor30days++;
    }
    int day30 = solve(n, days, cost, indexFor30days, dp) + cost[2];
    ans = min(ans, day30);
    
    return dp[index]=ans;
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    vector<int> dp(n+1, -1);
    int ans = solve(n, days, cost, 0, dp);
    
    return ans;
}