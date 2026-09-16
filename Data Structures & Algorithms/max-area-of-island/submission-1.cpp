class Solution {
public:
    vector<int> dx {1, -1, 0, 0}, dy {0, 0, 1, -1};
    void dfs(vector<vector<int>>& g, int y, int x, int &a) {
        if (y < 0 || y >= g.size() || x < 0 || x >= g[0].size() || g[y][x] == 0)
            return;
        g[y][x] = 0;
        a++;
        for (int i = 0; i < 4; i++) {
            dfs(g, y + dy[i], x + dx[i], a);
        }
        // return a;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    int area = 0;
                    dfs(grid, i, j, area);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};
