class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size())
            return "";
        vector<int> cnt_s(125, 0), cnt_t(125, 0);
        int l = -1, r = 0, distinct = 0, n = t.size();
        for (int i = 0; i < n; i++) {
            cnt_t[t[i]]++;
        }
        for (int i = 0, j = 0; j < s.size(); j++) {
            if (cnt_s[s[j]] < cnt_t[s[j]]) {
                distinct++;
            }
            // cout << i << " " << j << ": " << distinct << endl;
            cnt_s[s[j]]++;
            while(distinct == n) {
                if ((j - i) < (r - l) || (l < 0)) {
                    // cout << l << " " << r << " -> " << i << " " << j << endl;
                    l = i;
                    r = j;
                }
                cnt_s[s[i]]--;
                if (cnt_s[s[i]] < cnt_t[s[i]]) {
                    distinct--;
                }
                i++;
            }
        }
        return l < 0 ? "" : s.substr(l, r - l + 1);
    }
};
