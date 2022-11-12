#include<iostream>
using namespace std;

void print_snake_pattern(int **arr, int m, int n) {
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (i%2 == 0) {
                cout << arr[i][j] << " ";
            } else {
                cout << arr[i][n-j-1] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int m, n;
    cin >> m >> n;
    int *arr[m];
    for(int i=0; i<m; i++) {
        arr[i] = new int[n];
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }

    print_snake_pattern(arr, m, n);


    return 0;
}   