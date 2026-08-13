class Solution {
public:
    int search(vector<int>& nums, int target) {
        // int idx;
        int l = 0, r = nums.size() - 1, m = 0;
        while (l <= r) {
            m = l + (r - l) / 2;
            if (m + 1 == nums.size() || nums[l] < nums[r]) {
                l = 0;
                r = nums.size() - 1;
                break;
            }
            else if (nums[m] > nums[m + 1]) {
                if (target > nums.back()) {
                    l = 0;
                    r = m;
                }
                else {
                    l = m + 1;
                    r = nums.size() - 1;
                }
                break;
            }
            else if (nums[m] > nums[l])
                l = m + 1;
            else 
                r = m;
        }
        // cout << l << " " << r << endl;
        while (l <= r) {
            m = l + (r - l) / 2;
            if (nums[m] == target)
                return m;
            else if (nums[m] < target)
                l = m + 1;
            else
                r = m - 1;
        }
        return -1;
    }
};
