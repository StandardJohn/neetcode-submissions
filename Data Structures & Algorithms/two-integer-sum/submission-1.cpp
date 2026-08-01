class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        // value, index
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i++) {
            umap.insert({nums[i], i});
        }
        for (int i = 0; i < nums.size(); i++) {
            ans.push_back(i);
            auto it = umap.find(target - nums[i]);
            if (it != umap.end() && it->second != i) {
                ans.push_back(it->second);
                if (ans[1] < ans[0])
                    swap(ans[0], ans[1]);
                return ans;
            }
            ans.pop_back();
        }
    }
};
