//{ Driver Code Starts
#include "header.h"
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
    private:
    vector<int> prevSmallerElement(vector<int> arr, int n) {
        vector<int> ans(n);
        stack<int> s;
        s.push(-1);
        
        for(int i=0; i<n; i++) {
             int cur = arr[i];
             
             while((s.top() != -1) && (arr[s.top()] >= cur)) {
                 s.pop();
             }
             
             ans[i] = s.top();
             s.push(i);
         }
        return ans;
    }
    vector<int> nextSmallerElement(vector<int> arr, int n) {
        vector<int> ans(n);
        stack<int> s;
        s.push(-1);
        
        for(int i=n-1; i>=0; i--) {
             int cur = arr[i];
             
             while((s.top() != -1) && (arr[s.top()] >= cur)) {
                 s.pop();
             }
             
             ans[i] = s.top();
             s.push(i);
         }
        
        return ans;
    }
    
    int largestRectangle(vector < int > & heights) {
       // Write your code here.
         
         int n = heights.size();
         vector<int> prev(n);
         vector<int> next(n);
        
        prev = prevSmallerElement(heights, n);
        next = nextSmallerElement(heights, n);     
         
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int length = heights[i];
            if(next[i] == -1) {
                next[i] = n;
            }
            int breadth = next[i] - prev[i] - 1;
            int curArea = heights[i] * breadth;
            maxArea = max(maxArea, curArea);
        }
         
        return maxArea;
     }

    
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        vector<vector<int> > heights(n);
        for(int i=0; i<n; i++) {
            // vector<int> tmp(m,0);
            heights[i] = vector<int>(m);
        }
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (i == 0) {
                    heights[i][j] = M[i][j];
                } else {
                    if (M[i][j] == 0) {
                        heights[i][j] = 0;
                    } else {
                        heights[i][j] = heights[i-1][j] + 1;
                    }
                }
            }
        }
        
        int ans = 0;
        for (int i = 0; i<n; i++) {
            int curans = largestRectangle(heights[i]);
            ans = max(ans, curans);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends