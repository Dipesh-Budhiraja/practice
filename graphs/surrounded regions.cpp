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

    void dfs(vector<vector<char>>& board, int r, int c, vector<vector<bool>> &visited, vector<vector<bool>> &canBeFlipped) {
        canBeFlipped[r][c] = false;
        visited[r][c] = true;
        for (int k = 0; k < 4; k++) {
            int rnew = r + x[k];
            int cnew = c + y[k];
            if (isInside(rnew, cnew, ROWS, COLS) && !visited[rnew][cnew] && board[rnew][cnew] == 'O'){
                dfs(board, rnew, cnew, visited, canBeFlipped);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        ROWS = board.size();
        COLS = board[0].size();
        vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> canBeFlipped(ROWS, vector<bool>(COLS, true));

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (board[r][c] == 'X') {
                    canBeFlipped[r][c] = false;
                }
            }
        }

        for (int r = 0; r < ROWS; r++) {
            // visit 0th col
            if (board[r][0] == 'O') {
                dfs(board, r, 0, visited, canBeFlipped);
            }
            // visit last col
            if (board[r][COLS-1] == 'O') {
                dfs(board, r, COLS-1, visited, canBeFlipped);
            }
        }

        for (int c = 0; c < COLS; c++) {
            // visit 0th row
            if (board[0][c] == 'O') {
                dfs(board, 0, c, visited, canBeFlipped);
            }
            // visit last row
            if (board[ROWS-1][c] == 'O') {
                dfs(board, ROWS-1, c, visited, canBeFlipped);
            }
        }

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (canBeFlipped[r][c]) {
                    board[r][c] = 'X';
                }
            }
        }
    }
};