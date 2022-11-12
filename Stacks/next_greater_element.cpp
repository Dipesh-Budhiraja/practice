//{ Driver Code Starts
#include "header.h"
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        
        vector<long long> ans;
        stack<long long> s;
        long long curMax = -1;
        
        for (int i = n - 1; i>=0; i--) {
            if (arr[i] > curMax) {
                curMax = arr[i];
                ans.push_back(-1);
                s.push(arr[i]);
            } else {
                
                while (!s.empty() && arr[i] >= s.top()) {
                    s.pop();
                }
                if (s.empty()) {
                    ans.push_back(-1);
                } else {
                    ans.push_back(s.top());    
                }
                s.push(arr[i]);
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
