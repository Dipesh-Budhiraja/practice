#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int *arr[n], *temp[n];
    for(int i=0; i<n; i++) {
        arr[i] = new int[n];
        temp[i] = new int[n];
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
            temp[i][j] = 0;
        }
    }

    for (int i=0; i <n; i++) {
        for(int j=0; j<n; j++) {
            temp[i][j] = arr[j][n-1 - i];
        }
    }

    for (int i=0; i <n; i++) {
        for(int j=0; j<n; j++) {
            arr[i][j] = temp[i][j];
        }
    }

    for (int i=0; i <n; i++) {
        for(int j=0; j<n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}   