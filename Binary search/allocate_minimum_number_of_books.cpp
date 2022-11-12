#include <iostream>
using namespace std;

int allocate_min(int *arr, int n, int k, int index) {

    if (k == 1) {
        int sum = 0;
        for (int i=index; i<n;i++) {
            sum += arr[i];
        }
        return sum;
    }

    int sum = 0;
    int ans = INT_MAX;
    for (int i = index; i < n-k+1; i++)
    {
        sum += arr[i];
        ans = min(ans, max(sum, allocate_min(arr, n, k-1, i+1)) );
    }

    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }


    int ans = allocate_min(arr, n, k, 0);
    cout << ans << endl;

}