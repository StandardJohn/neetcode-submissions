class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int p = 1, cnt0 = 0, n = nums.size();
        vector<int> prefix(n, 1), suffix(n, 1);
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
            suffix[n - i - 1] = suffix[n - i] * nums[n - i];
        }
        for (int i = 0; i < n; i++) 
            nums[i] = prefix[i] * suffix[i];
            // cout << prefix[i] << " " << suffix[i] << endl;
        return nums;
    }
};
