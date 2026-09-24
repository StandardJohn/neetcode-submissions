class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, int> umap;
        for (string &s : strs) {
            string t = s;
            sort(t.begin(), t.end());
            auto it = umap.find(t);
            if (it != umap.end()) {
                res[it->second].push_back(s);
            }
            else {
                umap.insert({t, res.size()});
                res.push_back({s});
            }
        }

        return res;
    }
};
