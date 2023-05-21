#include "header.h"
#include <numeric>

class Solution 
{
    public:
    
    int number_of_subarrays_with_mid_as_max_sum(vector<int>& nums, int mid) {
        int count = 1;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (sum + nums[i] > mid) {
                count++;
                sum = nums[i];
            } else {
                sum += nums[i];
            }
        }
        return count;
    }

    int splitArray(vector<int>& nums, int m) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        int ans = high;
        while(low <= high) {
            int mid = (low + high)/2;
            int splits = number_of_subarrays_with_mid_as_max_sum(nums, mid);
            if (splits > m) {
                low = mid + 1;
            } else {
                ans = mid;
                high = mid-1;
            }
        }
        return ans;
    }
    
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        if (N < M) {
            return -1;
        }
        vector<int> nums(A, A + N);
        return splitArray(nums, M);
    }
};