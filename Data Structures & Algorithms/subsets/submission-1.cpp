class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        dfs(res, nums, 0, subset);
        return res;
    }
    void dfs(vector<vector<int>>& res, vector<int>& nums, int i, vector<int>& subset) {
        if (i >= nums.size()) {
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        dfs(res, nums, i + 1, subset);
        subset.pop_back();
        dfs(res, nums, i + 1, subset);
    }
};
