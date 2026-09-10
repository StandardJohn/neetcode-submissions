class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> umap;
        priority_queue<int> pq;
        queue<pair<int, int>> q;
        int time = 0;
        for (char c : tasks) {
            umap[c]++;
        }
        for (auto it = umap.begin(); it != umap.end(); ++it) {
            pq.push(it->second);
        }
        while (!pq.empty() || !q.empty()) {
            time++;
            if (!pq.empty()) {
                int t = pq.top();
                pq.pop();
                t--;
                if (t > 0) {
                    q.push({t, time + n});
                }
            }
            if (!q.empty() && q.front().second <= time) {
                pq.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
