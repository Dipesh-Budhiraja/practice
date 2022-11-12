//{ Driver Code Starts
#include "header.h"
using namespace std;


// } Driver Code Ends


class Solution
{
    void solve(string str, int k, int n, string &ans, int i) {
        if ( k == 0) {
            return;
        }
        
        char maxChar = str[i];
        for (int j = i+1; j < n; j++) {
            if (str[j] > maxChar) {
                maxChar = str[j];
            }
        }
        
        if (maxChar != str[i]) {
            k--;
        }
        
        for (int j = n-1; j >= i; j--) {
            if (str[j] == maxChar) {
                swap(str[j], str[i]);
                
                if (str > ans) {
                    ans = str;
                }
                
                solve(str, k, n, ans, i+1);
                swap(str[j], str[i]);
            }
        }
    }
    
    public:
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
       // code here.
       string ans = str;
       int n = str.length();
       solve(str, k, n, ans, 0);
       return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}

// } Driver Code Ends