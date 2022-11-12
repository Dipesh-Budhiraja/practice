//{ Driver Code Starts
//Initial Template for C++

#include "header.h""
using namespace std;
queue<int> rev(queue<int> q);
int main()
{
    int test;
    cin>>test; 
    while(test--)
    {
    queue<int> q; 
    int n, var; 
    cin>>n; 
    while(n--)
    {
        cin>>var; 
        q.push(var);
    }
    queue<int> a=rev(q); 
    while(!a.empty())
    {
        cout<<a.front()<<" ";
        a.pop();
    }
    cout<<endl; 
    }
}
// } Driver Code Ends


//function Template for C++


void reverse(queue<int> &q) {
    if (q.empty()) {
        return;
    }
    
    int cur = q.front();
    q.pop();
    reverse(q);
    
    q.push(cur);
}

//Function to reverse the queue.
queue<int> rev(queue<int> q)
{
    // add code here.
    stack<int> s;
    
    while(q.empty() == false) {
        s.push(q.front());
        q.pop();
    }
    
    while(s.empty() == false) {
        q.push(s.top());
        s.pop();
    }
    
    return q;
    
    
    /* reverse(q);
    
    return q; */
}