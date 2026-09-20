class Solution {
public:
    struct PairHash {
        std::size_t operator()(const std::pair<int, int>& p) const {
            auto h1 = std::hash<int>{}(p.first);
            auto h2 = std::hash<int>{}(p.second);
            return h1 ^ (h2 << 1); 
        }
    };
    unordered_set<pair<int, int>, PairHash> pac, atl;
    vector<int> dx {1, -1, 0, 0}, dy {0, 0, 1, -1};
    
    int n, m;
    void dfs(int y, int x, vector<vector<int>>& heights, unordered_set<pair<int, int>, PairHash>& visited, int prev) {
        if (y < 0 || y >= n || x < 0 || x >= m || visited.find({y, x}) != visited.end() || heights[y][x] < prev)
            return;

        visited.insert({y, x});
        for (int i = 0; i < 4; i++) {
            dfs(y + dy[i], x + dx[i], heights, visited, heights[y][x]);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size(), m = heights[0].size();
        vector<vector<int>> res;
        for (int i = 0; i < n; i++) {
            dfs(i, 0, heights, pac, 0);
            dfs(i, m - 1, heights, atl, 0);
        }
        for (int i = 0; i < m; i++) {
            dfs(0, i, heights, pac, 0);
            dfs(n - 1, i, heights, atl, 0);
        }
        for (auto it = pac.begin(); it != pac.end(); ++it) {
            if (atl.find(*it) != atl.end()) {
                res.push_back({});
                res.back().push_back(it->first);
                res.back().push_back(it->second);
            }
        }
        return res;
    }
};
