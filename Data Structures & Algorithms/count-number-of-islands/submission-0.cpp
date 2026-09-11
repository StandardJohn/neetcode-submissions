class Solution {
public:
    vector<int> dx {1, -1, 0, 0}, dy {0, 0, 1, -1};
    void dfs(vector<vector<char>>& g, int y, int x) {
        if (y < 0 || y >= g.size() || x < 0 || x >= g[0].size() || g[y][x] == '0')
            return;
        g[y][x] = '0';
        for (int i = 0; i < 4; i++) {
            dfs(g, y + dy[i], x + dx[i]);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    n++;
                    dfs(grid, i, j);
                }
            }
        }
        return n;
    }
};
