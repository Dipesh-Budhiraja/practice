// Recursion

int solve(int n, int x, int y, int z) {
    if (n < 0) {
        return -1;
    }
    if (n == 0) {
        return 0;
    }
    
    int xans = solve(n-x, x,y,z);
    int yans = solve(n-y, x,y,z);
    int zans = solve(n-z, x,y,z);
    
    int ans = max(xans, max(yans, zans));
    if (ans != -1) {
        ans = ans + 1;
    }
    
    return ans;
}

int cutSegments(int n, int x, int y, int z) {
	// Write your code here.
    int ans = solve(n, x, y, z);
    if(ans == -1) 
        return 0;
    return ans;
}


// memo
#include<climits>
int solve(int n, int x, int y, int z, vector<int> &dp) {
    if (n < 0) {
        return INT_MIN;
    }
    if (n == 0) {
        return 0;
    }
    
    if (dp[n] != -1) {
        return dp[n];
    }
    
    int xans = solve(n-x, x,y,z, dp);
    int yans = solve(n-y, x,y,z, dp);
    int zans = solve(n-z, x,y,z, dp);
    
    int ans = max(xans, max(yans, zans));
    if (ans != INT_MIN) {
        ans = ans + 1;
    }
    
    return dp[n] = ans;
}

int cutSegments(int n, int x, int y, int z) {
	// Write your code here.
    vector<int> dp(n+1, -1);
    int ans = solve(n, x, y, z, dp);
    if(ans == INT_MIN) 
        return 0;
    return ans;
}

// tab
#include<climits>
int cutSegments(int n, int x, int y, int z) {

    vector<int> dp(n+1, INT_MIN);
    dp[0] = 0;
    
    for(int i=1; i<=n; i++) {
        int xans = (i-x>=0) ? dp[i-x] : INT_MIN;
        int yans = (i-y>=0) ? dp[i-y] : INT_MIN;
        int zans = (i-z>=0) ? dp[i-z] : INT_MIN;
        
        int ans = max(xans, max(yans, zans));
        if (ans != INT_MIN) {
            ans = ans + 1;
        }
        dp[i] = ans;
    }
    if (dp[n] == INT_MIN) {
        return 0;
    }
    return dp[n];
}
