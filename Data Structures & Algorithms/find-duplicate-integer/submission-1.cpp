class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        bitset<10002> b1;
        for (int i : nums) {
            if (b1[i])
                return i;
            b1[i] = 1;
        }
        return 0;
    }
};
