//{ Driver Code Starts
// Initial Template for C++

#include "header.h"
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    
    bool isValidPlace(vector<vector<bool> > &board, int row, int col, int n) {
        // LTD
        for (int i=row-1, j=col-1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == true) {
                return false;
            }
        }
        
        // T
        for(int i = row-1; i >= 0; i--) {
            if (board[i][col] == true) {
                return false;
            }
        }
        
        // RTD
        for (int i=row-1, j=col+1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == true) {
                return false;
            }
        }
        
        return true;
    }
    
    void solve(vector<vector<bool> > &board, int row, int &n, vector<int> &curans, vector<vector<int> > &ans) {
        if (row == n) {
            // store solution
            ans.push_back(curans);
        }
        
        for (int col = 0; col < n; col++) {
            if(isValidPlace(board, row, col, n)) {
                curans.push_back(col+1);
                board[row][col] = true;
                solve(board, row + 1, n, curans, ans);
                board[row][col] = false;
                curans.pop_back();
            }
        }
    }
    
public:
    vector<vector<int>> nQueen(int n) {
        // code here
        
        vector<vector<bool> > board(n, vector<bool>(n, false));
        
        vector<vector<int> > ans;
        vector<int> curans;
        solve(board, 0, n, curans, ans);
        
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
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends