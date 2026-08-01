class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        // value, index
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            auto it = umap.find(complement);
            if (it != umap.end()) {
                // ans.push_back(i);
                // ans.push_back(it->second);
                if (i < it->second)
                    return {i, it->second};
                return {it->second, i};
            }
            umap[nums[i]] = i;

        }   
        return ans;
    }
};
