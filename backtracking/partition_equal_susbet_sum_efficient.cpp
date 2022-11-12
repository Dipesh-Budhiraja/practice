//{ Driver Code Starts
// Initial Template for C++

#include "header.h"
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    bool solve(int arr[], int n, int target, int index, vector<vector<int>> &dp) {
        // base case
        if (target < 0) {
            return false;
        }
        
        if (target == 0) {
            return true;
        }
        
        if (index >= n) {
            return false;
        }
        
        if (dp[target][index] != -1) {
            return dp[target][index];
        }
        
        bool putIntoTarget = solve(arr, n, target - arr[index], index+1, dp);
        bool dontPutIntoTarget = solve(arr, n, target, index+1, dp);
        
        return dp[target][index] = putIntoTarget or dontPutIntoTarget;
        
    }
    
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for (int i=0; i<N; i++) {
            sum += arr[i];
        }
        
        if (sum%2==1) {
            return 0;
        }
        
        int target = sum/2;
        vector<vector<int>> dp(target+1, vector<int>(N+1, -1));
        return solve(arr, N, target, 0, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends