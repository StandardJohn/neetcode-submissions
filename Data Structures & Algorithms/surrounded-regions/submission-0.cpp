class Solution {
public:
    vector<int> dx {1, -1, 0, 0}, dy {0, 0, 1, -1};
    void dfs(vector<vector<char>>& b, vector<vector<bool>>& visited, int y, int x) {
        if (y < 0 || y >= b.size() || x < 0 || x >= b[0].size() || visited[y][x] || b[y][x] != 'O')
            return;
        visited[y][x] = true;
        for (int i = 0; i < 4; i++) {
            dfs(b, visited, y + dy[i], x + dx[i]);
        }
    }
    void solve(vector<vector<char>>& board) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), 0));
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++) {
            dfs(board, visited, i, 0);
            dfs(board, visited, i, m - 1);
        }
        for (int i = 0; i < m; i++) {
            dfs(board, visited, 0, i);
            dfs(board, visited, n - 1, i);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
