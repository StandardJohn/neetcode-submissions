class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        while(!q.empty()) {
            pair<int, int> t = q.front();
            int &v = grid[t.first][t.second];
            for (int i = 0; i < 4; i++) {
                int y = t.first + dy[i],
                    x = t.second + dx[i];
                if (y < 0 || y >= n || x < 0 || x >= m || grid[y][x] != INT_MAX) {
                    continue;
                }
                grid[y][x] = v + 1;
                q.push({y, x});
            }
            q.pop();
        }
    }
};
