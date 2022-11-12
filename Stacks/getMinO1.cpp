#include <stack>
#include <limits.h>
using namespace std;

class SpecialStack {
    // Define the data members.
    stack<int> s;
    int mini = INT_MAX;
    
    
    /*----------------- Public Functions of SpecialStack -----------------*/
    public:
        
    void push(int data) {
        // Implement the push() function.
        if (s.empty()) {
            s.push(data);
            mini = data;
        } else {
            if (data < mini) {
                int val = 2*data - mini;
                s.push(val);
                mini = data;
            } else {
                s.push(data);
            }
        }
    }

    int pop() {
        // Implement the pop() function.
        if (s.empty()) {
            return -1;
        }
        
        int curr = s.top();
        s.pop();
        
        if (curr > mini) {
            return curr ;
        } else {
            int prevMin = mini;
            int val = 2*mini - curr;
            mini = val;
            return prevMin;
        }
    }

    int top() {
        // Implement the top() function.
        if (s.empty()) {
            return -1;
        }
        
        if (s.top() > mini) {
            return s.top();
        } else {
            return mini;
        }
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return s.empty();
    }

    int getMin() {
        // Implement the getMin() function.
        if (s.empty()) {
            return -1;
        }
        return mini;
    }  
};