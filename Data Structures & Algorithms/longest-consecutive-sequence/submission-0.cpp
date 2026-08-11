class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uset, start;
        int ans = 0;
        for (int i : nums) {
            uset.insert(i);
            // else
        }
        for (auto it = uset.begin(); it != uset.end(); ++it) {
            auto s = uset.find(*it - 1);
            if (s != uset.end())
                continue;
            start.insert(*it);
        }
        for (auto it = start.begin(); it != start.end(); ++it) {
            // cout << *it << endl;
            int cnt = 1, i = *it + 1;
            auto next = uset.find(i);
            while (next != uset.end()) {
                cnt++;
                i++;
                next = uset.find(i);
            }
            ans = max(ans, cnt);
        }
        // for (int )
        return ans;
    }
};
