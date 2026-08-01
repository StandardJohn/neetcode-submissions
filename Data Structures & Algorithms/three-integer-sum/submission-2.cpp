class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                int s = nums[j] + nums[k];
                if (s == -nums[i]) {
                    // cout << nums[i] << " " << nums[j] << " " << nums[k] << " " << s << endl;
                    vector<int> t = {nums[i], nums[j], nums[k]};
                    if (ans.size() == 0 || t != ans.back()) 
                        ans.push_back({nums[i], nums[j], nums[k]});                    
                    j++;
                }
                else if (s < -nums[i])
                    j++;
                else
                    k--;
            }
        }
        return ans;
    }
};
