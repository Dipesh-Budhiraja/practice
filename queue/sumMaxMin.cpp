#include "header.h"
using namespace std;

int solve(int *arr, int n, int k) {
    deque<int> maxi;
    deque<int> mini;

    //first window - populate first k elements in decrasing order
    for(int i=0; i <k; i++) {
        while(!maxi.empty() && arr[maxi.back()] <= arr[i]) {
            maxi.pop_back();
        }

        while(!mini.empty() && arr[mini.back()] >= arr[i]) {
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);
    }

    int ans = 0;
    for(int i=k; i<n; i++) {
        ans += arr[maxi.front()] + arr[mini.front()];
        //next window

        // removal
        while(!maxi.empty() && i - maxi.front() >= k) {
            maxi.pop_front();
        }

        while(!mini.empty() && i - mini.front() >= k) {
            mini.pop_front();
        }

        // addition
        while(!maxi.empty() && arr[maxi.back()] <= arr[i]) {
            maxi.pop_back();
        }

        while(!mini.empty() && arr[mini.back()] >= arr[i]) {
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);
    }

    // calculate for last window
    ans += arr[maxi.front()] + arr[mini.front()];
    return ans;
}

int main() {
    int arr[7]  = {2, 5, -1, 7, -3, -1, -2};

    cout << solve(arr, 7, 4);
    return 0;
}