class Solution {
    int a = INT_MAX;
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, 1e9);

        dp[0] = 0;

        for (int i=1; i<=amount; i++) {
            for (auto coin:coins) {
                if (i - coin >= 0) {
                    dp[i] = std::min(dp[i], dp[i-coin] + 1);
                }
            }
        }

        return (dp[amount] == 1e9) ? -1 : dp[amount];
    }
};
