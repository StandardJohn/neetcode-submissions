class Solution {
public:
    vector<vector<string>> res;
    void dfs(vector<string>& state, vector<bool>& col, vector<bool>& diag1, vector<bool>& diag2, int y, int n) {
        if (y == n) {
            res.push_back(state);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (col[i] || diag1[y - i + n - 1] || diag2[y + i]) {
                continue;
            }
            state[y][i] = 'Q';
            col[i] = true;
            diag1[y - i + n - 1] = true;
            diag2[y + i] = true;
            dfs(state, col, diag1, diag2, y + 1, n);
            state[y][i] = '.';
            col[i] = false;
            diag1[y - i + n - 1] = false;
            diag2[y + i] = false;
            
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> state(n, string(n, '.'));
        vector<bool> col(n, 0), diag1(2 * n - 1, 0), diag2(2 * n - 1, 0);
        dfs(state, col, diag1, diag2, 0, n);
        return res;
    }
};
