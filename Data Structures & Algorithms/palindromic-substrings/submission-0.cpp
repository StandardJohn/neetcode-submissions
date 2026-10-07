class Solution {
public:
    int countSubstrings(string s) {
        int cnt = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            for (int l = i, r = i; l >= 0 && r < n; l--, r++) {
                if (s[l] == s[r])  
                    cnt++;
                else
                    break;
            }
            for (int l = i, r = i + 1; l >= 0 && r < n; l--, r++) {
                if (s[l] == s[r])  
                    cnt++;
                else
                    break;
            }
        }
        return cnt;
    }
};
