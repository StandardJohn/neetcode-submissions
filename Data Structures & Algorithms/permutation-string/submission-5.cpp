class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;
        vector<int> cnt1(26, 0), cnt2(26, 0);
        int match = 26;
        for (int i = 0; i < s1.size(); i++) {
            cnt1[s1[i] - 'a']++;
            cnt2[s2[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (cnt1[i] != cnt2[i])
                match--;
        }
        for (int i = 0, j = s1.size(); j < s2.size(); i++, j++) {
            if (match == 26)
                return true;
            cnt2[s2[j] - 'a']++;
            if (cnt1[s2[j] - 'a'] == cnt2[s2[j] - 'a'])
                match++;
            else if (cnt1[s2[j] - 'a'] + 1 == cnt2[s2[j] - 'a'])
                match--;
            
            cnt2[s2[i] - 'a']--;
            if (cnt1[s2[i] - 'a'] == cnt2[s2[i] - 'a'])
                match++;
            else if (cnt1[s2[i] - 'a'] - 1 == cnt2[s2[i] - 'a'])
                match--;
        }
        return match == 26;
    }
};
