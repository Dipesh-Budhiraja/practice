#include<iostream>
using namespace std;


void print_matrix(int **arr,  int n) {
    for (int i=0; i <n; i++) {
        for(int j=0; j<n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int getMatrixMedian(int *arr[], int r, int c) {
    int minEle = arr[0][0], maxEle = arr[0][c-1];
    for (int i=1; i<r; i++) {
        if (arr[i][0] < minEle) {minEle = min(arr[i][0], minEle);}
        if (arr[i][c-1] > maxEle) {maxEle = max(arr[i][c-1], maxEle);}
    }

    int medPos = (r*c+1)/2;
    while (minEle < maxEle) {
        int mid = (minEle + maxEle)/2;
        int midPos = 0;
        for(int i = 0; i < r; i++) {
            midPos += upper_bound(arr[i], arr[i]+c, mid) - arr[i];
        }

        if (midPos < medPos) {
            minEle = mid+1;
        } else {
            maxEle = mid;
        }
    }
    return minEle;
}

int main() {
    int r, c;
    cin >> r >> c;
    int *arr[r];
    for(int i=0; i<r; i++) {
        arr[i] = new int[c];
        for(int j=0; j<c; j++) {
            cin >> arr[i][j];
        }
    }

    int matMedian = getMatrixMedian(arr, r, c);
    cout << matMedian;

    
    // print_matrix(arr, n);

    return 0;
}   