class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> state;
        sort(candidates.begin(), candidates.end());
        int n = candidates.size();
        vector<int> next(n);
        next[n - 1] = n;
        for (int i = n - 2; i >= 0; i--) {
            if (candidates[i] != candidates[i + 1])
                next[i] = i + 1;   
            else 
                next[i] = next[i + 1];
        }
        // for (int i : next) 
        //     cout << i << endl;
        //  for (int i = 0; i < n; ) {
            
        // }
        dfs(state, candidates, next, 0, 0, target);
        return res;
    }
    void dfs(vector<int>& state, vector<int>& nums, vector<int>& next, int start, int sum, int target) {
        if (sum == target) {
            res.push_back(state);
            return;
        }
        for (int i = start; i < nums.size(); i = next[i]) {
            cout << start << " " << i << endl;
            sum += nums[i];
            if (sum > target)
                return;
            state.push_back(nums[i]);
            dfs(state, nums, next, i + 1, sum, target);
            state.pop_back();
            sum -= nums[i];
        }
    }
};
