#include <iostream>
#include <cmath>
using namespace std;

int count_digits(int num) {
    if(num != 0) {
        return count_digits(num/10) + 1;
    }
    return 0;
}

int main() {

    int num = 198772;
    int digits = 0;

    // iterative approach
    /*
    while(num != 0) {
        digits++;
        num = num/10;
    }
    */

    // recursive solution
    //digits = count_digits(num);

    digits = floor(log10(num)) + 1;

    cout << digits << endl;

    return 0;
}