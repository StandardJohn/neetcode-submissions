class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;
        vector<int> cnt(256, -1);
        int maxS = 1, maxLocal = 1;
        cnt[s[0]] = 0;
        for (int i = 0, j = 1; j < s.size(); j++) {
            if (cnt[s[j]] >= 0 && cnt[s[j]] >= i) {
                i = cnt[s[j]] + 1;
                // cout << j << ": " << s[j] << " " << cnt[s[j]] << endl;
                maxS = max(maxS, maxLocal);
                maxLocal = j - i + 1;
            }
            else {
                // cout << j << " new: " << s[j] << endl;
                maxLocal++;
            }
            cnt[s[j]] = j;
        }
        return max(maxS, maxLocal);
    }
};
