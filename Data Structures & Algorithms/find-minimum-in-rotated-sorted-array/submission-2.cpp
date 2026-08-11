class Solution {
public:
    int findMin(vector<int> &nums) {
        // if (nums.size() == 1)
        //     return nums[0];
        int l = 0, r = nums.size() - 1;
        while(l <= r) {
            int m = l + (r - l) / 2;
            cout << nums[m] << endl;
            if (m + 1 == nums.size())
                break;
            if (nums[m + 1] < nums[m]) {
                return nums[m + 1];
            }
            else if (nums[m] > nums[l]) {
                l = m + 1;
            }
            else if (nums[m] < nums[r]){
                r = m;
            }
            else
                break;
        }
        return nums[0];
    }
};
