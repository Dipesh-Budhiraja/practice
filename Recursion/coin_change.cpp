#include <bits/stdc++.h> 

int solve(vector<int> &nums, int x) {
    if (x == 0) {
        return 0;
    }
    
    if (x < 0) {
        return INT_MAX;
    }
    
    int n = nums.size();
    int mini = INT_MAX;
    for (int i = 0; i < n; i++) {
        int ans = solve(nums, x - nums[i]);
        if (ans != INT_MAX) {
            mini = min(mini, 1 + ans);
        }
    }
    
    return mini;
}

int minimumElements(vector<int> &nums, int x)
{
    int ans = solve(nums, x);
    if (ans == INT_MAX) {
        return -1;
    }
    return ans;
}