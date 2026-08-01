class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> um_s, um_t;
        int s_size = s.size(), t_size = t.size();
        for (int i = 0; i < s_size; i++) 
            um_s[s[i]]++;
        for (int i = 0; i < t_size; i++)
            um_t[t[i]]++;
        return (um_s == um_t);
    }
};
