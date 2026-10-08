class Solution {
public:
    int cnt(char& a, char& b) {
        if (a == '0') 
            return 0;
        int c = (a - '0') * 10 + b - '0';
        if (c <= 26) {
            // if (c % 10 == 0)
            //     return 1;
            return 1;
        }
        return 0;
    }
    int numDecodings(string s) {
        int n = s.size();
        if (s[0] == '0')
            return 0;
        if (n == 1) 
            return 1;
        vector<int> dp(n, 0);
        dp[0] = 1;
        if (cnt(s[0], s[1]) == 0 && s[1] == '0')
            return 0;
        if (cnt(s[0], s[1]) == 0 || s[1] == '0')
            dp[1] = 1;
        else
            dp[1] = 2;
        
        for (int i = 2; i < n; i++) {
            if ((s[i] == '0' && s[i - 1] == '0') || (s[i] == '0' && cnt(s[i - 1], s[i]) == 0))
                return 0;
            if (s[i] == '0') 
                dp[i] = dp[i - 2];
            else
                dp[i] = dp[i - 1] + cnt(s[i - 1], s[i]) * dp[i - 2];
            // cout << dp[i] << endl;
        }
        for (int i : dp) 
            cout << i << endl;
        return dp[n - 1];

    }
};
