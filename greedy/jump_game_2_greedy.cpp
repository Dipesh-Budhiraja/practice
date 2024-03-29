#include "header.h"

class Solution {
public:

    int jump(vector<int>& nums) {
        int res = 0;
        int l = 0;
        int r = 0;
        int n = nums.size();

        while (r < n - 1) { // means right pointer not reached right most point so jumps to he done
            int farthest = 0;
            for (int i = l; i <= r; i++) {
                farthest = max(farthest, i + nums[i]);
            }
            l = r + 1;
            r = farthest;
            res++;
        }
        return res;
    }
};