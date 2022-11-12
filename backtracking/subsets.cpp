#include "header.h"
using namespace std;

class Solution {
public:
    void solve(vector<int>& nums, int index, vector<int> curans, vector<vector<int> > &ans) {
        if (index == nums.size()) {
            ans.push_back(curans);
            return;
        }
        
        // not take cur element
        solve(nums, index+1, curans, ans);
        
        // take cur element
        curans.push_back(nums[index]);
        solve(nums, index+1, curans, ans);
        curans.pop_back();
        
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int> > ans;
        vector<int> curans;
        solve(nums, 0, curans, ans);
        
        return ans;
        
    }
};