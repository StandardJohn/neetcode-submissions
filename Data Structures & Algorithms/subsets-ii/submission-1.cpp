class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        dfs({}, nums, 0, n);
        return res;
    }
    void dfs(vector<int> state, vector<int>& nums, int i, int n) {
        res.push_back(state);
        for (int j = i; j < n; j++) {
            if (j > i && nums[j] == nums[j - 1])
                continue;
            state.push_back(nums[j]);
            dfs(state, nums, j + 1, n);
            state.pop_back();
        }
    }
};
