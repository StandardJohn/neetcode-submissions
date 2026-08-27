class Solution {
public:
    vector<vector<int>> res;
    vector<int> state;
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(state, nums, 0);
        return res;
    }
    void dfs(vector<int>& state, vector<int>& nums, int i) {
        if (i == nums.size()) {
            res.push_back(state);
            return;
        }
        state.push_back(nums[i]);
        dfs(state, nums, i + 1);
        state.pop_back();
        dfs(state, nums, i + 1);
    }
};
