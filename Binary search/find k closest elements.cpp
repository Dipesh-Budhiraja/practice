using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int l = 0;
        int r = n - k;


        while(l <= r) {
            int m = (l + r)/2;

            if (m+k == n) {
                break;
            }
            if (
                (abs(x - arr[m+k]) < abs(x - arr[m])) 
                || (arr[m] == arr[m+k] && arr[m] < x)
            ) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        vector<int> ans;
        for (int i = l; i < l + k; i++) {
            ans.push_back(arr[i]);
        }
        return ans;
    }
};