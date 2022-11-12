#include "header.h"
using namespace std;

class Solution {
public:
    int xdir[4] = {-1, 1, 0, 0};
    int ydir[4] = {0, 0, -1, 1};
    
    
    bool isInside(int i, int j, int m, int n) {
        if (i>=0 && i<m && j>=0 && j<n) {
            return true;
        }
        return false;
    }
    
    bool solve(vector<vector<char>>& board, string word, int len, int m, int n, 
               vector<vector<bool>> &visited, int index, int i, int j) {
        if (index == len) {
            return true;
        }
        
        
        for (int k = 0; k < 4; k++) {
            int newi = i + xdir[k];
            int newj = j + ydir[k];
            
            if (isInside(newi, newj, m, n) && !visited[newi][newj] && board[newi][newj] == word[index]) {
                visited[newi][newj] = true;
                if (solve(board, word, len, m, n, visited, index+1, newi, newj)) {
                    return true;
                }
                visited[newi][newj] = false;
            }
        }
        
        return false;
        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    visited[i][j] = true;
                    if (solve(board, word, word.length(), m, n, visited, 1, i, j)) {
                        return true;
                    }
                    visited[i][j] = false;
                }
            }
        }
        
        return false;
    }
};