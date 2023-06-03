#include "header.h"

class Solution {
public:
    static bool comp(vector<int> &i1, vector<int> &i2) {
        return i1[0] < i2[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sort
        sort(intervals.begin(), intervals.end(), comp);

        vector<vector<int>> res;
        int n = intervals.size();
        for (int i = 0; i < n - 1; i++) {
            vector<int> i1 = intervals[i];
            vector<int> i2 = intervals[i+1];

            if (i1[1] >= i2[0]) {
                // merge
                i2[0] = min(i1[0], i2[0]);
                i2[1] = max(i1[1], i2[1]);
                intervals[i+1].clear();
                intervals[i+1] = i2;
            } else {
                res.push_back(i1);
            }
        }
        // for (int i = 0; i < n; i++) {
        //     cout << intervals[i][0] << " " << intervals[i][1] << endl;
        // }
        res.push_back(intervals[n-1]);
        return res;
    }
};