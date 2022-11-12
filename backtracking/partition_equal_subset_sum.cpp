//{ Driver Code Starts
// Initial Template for C++

#include "header.h"
using namespace std;

// } Driver Code Ends
// User function Template for C++

#define SIZE 1000

class Solution{
public:
    bool ***dp;
    bool ***seen;
    
    Solution() {
        dp = new bool**[SIZE];
        seen = new bool**[SIZE];
        for (int i = 0; i<SIZE; i++) {
            dp[i] = new bool*[SIZE];
            seen[i] = new bool*[SIZE];
            for (int j = 0; j < 101; j++) {
                dp[i][j] = new bool[101];
                seen[i][j] = new bool[101];
            }
        }
    }

    bool solve(int arr[], int n, int s1, int s2, int index) {
        // base case
        if (s1 == s2 && index == n) {
            seen[s1][s2][index] = true;
            return dp[s1][s2][index] = true;
        }
        
        if (index == n && s1 != s2) {
            seen[s1][s2][index] = true;
            return dp[s1][s2][index] = false;
        }
        
        if (seen[s1][s2][index]) {
            return dp[s1][s2][index];
        }
        
        seen[s1][s2][index] = true;
        
        bool putIntos1 = solve(arr, n, s1+arr[index], s2, index+1);
        if (putIntos1) {
            return dp[s1][s2][index] = true;
        }
        
        bool putIntos2 = solve(arr, n, s1, s2+arr[index], index+1);
        if (putIntos2) {
            return dp[s1][s2][index] = true;
        }
        
        return dp[s1][s2][index] = false;
        
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
        
        int s1 = 0, s2 = 0;
        return solve(arr, N, s1, s2, 0);
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