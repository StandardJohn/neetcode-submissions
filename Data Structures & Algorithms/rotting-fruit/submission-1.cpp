class Solution {
public:
    vector<int>dx {1, -1, 0, 0}, dy {0, 0, 1, -1};
    int orangesRotting(vector<vector<int>>& grid) {
        int minTime = 0, n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } 
            }
        }

        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int y = p.second + dy[i], 
                    x = p.first + dx[i];
                if (y < 0 || y >= n || x < 0 || x >= m || grid[y][x] != 1) {
                    continue;
                }
                grid[y][x] = grid[p.first][p.second] + 1;
                q.push({y, x});
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                } 
                minTime = max(minTime, grid[i][j] - 2);
            }
        }
        return minTime;
    }
};
