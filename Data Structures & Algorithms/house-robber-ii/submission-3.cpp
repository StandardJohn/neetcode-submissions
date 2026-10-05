class Solution {
public:
    int rob(vector<int>& nums) {
        // bool flag = false;
        int n = nums.size();
        if (n <= 3) {
            int m = 0;
            for (int i = 0; i < n; i++) {
                m = max(m, nums[i]);
            }
            return m;
        }
        vector<vector<int>> dp(2, vector<int>(n, 0));
        dp[0][0] = nums[0];
        dp[0][1] = max(nums[0], nums[1]);
        dp[1][1] = nums[1];
        dp[1][2] = max(nums[1], nums[2]);
        for (int i = 2; i < n - 1; i++) {
            dp[0][i] = max(dp[0][i - 2] + nums[i], dp[0][i - 1]);
        }
        for (int i = 3; i < n; i++) {
            dp[1][i] = max(dp[1][i - 2] + nums[i], dp[1][i - 1]);
        }
        // for (vector<int> i : dp) {
        //     for (int j : i) {
        //         cout << j << " ";
        //     }
        //     cout << endl;
        // }
        return max(dp[0][n - 2], dp[1][n - 1]);
    }
};
