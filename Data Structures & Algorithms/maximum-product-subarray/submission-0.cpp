class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct = nums[0], minProduct = nums[0], n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        for (int i = 1; i < n; i++) {
            int t1 = max({maxProduct * nums[i], minProduct * nums[i], nums[i]}),
                t2 = min({maxProduct * nums[i], minProduct * nums[i], nums[i]});
            maxProduct = t1;
            minProduct = t2;
            dp[i] = max(dp[i - 1], maxProduct);
            // cout << maxProduct << " " << minProduct << endl;
        }
        return dp[n - 1];
    }
};
