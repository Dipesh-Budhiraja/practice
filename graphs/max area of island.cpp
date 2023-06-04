#include "header.h"

class Solution {
public:
    static bool isInside(int xnew, int ynew, int m, int n) {
        if (xnew < 0 || ynew < 0 || xnew >= m || ynew >= n) {
            return false;
        }
        return true;
    }
    
    const int x[4] = {-1,1,0,0};
    const int y[4] = {0,0,1,-1};
    
    void trav(vector<vector<int>>& grid, int i, int j, int m, int n, vector<vector<bool>> &visited, 
            int &area) {
        area++;
        visited[i][j] = true;
        for (int k = 0; k < 4; k++) {
            int xnew = i + x[k];
            int ynew = j + y[k];
            if (isInside(xnew, ynew, m, n) && !visited[xnew][ynew] && grid[xnew][ynew] == 1) {
                trav(grid, xnew, ynew, m, n, visited, area);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false)); // set can also be used here 
        int maxarea = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    int area = 0;
                    trav(grid, i, j, m, n, visited, area);
                    maxarea = max(maxarea, area);
                }
            }
        }
        return maxarea;
    }
};