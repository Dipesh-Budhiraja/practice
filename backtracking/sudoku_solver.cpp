//{ Driver Code Starts
#include "header.h"
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    bool isFull(int grid[N][N]) {
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if (grid[i][j] == 0) {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    void checkPossibleNums(int grid[N][N], int vi, int vj, bool *numcame) {
        // check row
        for (int i=0; i<N; i++) {
            if (grid[vi][i] != 0) {
                numcame[grid[vi][i]] = true;
            }
        }
        
        // check column
        for (int i=0; i<N; i++) {
            if (grid[i][vj] != 0) {
                numcame[grid[i][vj]] = true;
            }
        }
        
        // check 3x3 box
        int r = (vi/3)*3;
        int c = (vj/3)*3;
        
        for (int i=r; i < r+3; i++) {
            for (int j=c; j < c+3; j++) {
                if (grid[i][j] != 0) {
                    numcame[grid[i][j]] = true;
                }
            }
        }
    }
    
    public:
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
    { 
        if (isFull(grid)) {
            return true;
        }
        
        // find vacany
        int vi, vj;
        bool flag = false;
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if (grid[i][j] == 0) {
                    vi = i;
                    vj = j;
                    flag = true;
                    break;
                }
            }
            if (flag) {
                break;
            }
        }
        
        bool numcame[10] = {false};
        checkPossibleNums(grid, vi, vj, numcame);
        
        for (int i=1; i<=9; i++) {
            if (numcame[i] == false) {
                grid[vi][vj] = i;
                
                if (SolveSudoku(grid)) {
                    return true;
                }
                
                // backtrack changes
                grid[vi][vj] = 0;
            }
        }
        return false;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                cout << grid[i][j] << " ";
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends