#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int fact(int n) {
    if(n == 0 || n == 1) {
        return 1;
    }
    return n * fact(n-1);
}

int main() {

    int n = 0;
    cin >> n;

    // recursive
    // int f = fact(n);


    // iterative
    int f = 1;

    for(int i=2; i <= n; i++) {
        f = f*i;
    }

    cout << f << endl;

    return 0;
}