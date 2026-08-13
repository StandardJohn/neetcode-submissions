class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size(), fleet_cnt = 0;
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int i, int j){ return position[i] > position[j]; });
        stack<int> s;
        s.push(indices[0]);
        // for (int i = 0; i < n; i++)
        //     cout << position[indices[i]] << " " << speed[indices[i]] << endl;
        // cout << endl;            
        for (int i = 1; i < n; i++) {
            float t1 = (target - position[s.top()]) / double(speed[s.top()]),
                t2 = (target - position[indices[i]]) / double(speed[indices[i]]);
            if (t2 > t1) {
                // cout << position[indices[i]] << " " << speed[indices[i]] << " " << t1 << " " << t2 << endl;
                s.push(indices[i]);
            }
        }
        
        return s.size();
    }
};

// 21 19 18 12 6 5
// 25 25 24 19 10 10
// 29 29 29 26 14