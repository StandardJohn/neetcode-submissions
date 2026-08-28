class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        string state;
        dfs(state, 0, 0, n);
        return res;
    }
    void dfs(string& state, int a, int b, int n) {
        if (a == n && b == n) {
            res.push_back(state);
            return;
        }
        if (a < n) {
            state += '(';
            dfs(state, a + 1, b, n);
            state.pop_back();
        }
        if (b < a) {
            state += ')';
            dfs(state, a, b + 1, n);
            state.pop_back();
        }
    }
};

// aaabbb aababb aabbab abaabb ababab