class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (int i : coins) {
            if (i <= amount)
                dp[i] = 1;
        }
        for (int i = 2; i <= amount; i++) {
            if (dp[i] > 0)
                continue;
            int c = INT_MAX;
            for (int j = i - 1; j >= i / 2; j--) {
                if (dp[j] > 0 && dp[i - j] > 0)
                    c = min(c, dp[j] + dp[i - j]);
                if (c == 2)
                    break;
            }
            if (c != INT_MAX)
                dp[i] = c;
        }
        // for (int i : dp)
        //     cout << i << endl;
        return dp[amount];
    }
};
