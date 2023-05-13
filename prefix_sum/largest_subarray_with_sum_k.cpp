#include "header.h" 
#define ll long long
int getLongestSubarray(vector<int>& nums, int k){
    unordered_map<ll, int> prefixSums;
    ll sum = 0;
    int ans = 0;

    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];

        if (sum == k) {
            ans = i+1;
        }
        int rem = sum - k;
        if (prefixSums.find(rem) != prefixSums.end()) {
            ans = max(ans, i - prefixSums[rem]);
        }

        if (prefixSums.find(sum) == prefixSums.end()) {
            prefixSums[sum] = i;
        }
    }

    return ans;
}