#include "header.h"

class Solution {
public:
    int find_pivot(vector<int>& nums, int l, int r) {
        if (l > r) {
            return -1;
        } 

        if (nums.size() == 1) {
            return -1;
        }

        int mid = (l + r)/2;
        if (nums[mid] > nums[mid+1] ) {
            return mid;
        } else if (mid-1 >= 0 && nums[mid - 1] > nums[mid]) {
            return mid - 1;
        } else if (nums[mid] > nums[r]) {
            return find_pivot(nums, mid + 1, r);
        } else {
            return find_pivot(nums, l, mid - 1);
        }

        return -1;
    }

    int bs(vector<int>& nums, int l, int r, int target) {

        while (l <= r) {
            int mid = (l + r)/2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int pivot = find_pivot(nums, l, r);
        cout << "pivot: " << pivot << endl;
        if (pivot == -1) {
            return bs(nums, l, r, target);
        } 
        // find in left
        int leftans = bs(nums, l, pivot, target);
        if (leftans != -1) {
            return leftans;
        }
        int rightans = bs(nums, pivot + 1, r, target);
        if (rightans != -1) {
            return rightans;
        }
        return -1;

    }
};