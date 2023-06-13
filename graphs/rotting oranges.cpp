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

    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        int fresh = 0;
        queue<pair<int, int>> q;

        int ROW = grid.size();
        int COL = grid[0].size();

        for (int r = 0; r < ROW; r++) {
            for (int c = 0; c < COL; c++) {
                if (grid[r][c] == 1) {
                    fresh++;
                } else if (grid[r][c] == 2) {
                    q.push({r, c});
                }
            }
        }

        while(!q.empty() && fresh > 0) {
            int n = q.size();

            for (int i = 0; i < n; i++) {
                pair<int, int> element = q.front();
                q.pop();

                for (int j = 0; j < 4; j++) {
                    int rnew = element.first + x[j];
                    int cnew = element.second + y[j];

                    if (isInside(rnew, cnew, ROW, COL) && grid[rnew][cnew] == 1) {
                        grid[rnew][cnew] = 2;
                        q.push({rnew, cnew});
                        fresh--;
                    }
                }
            }
            time++;
        }

        if (fresh > 0) {
            return -1;
        }
        return time;
    }
};