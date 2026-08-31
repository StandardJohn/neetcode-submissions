class Solution {
public:
    vector<string> res;
    string state;
    unordered_map<char, string> umap;
    void init_digits() {
        umap.insert({'2', "abc"});
        umap.insert({'3', "def"});
        umap.insert({'4', "ghi"});
        umap.insert({'5', "jkl"});
        umap.insert({'6', "mno"});
        umap.insert({'7', "pqrs"});
        umap.insert({'8', "tuv"});
        umap.insert({'9', "wxyz"});
    }
    void dfs(string& state, string& digits, int digit, int ch) {
        if (state.size() == digits.size()) {
            if (!state.empty())
                res.push_back(state);
            return;
        }
        // if (digit == digits.size())
        //     return;
        auto it = umap.find(digits[digit]);
        string& s = it->second;
        // cout << it->first << " " << s << " " << state << endl;
        for (int i = ch; i < s.size(); i++) {
            state.push_back(s[i]);
            dfs(state, digits, digit + 1, 0);
            state.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        init_digits();
        dfs(state, digits, 0, 0);
        auto it = umap.find(digits[0]);
        return res;
    }
};
