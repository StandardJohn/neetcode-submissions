class Solution {
public:
    vector<pair<int, int>> start;
    bool flag = false;
    vector<int> dx {1, -1, 0, 0}, dy {0, 0, 1, -1};
    void firstCh(vector<vector<char>>& board, char c) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == c) {
                    start.push_back({i, j});
                }
            }
        }
    }
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int y, int x, int i, string& word) {
        if (y < 0 || y >= board.size() || x < 0 || x >= board[0].size() || board[y][x] != word[i] || visited[y][x]) {
            return;
        }
        if (i == word.size() - 1) {
            flag = true;
            return;
        }
        visited[y][x] = true;
        for (int j = 0; j < 4; j++) {
            dfs(board, visited, y + dy[j], x + dx[j], i + 1, word);
            if (flag) {
                return;
            }
        }
        visited[y][x] = false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        firstCh(board, word[0]);
        // for (auto i : start) {
        //     cout << i.first << " " << i.second << endl;
        // }
        for (pair<int, int> p : start) {
            dfs(board, visited, p.first, p.second, 0, word);
            if (flag)
                return true;
        }
        return false;
    }
};
