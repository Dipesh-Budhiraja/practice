#include <bits/stdc++.h> 

int solve(vector<int> &nums, int n) {
    if (n < 0) {
        return 0;
    }
    
    if (n == 0) {
        return nums[n];
    }
    
    int incl = solve(nums, n-2) + nums[n];
    int excl = solve(nums, n-1);
    
    return max(incl, excl);
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    
    int ans = solve(nums, n-1);
    
    return ans;
}