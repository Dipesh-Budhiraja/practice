#include<iostream>
using namespace std;

void toh(int n, char source, char helper, char dest) {
    if(n==0) {
        return;
    }
    if(n == 1) {
        cout << "Move disc " << n << " from " << source << " -> " << dest << endl; 
        return;
    }
    // if (n == 2) {
    //     cout << "Move disc " << n-1 << " from " << source << " -> " << helper << endl;
    //     cout << "Move disc " << n << " from " << source << " -> " << dest << endl;
    //     cout << "Move disc " << n-1 << " from " << helper << " -> " << dest << endl;
    //     return;
    // }

    toh(n-1, source, dest, helper);
    cout << "Move disc " << n << " from " << source << " -> " << dest << endl;
    toh(n-1, helper, source, dest);

}   


int main() {
    
    int n;
    cin >> n;

    toh(n, 'A', 'B', 'C');


    return 0;
}