class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());

        int ans = 0;
        int n = coins.size();

        for (int i = n-1; i >= 0; i--) {
            int noOfCoinsTaken = amount/coins[i];
            amount -= noOfCoinsTaken*coins[i];
            ans += noOfCoinsTaken;
        }
        if (amount != 0) {
            return -1;
        }

        return ans;
    }
};