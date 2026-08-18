class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums, 0);
        return res;
    }
    void dfs(vector<int>& nums, int n) {
        if (nums.size() == n) {
            res.push_back(nums);
            return;
        }
        for (int i = n; i < nums.size(); i++) {
            swap(nums[i], nums[n]);
            dfs(nums, n + 1);
            swap(nums[i], nums[n]);
        }
    }
};
