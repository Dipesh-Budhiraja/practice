#include "header.h"

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        int cursum = 0;
        unordered_map<int, int> preSum;
        preSum[0] = 1;

        for (int i = 0; i < nums.size(); i++) {
            cursum += nums[i];

            int diff = cursum - k;
            if (preSum.find(diff) != preSum.end()) {
                res += preSum[diff];
            }

            preSum[cursum]++;
        }

        return res;
    }
};