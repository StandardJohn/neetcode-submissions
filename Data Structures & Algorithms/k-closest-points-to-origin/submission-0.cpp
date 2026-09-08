class Solution {
public:
    struct c {
        bool operator() (const vector<int> &a, const vector<int> &b) {
            return (double) sqrt(a[0] * a[0] + a[1] * a[1]) < (double) sqrt(b[0] * b[0] + b[1] * b[1]);
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<vector<int>, vector<vector<int>>, c> pq;
        for (int i = 0; i < points.size(); i++) {
            if (pq.size() < k) {
                // pair<int, int> p = {points[i][0], points[i][1]};
                pq.push(points[i]);
                continue;
            }
            const vector<int> &p1 = points[i], &p2 = pq.top();
            double d1 = sqrt(p1[0] * p1[0] + p1[1] * p1[1]), d2 = sqrt(p2[0] * p2[0] + p2[1] * p2[1]);
            if (d1 < d2) {
                pq.pop();
                pq.push(points[i]);
            }
        }
        while (!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};
