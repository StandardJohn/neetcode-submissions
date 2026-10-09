class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            int c = INT_MAX;
            for (int j : coins) {
                if (j <= amount && i - j >= 0 && dp[i - j] >= 0)
                    c = min(c, dp[i - j] + 1);
                if (c == 1)
                    break;
            }
            dp[i] = c != INT_MAX ? c : -1;
        }
        // for (int i : dp)
        //     cout << i << endl;
        return dp[amount];
    }
};
