#include "header.h"

class Solution {
public:

    int bs(vector<int>& nums, int target, int l, int r) {
        if (l > r) {
            return -1;
        }

        int mid = (l + r)/2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            int temp = bs(nums, target, l, mid-1);
            if (temp == -1) {
                return mid;
            }
            return temp;
        } else {
            int temp = bs(nums, target, mid+1, r);
            if (temp == -1) {
                return mid + 1;
            }
            return temp;
        }

        return -1;

    }

    int searchInsert(vector<int>& nums, int target) {
        
        return bs(nums, target, 0, nums.size() - 1);

    }
};