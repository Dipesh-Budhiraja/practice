#include "header.h"

class Solution {
public:

    int bs(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while(l <= r) {
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


    int leftBS(vector<int>& nums, int target, int l, int r) {
        if (l > r) {
            return -1;
        }

        int mid = (l + r)/2;
        if (nums[mid] == target) {
            int leftMeKuchMila = leftBS(nums, target, l, mid - 1);
            if (leftMeKuchMila == -1) {
                return mid;
            }
            return leftMeKuchMila;
        } else if (nums[mid] < target) {
            return leftBS(nums, target, mid + 1, r);
        }
        return -1;
    }

    int rightBS(vector<int>& nums, int target, int l, int r) {
        if (l > r) {
            return -1;
        }

        int mid = (l + r)/2;
        if (nums[mid] == target) {
            int rightMeKuchMila = rightBS(nums, target, mid + 1, r);
            if (rightMeKuchMila == -1) {
                return mid;
            }
            return rightMeKuchMila;
        } else if (nums[mid] > target) {
            return rightBS(nums, target, l, mid - 1);
        }
        return -1;
    }


    vector<int> searchRange(vector<int>& nums, int target) {
        int midIndex = bs(nums, target);

        if (midIndex == -1) {
            return vector<int>({-1, -1});
        }

        int leftOcc = leftBS(nums, target, 0, midIndex - 1);
        int rightOcc = rightBS(nums, target, midIndex + 1, nums.size() - 1);


        vector<int> ans;
        if (leftOcc == -1) {
            ans.push_back(midIndex);
        } else {
            ans.push_back(leftOcc);
        }

        if (rightOcc == -1) {
            ans.push_back(midIndex);
        } else {
            ans.push_back(rightOcc);
        }
        return ans;
    }
};