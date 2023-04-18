#include "header.h"

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        long long ans = 0;

        int l = 0;
        int n = nums.size();
        bool repeatedNums = false;
        long long cursum = 0;
        int numberOfRepeatedNums = 0;
        for (int r = 0; r < n; r++) {
            // for first window
            while (r-l < k && r < n) {
                cursum += nums[r];
                if (count[nums[r]] == 1) {
                    repeatedNums = true;
                    numberOfRepeatedNums++;
                }
                count[nums[r]]++;
                r++;
            }

            if (repeatedNums == false) {
                ans = max(ans, cursum); 
            }

            // remove num from left
            count[nums[l]]--;
            if (count[nums[l]] == 1) {
                numberOfRepeatedNums--;
            }
            if (numberOfRepeatedNums == 0) {
                repeatedNums = false;
            }
            cursum -= nums[l];
            l++;
            r--;
        } 

        return ans;
    }
};