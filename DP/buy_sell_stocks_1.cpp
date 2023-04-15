class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int minVal = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] >= minVal) {
                ans = max(ans, prices[i] - minVal);
            } else {
                minVal = prices[i];
            }
            // for (int j = 0; j < i; j++) {
            //     int diff = prices[i] - prices[j];
            //     ans = max(ans, diff);
            // }
        }
        return ans;
    }
};