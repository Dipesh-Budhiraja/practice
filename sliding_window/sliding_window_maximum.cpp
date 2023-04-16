#include "header.h"

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        for (int i = 0; i < k; i++) {
            while (dq.empty() == false && dq.back() < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(nums[i]);
        }

        for(int i = k; i < nums.size(); i++) {
            ans.push_back(dq.front());

            while (dq.empty() == false && dq.back() < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(nums[i]);

            if (dq.front() == nums[i-k]) {
                dq.pop_front();
            }
        }
        ans.push_back(dq.front());

        return ans;
    }
};