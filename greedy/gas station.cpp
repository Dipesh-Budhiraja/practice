#include "header.h"
#include <numeric>

class Solution {
public:

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        if (accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0)) {
            return -1;
        }
        int balance = 0;
        int start = 0; // considering 0th index as a solution
        for (int i = 0; i < n; i++) {
            balance += gas[i] - cost[i];
            if (balance < 0) {
                balance = 0;
                start = i+1;
            }
        }
        return start;
    }
};