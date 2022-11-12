//{ Driver Code Starts
#include "header.h"
#include <numeric>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    bool isKPartitionPossible(int a[], int n, int k)
    {
         //Your code here
         vector<int> nums(a, a+n);
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum%k != 0) {
            return false;
        }
        int target = sum/k;
        vector<bool> used(nums.size(), false);
        
        return backtrack(nums, k, 0, used, 0, target);
    }
    
    bool backtrack(vector<int>& nums, int k, int i, vector<bool> &used, int subsetSum, int target) {
        if (k == 0) {
            return true;
        }
        
        if (subsetSum == target) {
            return backtrack(nums, k-1, 0, used, 0, target);
        }
        
        for (int j = i; j < nums.size(); j++) {
            if (used[j] == true || subsetSum + nums[j] > target) {
                continue;
            }
            
            used[j] = true;
            if (backtrack(nums, k, j+1, used, subsetSum + nums[j], target)) {
                return true;
            }
            used[j] = false;
        }
        
        return false;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}
// } Driver Code Ends