//{ Driver Code Starts
#include "header.h"
using namespace std;

// } Driver Code Ends
class Solution {
public:
	vector<vector<int>> ShortestDistance(vector<vector<int>>&matrix){
	   // Code here
	   int m = matrix.size();
	   int n = matrix[0].size();
	   vector<vector<int> > ans(m, vector<int> (n, 0));
	   
	   if (!ratMaze(matrix, ans, 0, 0, m, n)) {
	       return {{-1}};
	   }
	   
	   return ans;
	}
	
	bool ratMaze(vector<vector<int>>&matrix, vector<vector<int> > &ans, int i, int j, int m, int n) {
        if (i==m-1 && j==n-1) {
            ans[i][j] = 1;
            return true;
        }
        
        
        if(canGo(i,j,m,n,matrix)) {
            ans[i][j] = 1;
            
            for(int noOfPos = 1; noOfPos <= matrix[i][j]; noOfPos++) {
                if (ratMaze(matrix, ans, i, j+noOfPos, m, n)) return true;
                if (ratMaze(matrix, ans, i+noOfPos, j, m, n)) return true;
            }
            
            ans[i][j] = 0;
        }
        return false;
	}
	
	bool canGo(int i, int j, int m, int n, vector<vector<int>>&matrix) {
	    if (i>=0 && i<m && j>=0 && j<n && matrix[i][j] != 0) {
	        return true;
	    }
	    return false;
	}
	
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.ShortestDistance(matrix);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends