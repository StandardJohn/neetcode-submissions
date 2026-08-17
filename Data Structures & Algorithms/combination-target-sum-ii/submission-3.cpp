class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        // for (int i : candidates)
        //     cout << i << " ";
        // cout << endl;
        vector<int> state, next(candidates.size(), candidates.size());
        vector<vector<int>> res;
        for (int i = candidates.size() - 2, j = candidates.size(); i >= 0; i--) {
            if (candidates[i + 1] != candidates[i])
                j = i + 1;
            next[i] = j;
        }
        // for (int i : next)
        //     cout << i << " ";
        // cout << endl;
        dfs(state, candidates, res, 0, target, 0, next);
        return res;
    }
    void dfs(vector<int> state, vector<int>& candidates, vector<vector<int>>& res, int sum, const int target, int idx, vector<int>& next) {
        if (sum == target) {
            // for (int i : state)
            //     cout << i << " ";
            // cout << endl;
            res.push_back(state);
            return;
        }
        for (int i = idx; i < candidates.size(); i = next[i]) {
            state.push_back(candidates[i]);
            if (sum + candidates[i] > target)
                return;
            dfs(state, candidates, res, sum + candidates[i], target, i + 1, next);
            state.pop_back();
        }
    }
};
