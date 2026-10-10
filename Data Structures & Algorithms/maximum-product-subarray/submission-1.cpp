class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct = nums[0], minProduct = nums[0], n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        for (int i = 1; i < n; i++) {
            int p1 = maxProduct * nums[i], p2 = minProduct * nums[i];
            maxProduct = max({p1, p2, nums[i]});
            minProduct = min({p1, p2, nums[i]});
            dp[i] = max(dp[i - 1], maxProduct);
            // cout << maxProduct << " " << minProduct << endl;
        }
        return dp[n - 1];
    }
};
