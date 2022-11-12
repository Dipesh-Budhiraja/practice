#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int count_digits(int num) {
    if(num != 0) {
        return count_digits(num/10) + 1;
    }
    return 0;
}

bool isPalindrome(int n) {
    bool ans = true;
    stack<int> s;

    int digits = count_digits(n);

    for(int i=1; i <= digits/2; i++) {
        int last_digit = n%10;
        s.push(last_digit);
        n=n/10;
    }

    if (digits%2 != 0)
    {
        n = n/10;
    }

    while(n != 0) {
        int last_digit = n%10;
        if(s.top() != last_digit) {
            ans = false;
            break;
        }
        s.pop();
        n = n/10;
    }

    return ans;
 }


int reverse_number(int n) {
    int rev_num = 0;

    while(n != 0) {
        int last_digit = n%10;
        rev_num = rev_num*10 + last_digit;
        n /= 10;
    }

    return rev_num;
}

int main() {

    int n = 0;
    cin >> n;

    // using stack
    // cout << isPalindrome(n) << endl;

    //by reversing the number and comparing to original

    int rev_num = reverse_number(n);
    if(rev_num == n) {
        cout << true;
    } else {
        cout << false;
    }

    return 0;
}