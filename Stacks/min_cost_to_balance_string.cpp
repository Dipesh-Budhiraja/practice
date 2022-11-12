#include "header.h"
using namespace std;

int findMinimumCost(string str) {
  // Write your code here
    
    if (str.length()%2 == 1) {
        return -1;
    }
    
    stack<char> s;
    
    for (int i=0; i < str.length(); i++) {
        if (str[i] == '{') {
            s.push(str[i]);
        } else {
            if (!s.empty() && s.top() == '{') {
                s.pop();
            } else {
                s.push(str[i]);
            }
        }
    }
    
    // invalid string will be left
    int a=0, b=0;
    while(s.empty() == false) {
        if (s.top() == '{') {
            a++;
        } else {
            b++;
        }
        s.pop();
    }
    
    int ans = (a+1)/2 + (b+1)/2;
    return ans;
}