#include "header.h"
using namespace std;

class NStack
{
private:
    int *arr;
    int *top;
    int *next;
    
    int n, s;
    int freespot;
    
public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        // Write your code here.
        n = N;
        s = S;
        
        arr = new int[s];
        next = new int[s];
        top = new int[n];
        
        // initialise top
        for(int i=0; i<n; i++) {
            top[i] = -1;
        }
        
        // initialise next
        for (int i = 0; i < s; i++) {
            next[i] = i+1;
        }
        // set last to -1
        next[s-1] = -1;
        
        // intialise freespot
        freespot = 0;
        
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // check for overflow
        if (freespot == -1) {
            return false;
        }
        
        // find index
        int index = freespot;
        
        //update freespot
        freespot = next[index];
        
        //store element
        arr[index] = x;
        
        //update next - point to previous element
        next[index] = top[m-1];
        
        //update top
        top[m-1] = index;
        
        return true;
        
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // check underflow
        if (top[m-1] == -1) {
            return -1;
        }
        
        // find index
        int index = top[m-1];
        
        
        // update top
        top[m-1] = next[index];
        
        // update next
        next[index] = freespot;
        
        // update freespot
        freespot = index;
        
        return arr[index];
    }
};