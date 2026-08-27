class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> state;
        dfs(state, nums, 0, 0, target);
        return res;
    }
    void dfs(vector<int>& state, vector<int>& nums, int start, int sum, int target) {
        if (sum == target) {
            res.push_back(state);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            sum += nums[i];
            if (sum > target)
                return;
            state.push_back(nums[i]);
            dfs(state, nums, i, sum, target);
            sum -= nums[i];
            state.pop_back();
        }
    }
};
