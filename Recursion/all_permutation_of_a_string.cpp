#include<iostream>
using namespace std;

void print_all_permutations(string s, int len, int start) {
    if(start == len) {
        cout << s << endl;
        return;
    }

    
    for(int i = start; i < len; i++) {
        // swap s[start], s[i]
        swap(s[start], s[i]);
        print_all_permutations(s, len, start+1);
        swap(s[start], s[i]);
    }
}

int main() {

    string s;
    cin >> s;

    int len = s.length();

    print_all_permutations(s, len, 0);

    return 0;
}