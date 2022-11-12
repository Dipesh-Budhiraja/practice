#include "header.h"
using namespace std;

class Solution {
public:
    
    int xcom[4] = {-1, 0, 1, 0};
    int ycom[4] = {0, -1, 0, 1};
    
    bool isInside(int i, int j, int m, int n) {
        if (i >= 0 && i < m && j >= 0 && j < n) {
            return true;
        }
        return false;
    }
    
    void dfs(vector<vector<int> >& grid, vector<vector<bool> > &visited, int m, int n,
            int i, int j, int ei, int ej, int curCountof0, int &count0, int &ans) {
        // base case
        if (i == ei && j == ej && curCountof0 == count0) {
            ans++;
        }
        
        if (!isInside(i,j,m,n)) {
            return;
        }
        
        for (int k = 0; k < 4; k++) {
            int newi = i + xcom[k];
            int newj = j + ycom[k];
            
            if (isInside(newi,newj,m,n) && visited[newi][newj] == false && 
                (grid[newi][newj] == 0 || grid[newi][newj] == 2)) {
                visited[newi][newj] = true;
                if (grid[newi][newj] == 0) {
                    curCountof0++;
                }
                dfs(grid, visited, m, n, newi, newj, ei, ej, curCountof0, count0,  ans);
                if (grid[newi][newj] == 0) {
                    curCountof0--;
                }
                visited[newi][newj] = false;
            }
        }
    }
    
    int uniquePathsIII(vector<vector<int> >& grid) {
        int m  = grid.size();
        int n = grid[0].size();
        int count0 = 0;
        int si, sj, ei, ej;
        
        for (int i=0; i < m; i++) {
            for (int j=0; j < n; j++) {
                if (grid[i][j] == 0) {
                    count0++;
                } else if (grid[i][j] == 1) {
                    si = i;
                    sj = j;
                } else if (grid[i][j] == 2) {
                    ei = i;
                    ej = j;
                }
            }
        }
        
        int ans = 0;
        int curCountof0 = 0;
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        visited[si][sj] = true;
        dfs(grid, visited, m, n, si, sj, ei, ej, curCountof0, count0,  ans);
        
        return ans;
        
    }
};