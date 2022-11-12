#include "header.h"
using namespace std;

class Solution {
public:
    void permute(vector<int> &nums, int index, int n, set<vector<int>> &mySet) {
        if (index == n) {
            mySet.insert(nums);
            return;
        }
        
        for (int i = index; i < n; i++) {
            swap(nums[index], nums[i]);
            permute(nums, index+1, n, mySet);
            swap(nums[index], nums[i]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> mySet;
        int n = nums.size();
        permute(nums, 0, n, mySet);

        for (auto it: mySet) {
            ans.push_back(it);
        }

        return ans;
    }
};