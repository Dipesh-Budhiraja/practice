//{ Driver Code Starts
#include "header.h"
using namespace std;


// } Driver Code Ends
class Solution{
public:

    bool isAllowed(bool graph[101][101], int n, int curColor, int index, vector<int> &color) {
        for(int i = 0; i < n; i++) {
            if (graph[index][i] == 1 && color[i] == curColor) {
                return false;
            }
        }
        
        return true;
    }
    
    bool solve(bool graph[101][101], int m, int n, int index, vector<int> &color) {
        if (index == n) {
            return true;
        }
        
        for(int curColor=0; curColor<m; curColor++) {
            if (isAllowed(graph, n, curColor, index, color)) {
                color[index] = curColor;
                
                if (solve(graph, m, n, index+1, color)){
                    return true;
                }
                
                
                // backtrack
                color[index] = -1;
            }
        }
        
        return false;
    }

    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        
        vector<int> color(n, -1);
        
        return solve(graph, m, n, 0, color);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends