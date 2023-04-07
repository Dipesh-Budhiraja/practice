#include "header.h"

class Solution {
public:

    int solveTab(string &a, string &b) {
        int m = a.length();
        int n = b.length();

        vector<vector<int> > dp(m+1, vector<int>(n+1, 0));

        for (int i = m-1; i>=0; i--) {
            for (int j = n-1; j>= 0; j--) {
                int ans = 0;
                if (a[i] == b[j]) {
                    ans = 1 + dp[i+1][j+1];
                } else {
                    ans = max(dp[i][j+1], dp[i+1][j]);
                }

                dp[i][j] = ans;
            }
        }

        return dp[0][0];
    }

    int longestPalindromeSubseq(string s) {
        string revstring = "";
        for (int i = s.length()-1; i>=0; i--) {
            revstring += s[i];
        }

        return solveTab(s, revstring);
    }
};