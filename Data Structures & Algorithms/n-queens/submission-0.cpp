class Solution {
public:
    vector<vector<string>> res;
    vector<int> dx = {0, 1, 1, 1, 0, -1, -1, -1}, dy = {-1, -1, 0, 1, 1, 1, 0, -1};
    void update_visited(vector<vector<int>>& visited, int y, int x, int n, int flag) {
        for (int i = 0; i < 8; i++) {
            int j = y, k = x;
            // cout << j << " " << k << endl;
            while (j >= 0 && j < n && k >= 0 && k < n) {
                visited[j][k] += flag;
                j += dy[i];
                k += dx[i];
            }
        }
    }
    void dfs(vector<string>& state, vector<vector<int>>& visited, int y, int x, int n) {
        if (y == n) {
            res.push_back(state);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (visited[y][i] > 0) {
                continue;
            }
            // for (int j = 0; j < n; j++) {
            //     for (int k = 0; k < n; k++) {
            //         cout << visited[j][k];
            //     }
            //     cout << endl;
            // }
            // cout << endl;
            state[y][i] = 'Q';
            update_visited(visited, y, i, n, 1);
            dfs(state, visited, y + 1, 0, n);
            state[y][i] = '.';
            update_visited(visited, y, i, n, -1);
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> visited(n, vector<int>(n, 0));
        vector<string> state(n, string(n, '.'));
        dfs(state, visited, 0, 0, n);
        return res;
    }
};
