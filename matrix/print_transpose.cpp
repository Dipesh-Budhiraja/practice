#include<iostream>
using namespace std;

void print_transpose(int **arr, int n) {
    for (int i=0; i <n; i++) {
        for(int j=i+1; j<n; j++) {
            int temp = arr[j][i];
            arr[j][i] = arr[i][j];
            arr[i][j] = temp;
        }
    }

    for (int i=0; i <n; i++) {
        for(int j=0; j<n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    int *arr[n];
    for(int i=0; i<n; i++) {
        arr[i] = new int[n];
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }

    print_transpose(arr, n);


    return 0;
}   