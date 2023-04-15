#include "header.h"

class Solution{
public:
    int solve(vector<vector<int> > mat, int i, int j, int &ans) {
        if (i >= mat.size() || j >= mat[0].size()) {
            return 0;
        }
        
        int right = solve(mat, i, j+1, ans);
        int diag =  solve(mat, i+1, j+1, ans);
        int down = solve(mat, i+1, j, ans);
        
        if (mat[i][j] == 1) {
            int cur = 1 + min(right, min(diag, down));
            ans = max(ans, cur);
            return cur;
        } else {
            return 0;
        }
    }

    int maxSquare(int n, int m, vector<vector<int> > mat){
        int ans = 0;
        solve(mat, 0, 0, ans);
        return ans;
    }
};

int solveMem(vector<vector<int> > &mat, int i, int j, int &ans, vector<vector<int> > &dp) {
    if (i >= mat.size() || j >= mat[0].size()) {
        return 0;
    }
    
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    
    int right = solveMem(mat, i, j+1, ans, dp);
    int diag =  solveMem(mat, i+1, j+1, ans, dp);
    int down = solveMem(mat, i+1, j, ans, dp);
    
    if (mat[i][j] == 1) {
        dp[i][j] = 1 + min(right, min(diag, down));
        ans = max(ans, dp[i][j]);
        return dp[i][j];
    } else {
        return dp[i][j] = 0;
    }
}

int maxSquare(int n, int m, vector<vector<int> > mat){
    // int ans = 0;
    // solve(mat, 0, 0, ans);
    // return ans;
    
    int ans = 0;
    vector<vector<int> > dp(n, vector<int>(m, -1));
    solveMem(mat, 0, 0, ans, dp);
    return ans;
    
}




int solveTab(vector<vector<int> > &mat, int &ans) {
    int row = mat.size();
    int col = mat[0].size();
    vector<vector<int> > dp(row+1, vector<int>(col+1, 0));
    
    for (int i = row-1; i>=0; i--) {
        for (int j = col-1; j>=0; j--) {
            int right = dp[i][j+1];
            int diag =  dp[i+1][j+1];
            int down = dp[i+1][j];
            
            if (mat[i][j] == 1) {
                dp[i][j] = 1 + min(right, min(diag, down));
                ans = max(ans, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }
}

int maxSquare(int n, int m, vector<vector<int> > mat){
    // int ans = 0;
    // solve(mat, 0, 0, ans);
    // return ans;
    
    // int ans = 0;
    // vector<vector<int> > dp(n, vector<int>(m, -1));
    // solveMem(mat, 0, 0, ans, dp);
    // return ans;
    
    int ans = 0;
    solveTab(mat, ans);
    return ans;
    
}