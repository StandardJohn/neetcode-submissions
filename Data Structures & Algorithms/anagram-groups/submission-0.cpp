class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, int> umap;
        int n = 0;
        for (int i = 0; i < strs.size(); i++) {
            string s = strs[i];
            string t = s;
            sort(t.begin(), t.end(), less<char>());
            auto it = umap.find(t);
            if (it != umap.end()) {
                // cout << it->second << endl;
                ans[it->second].push_back(s);
            }
            else {
                ans.push_back({s});
                umap.insert({t, n++});
            }
        }
        return ans;
    }
};
