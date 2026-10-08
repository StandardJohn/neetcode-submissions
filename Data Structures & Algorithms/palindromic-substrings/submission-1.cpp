class Solution {
public:
    int countSubstrings(string s) {
        int cnt = 0, n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, 0));
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
