class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> umap;

    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        auto it = umap.find(key);
        if (it != umap.end()) {
            it->second.push_back({timestamp, value});
        }
        else {
            vector<pair<int, string>> v = {{timestamp, value}};
            umap.insert({key, v});
        }
    }
    
    string get(string key, int timestamp) {
        auto it = umap.find(key);
        if (it == umap.end())
            return "";
        vector<pair<int, string>>& v = it->second;
        int l = 0, r = v.size() - 1, res = -1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (v[m].first <= timestamp) {
                res = m;
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        return res < 0 ? "" : v[res].second;
    }
};
