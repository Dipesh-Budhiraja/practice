//{ Driver Code Starts
//Initial template for C++

#include "header.h"
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
    
    vector<vector<int> > ans;
    void solve(vector<int> &A, int n, int B, vector<int> curans, int index) {
        if (B == 0) {
            // sort(curans.begin(), curans.end());
            ans.push_back(curans);
            return;
        }
        
        if (index == n) {
            return;
        }
        
        for (int i=index; i<n && B - A[i] >= 0 ; i++) {
            if (B - A[i] >= 0) {
                curans.push_back(A[i]);
                solve(A, n, B-A[i], curans, i);
                curans.pop_back();
            }
        }
    }
    
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        vector<int> curans;
        
        // remove duplicates
        set<int> s( A.begin(), A.end() );
        A.assign( s.begin(), s.end() );
        
        // sort
        sort(A.begin(), A.end());
        int n = A.size();
    
        solve(A, n, B, curans, 0);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends