#include <bits/stdc++.h> 

int solve(int nStairs, int i) {
    if (i == nStairs) {
        return 1;
    }
    
    if (i > nStairs) {
        return 0;
    }
    
    return solve(nStairs, i+1) + solve(nStairs, i+2);
}

int countDistinctWays(int nStairs) {
    return solve(nStairs, 0);
}