#include "header.h"

class Solution {
public:
    bool canPlaceCows(vector<int> &stalls, int n, int cows, int dist) {
        int coord = stalls[0];
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (stalls[i] - coord >= dist) {
                cnt++;
                coord = stalls[i];
            }
            
            if (cnt == cows) {
                return true;
            }
        }
        return false;
    }


    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(), stalls.end());
        int low = 1;
        int high = stalls[n-1] - stalls[0];
        
        int ans = high;
        while(low <= high) {
            int mid = (low + high)/2;
            if (canPlaceCows(stalls, n, k, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};