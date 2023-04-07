#include "header.h"

class Solution {
public:

    int solve(string a, string b, int i, int j) {
        if (i == a.length()) {
            return b.length() - j;
        }

        if (j == b.length()) {
            return a.length() - i;
        }

        int ans = 0;

        if (a[i] == b[j]) {
            ans = solve(a, b, i+1, j+1);
        } else {
            int insertAns = solve(a, b, i, j+1) + 1;
            int delAns = solve(a, b, i+1, j) + 1;
            int replaceAns = solve(a, b, i+1, j+1) + 1;
            ans = min(insertAns, min(delAns, replaceAns));
        }
        return ans;
    }


    int solveMem(string a, string b, int i, int j, vector<vector<int> > &dp) {
        if (i == a.length()) {
            return b.length() - j;
        }

        if (j == b.length()) {
            return a.length() - i;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int ans = 0;

        if (a[i] == b[j]) {
            ans = solveMem(a, b, i+1, j+1, dp);
        } else {
            int insertAns = solveMem(a, b, i, j+1, dp) + 1;
            int delAns = solveMem(a, b, i+1, j, dp) + 1;
            int replaceAns = solveMem(a, b, i+1, j+1, dp) + 1;
            ans = min(insertAns, min(delAns, replaceAns));
        }
        return dp[i][j] = ans;
    }

    int solveTab(string a, string b) {
        vector<vector<int> > dp(a.length()+1, vector<int>(b.length()+1, 0));

        // base cases
        for (int j=0; j<=b.length(); j++) {
            dp[a.length()][j] = b.length() - j;
        }

        for (int i=0; i<=a.length(); i++) {
            dp[i][b.length()] = a.length() - i;
        }

        for (int i = a.length() - 1; i >= 0; i--) {
            for(int j = b.length() - 1; j >=0; j--) {
                if (a[i] == b[j]) {
                    dp[i][j] = dp[i+1][j+1];
                } else {
                    int insertAns = dp[i][j+1] + 1;
                    int delAns = dp[i+1][j] + 1;
                    int replaceAns = dp[i+1][j+1] + 1;
                    dp[i][j] = min(insertAns, min(delAns, replaceAns));
                }
            }
        }

        return dp[0][0];
    }

    int minDistance(string word1, string word2) {
        // return solve(word1, word2, 0, 0);

        // vector<vector<int> > dp(word1.length(), vector<int>(word2.length(), -1));
        // return solveMem(word1, word2, 0, 0, dp);

        return solveTab(word1, word2);
    }
};