//{ Driver Code Starts
// Initial template for C++

#include "header.h"
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    int xcom[4] = {-1, 0, 1, 0};
    int ycom[4] = {0, -1, 0, 1};
    
    bool isInside(int x, int y, int n) {
        if (x>=0 && x<n && y>=0 && y<n) {
            return true;
        }
        return false;
    }
    
    void solve(vector<vector<int>> &m, int n, int i, int j, 
    vector<vector<bool> > &visited, string curans, vector<string> &ans) {
        
        if (!isInside(i,j,n)) {
            return;
        }
        
        if (m[i][j] == 0) {
            return ;
        }
        
        // base case
        if (i == n-1 && j == n-1) {
            ans.push_back(curans);
            return;
        }
        
        
        
        // check for 4 directions and also check if not visited
        for (int k=0; k < 4; k++) {
            int x = i + xcom[k];
            int y = j + ycom[k];
            
            
            
            if (isInside(x,y,n) && (visited[x][y]==false) && (m[x][y] == 1)) {
                switch(k) {
                    case 0: curans += "U";
                            break;
                    case 1: curans += "L";
                            break;
                    case 2: curans += "D";
                            break;
                    case 3: curans += "R";
                            break;
                }
                visited[x][y] = true;
                solve(m, n, x, y, visited, curans, ans);
                visited[x][y] = false;
                curans.pop_back();
            }
        }
        
    }
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
        vector<string> ans;
        
        vector<vector<bool> > visited(n, vector<bool> (n, false));
        
        if (m[0][0] == 0) {
            return ans;
        }
        
        visited[0][0] = true;
        string curans = "";
        solve(m, n, 0, 0, visited, curans, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends