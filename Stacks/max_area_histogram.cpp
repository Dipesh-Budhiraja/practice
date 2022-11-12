#include "header.h"
using namespace  std;



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