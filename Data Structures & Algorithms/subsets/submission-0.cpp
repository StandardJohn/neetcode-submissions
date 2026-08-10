class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back({});
        dfs(res, nums, 0);
        return res;
    }
    void dfs(vector<vector<int>>& res, vector<int>& nums, int i) {
        if (i >= nums.size())
            return;
        vector<int> back = res.back();
        for ( ; i < nums.size(); i++) {
            back.push_back(nums[i]);
            res.push_back(back);
            back.pop_back();
            dfs(res, nums, i + 1);
        }
    }
};
