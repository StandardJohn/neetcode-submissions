class Solution {
public:
    bool check(string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    vector<vector<string>> res;
    void dfs(vector<string>& state, string& s, int start) {
        if (start == s.size()) {
            return;
        }
        if (check(s, start, s.size() - 1)) {
            state.push_back(s.substr(start, s.size() - start));
            res.push_back(state);
            state.pop_back();
        }
        for (int i = start + 1; i <= s.size(); i++) {
            if (check(s, start, i - 1)) {
                state.push_back(s.substr(start, i - start));
                dfs(state, s, i);
                state.pop_back();

            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> state;
        dfs(state, s, 0);
        return res;
    }
};
