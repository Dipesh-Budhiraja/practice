#include "header.h"
using namespace std;

int main() {
    
    stack<int> s;
    s.push(11); s.push(22); s.push(33); s.push(44); s.push(55); s.push(66);

    int midElePos = s.size()/2;

    stack<int> tmp;

    int count = 0;
    while (count < midElePos) {
        tmp.push(s.top());
        s.pop();
        count++;
    }

    s.pop();

    while(tmp.empty() == false) {
        s.push(tmp.top());
        tmp.pop();
    }

    // print
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}
