class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = 0, slow = 0, slow2 = 0;
        while (1) {
            fast = nums[nums[fast]];
            slow = nums[slow];
            if (fast == slow)
                break;
        }
        while(1) {
            slow = nums[slow];
            slow2 = nums[slow2];
            if (slow == slow2)
                return slow;
        }
    }
};
