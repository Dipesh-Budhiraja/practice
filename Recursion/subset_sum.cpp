#include<iostream>
#define N 1000
using namespace std;

int subset_sum(int arr[], int n, int sum) {
    if (sum == 0) {
        return 1;
    }

    if(n == 0) {
        return 0;
    }

    int s1 = subset_sum(arr, n-1, sum);
    int s2 = subset_sum(arr, n-1, sum-arr[n-1]);

    return s1+s2;
}


int main() {

    int arr[N], n, sum;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    cin >> sum;

    int ans = subset_sum(arr, n, sum);
    cout << ans << endl;

    return 0;
}