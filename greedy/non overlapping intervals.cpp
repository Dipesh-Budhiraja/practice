#include "header.h"

class Solution {
public:
    static bool comp(vector<int> &i1, vector<int> &i2) {
        return i1[0] < i2[0];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        int res = 0;
        int prevEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= prevEnd) {
                prevEnd = intervals[i][1];
            } else {
                // overlap case
                res++;
                // remove the one that has farthest end
                prevEnd = min(prevEnd, intervals[i][1]);
            }
        }
        return res;
    }
};