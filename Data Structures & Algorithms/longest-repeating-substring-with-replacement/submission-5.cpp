class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> cnt(100, 0);
        int i = 0, j = 1, maxChar = 1, t = k;
        char freqCh = s[0];
        cnt[s[0]]++;
        for ( ; j < s.size(); j++) {
            cnt[s[j]]++;
            // cout << i << " " << j  << " " << cnt[s[j]] << endl;
            // cout << i << " " << j << ": " << s[j] << " = " << cnt[s[j]] << " " << char(freqCh) << " = " << cnt[freqCh] << endl;
            if (int(s[j]) != freqCh) {
                if (cnt[s[j]] > cnt[freqCh]) {
                    freqCh = s[j];
                }

            }
            if (j - i + 1 - cnt[freqCh] > k) {
                cnt[s[i]]--;
                k == 0 ? i = j : i++;
            }
            maxChar = max(maxChar, j - i + 1);
        }
        // maxChar = max(maxChar, j - i);
        return maxChar;
    }
};
