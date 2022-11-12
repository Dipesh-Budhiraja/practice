#include<iostream>
using namespace std;

void printAllSubsets(string s, string ans, int i, int len) {
    if(i == len) {
        cout << ans << endl;
        return;
    }

    // cout << ans << endl;
    printAllSubsets(s, ans, i+1, len);
    printAllSubsets(s, ans+s[i], i+1, len);
}


int main() {

    string s = "abc";
    string ans = "";

    printAllSubsets(s, ans, 0, s.length());

    return 0;
}