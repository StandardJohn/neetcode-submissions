class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> uset;
        for (int i : nums) {
            if (uset.find(i) != uset.end())
                return i;
            uset.insert(i);
        }
        return 0;
    }
};
