class Solution {
public:
    string longestPalindrome(string s) {
        int maxL = 0, maxR = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            for (int l = i - 1, r = i + 1; l >= 0 && r < n; l--, r++) {
                if (s[l] == s[r]) {
                    if (r - l > maxR - maxL) {
                        maxL = l;
                        maxR = r;
                    }
                }
                else 
                    break;
            }
            for (int l = i, r = i + 1; l >= 0 && r < n; l--, r++) {
                if (s[l] == s[r]) {
                    if (r - l > maxR - maxL) {
                        maxL = l;
                        maxR = r;
                    }
                }
                else 
                    break;
            }
        }
        return s.substr(maxL, maxR - maxL + 1);
    }
};
