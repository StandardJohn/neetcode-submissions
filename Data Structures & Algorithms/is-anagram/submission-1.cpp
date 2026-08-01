class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> um_s, um_t;
        for (int i = 0; i < s.size(); i++) 
            um_s[s[i]]++;
        for (int i = 0; i < t.size(); i++)
            um_t[t[i]]++;
        return (um_s == um_t);
    }
};
