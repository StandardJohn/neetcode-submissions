class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>>row(9), col(9), sub(9);
        // int n = board.size(), m = board[0].size();
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                // cout << c << " ";
                if (c == '.')
                    continue;
                if (row[i].find(c) != row[i].end())
                    return false;
                row[i].insert(c);
                if (col[j].find(c) != col[j].end())
                    return false;
                col[j].insert(c);
                int k = i / 3 * 3 + j / 3;
                // cout << k << endl;
                if (sub[k].find(c) != sub[k].end())
                    return false;
                sub[k].insert(c);
            }
            // cout << endl;
        }
        return true;
    }
};
