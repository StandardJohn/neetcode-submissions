class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j : coins) {
                if (i - j >= 0) 
                    dp[i] = min(dp[i], dp[i - j] + 1);
            }
        }
        // for (int i : dp)
        //     cout << i << endl;
        return dp[amount] <= amount ? dp[amount] : -1;
    }
};
