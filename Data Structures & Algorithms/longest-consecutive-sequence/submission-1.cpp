class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uset, start;
        int ans = 0;
        for (int i : nums) {
            uset.insert(i);
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
            for (auto next = uset.find(i); next != uset.end(); next = uset.find(++i)) {
                cnt++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
