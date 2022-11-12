//{ Driver Code Starts
//Initial template for C++

#include "header.h"
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int> s;
        
        for (int i = 0; i<n; i++) {
            s.push(i);
        }
        
        
        while(s.empty() == false && s.size() != 1) {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            
            if (M[a][b] == 1) {
                s.push(b);
            } else if (M[b][a] == 1) {
                s.push(a);
            }
        }
        
        int candidate = s.top();
        
        // validate rows - candidate knows no one
        for (int i = 0; i<n; i++) {
            if (M[candidate][i] != 0) {
                return -1;
            }
        }
        
        // validate columns - everyone knows candidate
        for (int i = 0; i<n; i++) {
            if (i!=candidate && M[i][candidate] != 1) {
                return -1;
            }
        }
        
        return candidate;
        
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
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends