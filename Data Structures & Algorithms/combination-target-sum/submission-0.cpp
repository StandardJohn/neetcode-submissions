class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> state;
        vector<vector<int>> res;
        dfs(state, nums, res, 0, target, 0);
        return res;
    }
    void dfs(vector<int> state, vector<int>& nums, vector<vector<int>>& res, int sum, const int target, int idx) {
        if (sum == target) {
            res.push_back(state);
            return;
        }
        for (int i = idx; i < nums.size(); i++) {
            state.push_back(nums[i]);
            if (sum + nums[i] > target)
                return;
            dfs(state, nums, res, sum + nums[i], target, i);
            state.pop_back();
        }
    }
};
