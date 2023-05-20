#include "header.h"

class Solution {
public:
    int find_pivot(vector<int>& nums, int l, int r) {
        if (l > r) {
            return -1;
        } 

        int mid = (l + r)/2;
        if (nums[mid] > nums[mid+1] ) {
            return nums[mid+1];
        } else if (mid-1 >= 0 && nums[mid - 1] > nums[mid]) {
            return nums[mid];
        } else if (nums[mid] > nums[r]) {
            return find_pivot(nums, mid + 1, r);
        } else {
            return find_pivot(nums, l, mid - 1);
        }

        return -1;
    }

    int findMin(vector<int>& nums) {

        if (nums.size() == 1) {
            return nums[0];
        }

        int answer = find_pivot(nums, 0, nums.size() - 1);
        if (answer == -1) { // when array was already sorted. no pivot point
            return nums[0];
        }
        return answer;
    }
};