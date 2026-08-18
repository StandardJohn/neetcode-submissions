class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> state;
        vector<bool> visited(n, 0);
        dfs(nums, state, visited, n);
        return res;
    }
    void dfs(vector<int>& nums, vector<int> state, vector<bool>& visited, int n) {
        if (state.size() == n) {
            res.push_back(state);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (visited[i])
                continue;
            state.push_back(nums[i]);
            visited[i] = true;
            dfs(nums, state, visited, n);
            state.pop_back();
            visited[i] = false;
        }
    }
};
