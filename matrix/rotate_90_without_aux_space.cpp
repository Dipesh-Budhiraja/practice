#include<iostream>
using namespace std;

void transpose(int **arr, int n) {
    for (int i=0; i <n; i++) {
        for(int j=i+1; j<n; j++) {
            int temp = arr[j][i];
            arr[j][i] = arr[i][j];
            arr[i][j] = temp;
        }
    }
}

void reverse_columns(int **arr, int n) {
    for (int i=0; i <n; i++) {
        for(int j=0; j<n/2; j++) {
            int temp = arr[j][i];
            arr[j][i] = arr[n-1 - j][i];
            arr[n-1 - j][i] = temp;
        }
    }
}

void print_matrix(int **arr,  int n) {
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

    transpose(arr, n);
    reverse_columns(arr, n);
    print_matrix(arr, n);

    return 0;
}   