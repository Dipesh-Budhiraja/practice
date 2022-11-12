#include <iostream>
#include <stack>
#include <cmath>
using namespace std;


int main() {

    int n = 0;
    cin >> n;

    int ans = 0;

    // int to_divide = 5;

    // while(1) {
    //     if (n / to_divide != 0) {
    //         ans += n/to_divide;
    //         to_divide = to_divide*5;
    //     } else {
    //         break;
    //     }
    // }

    for (int i = 5; i <= n; i *= 5) {
        ans = ans + n/i;
    }

    cout << ans;

    return 0;
}