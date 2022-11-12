#include<iostream>
using namespace std;


int rope_cut(int n, int a, int b, int c) {
    if(n == 0) {
        return 0;
    }

    if(n < a && n < b && n < c) {
        return -1;
    }

    int cur_max = -1;
    if(n >= a) {
        int sol = -1;
        int returned_val = rope_cut(n-a, a, b, c);
        if(returned_val != -1){
            sol = 1 + returned_val; 
        }
        cur_max = max(cur_max, sol);
    }

    if(n >= b) {
        int sol = -1;
        int returned_val = rope_cut(n-b, a, b, c);
        if(returned_val != -1){
            sol = 1 + returned_val; 
        }
        cur_max = max(cur_max, sol);
    }

    if(n >= c) {
        int sol = -1;
        int returned_val = rope_cut(n-c, a, b, c);
        if(returned_val != -1){
            sol = 1 + returned_val; 
        }
        cur_max = max(cur_max, sol);
    }

    return cur_max;

}

int main() {

    int n, a, b, c;
    cin >> n >> a >> b >> c;

    cout << rope_cut(n, a, b, c) << endl;

    return 0;
}