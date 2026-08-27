class Solution {
public:
    struct c {
        bool operator() (const pair<int, int> a, const pair<int, int> b) const{
            return a.first < b.first;
        }
    };
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, c> pq;
        vector<int> res;
        for (int i = 0; i < k; i++) {
            pq.push({nums[i], i});
        }
        res.push_back(pq.top().first);
        for (int i = 1, j = k; j < nums.size(); i++, j++) {
            while (!pq.empty() && pq.top().second < i) {
                pq.pop();
            }
            pq.push({nums[j], j});
            res.push_back(pq.top().first);
        }
        return res;
    }
};
