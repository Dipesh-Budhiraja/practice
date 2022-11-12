#include <iostream>
#include <vector>
using namespace std;

int subarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        
        int occurences = 0;
        int sum = 0;
        int start = 0, end = 0;
        
        while(end < n) {
            if (sum < k) {
                sum += arr[end];

                if (sum == k) {
                    occurences++;
                    end++;
                    
                } else {
                    end++;
                }
            } else if (sum > k) {
                sum -= arr[start];
                start++;
            }
        }
        
        return occurences;
    }


int main() {

    
    // int n; cin >> n;
    // int k; cin >> k;
    // vector<int> arr(n);
    // for(int i = 0; i<n; i++) {
    //     cin >> arr[i];
    // }
    int n = 3, k = 2;
    vector<int> arr(n, 1);

    cout << subarraySum(arr, k) << endl;



    return 0;
}