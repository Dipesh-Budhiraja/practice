#include "header.h"

class Solution {
public:
    int ROWS = 0; 
    int COLS = 0;

    static bool isInside(int xnew, int ynew, int m, int n) {
        if (xnew < 0 || ynew < 0 || xnew >= m || ynew >= n) {
            return false;
        }
        return true;
    }
	    
    const int x[4] = {-1,1,0,0};
    const int y[4] = {0,0,1,-1};
        

    void dfs(vector<vector<int>>& heights, int r, int c, vector<vector<bool>> &visited) {
        visited[r][c] = true;

        for (int k = 0; k < 4; k++) {
	            int rnew = r + x[k];
	            int cnew = c + y[k];
	            if (isInside(rnew, cnew, ROWS, COLS) && !visited[rnew][cnew] && heights[rnew][cnew] >= heights[r][c]) {
	                dfs(heights, rnew, cnew, visited);
	            }
        }

    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        ROWS = heights.size();
        COLS = heights[0].size();
        vector<vector<bool>> pac(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atl(ROWS, vector<bool>(COLS, false));

        for (int c = 0; c < COLS; c++) {
            // FIRST ROW
            dfs(heights, 0, c, pac);
            // LAST ROW
            dfs(heights, ROWS - 1, c, atl);
        }

        for (int r = 0; r < ROWS; r++) {
            // FIRST COL
            dfs(heights, r, 0, pac);
            // LAST COL
            dfs(heights, r, COLS - 1, atl);
        }


        vector<vector<int>> res;
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (pac[r][c] && atl[r][c]) {
                    res.push_back(vector<int>({r,c}));
                }
            }
        }

        return res;
    }
};