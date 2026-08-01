class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        vector<int> ans;
        vector<vector<int>> buckets(nums.size() + 1);
        for (int i = 0; i < nums.size(); i++) {
            umap[nums[i]]++;
        }
        for (auto it = umap.begin(); it != umap.end(); ++it) {
            // cout << it->second << endl;
            buckets[it->second].push_back(it->first);
        }
        for (int i = buckets.size() - 1; i >= 0; i--) {
            for (int j = 0; j < buckets[i].size(); j++) {
                // cout << buckets[i][j] << endl;
                ans.push_back(buckets[i][j]);
                if (!--k)
                    return ans;
            }
        }
        return ans;
    }
};
